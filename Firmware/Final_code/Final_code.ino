#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// --- WiFi & MQTT Config ---
const char* ssid = "Nokia 5.4";
const char* password = "987654321";

const char* mqtt_server = "10.126.26.107"; // Telegraf server IP
const int mqtt_port = 1883;
const char* mqtt_topic = "esp32/data";

const char* device_id = "001";

WiFiClient espClient;
PubSubClient client(espClient);

// --- Pins ---
// Inputs
const int pinA = 35; // Current transformer (CT)
const int pinB = 32; 
const int pinC = 34;
const int pinD = 33;

// LED indicators
const int ledA = 4;
const int ledB = 5;
const int ledC = 18;
const int ledD = 19;

// Relay and button
const int relayPin = 25;
const int buttonPin = 13;

// --- Variables ---
int lastA = -1, lastB = -1, lastC = -1, lastD = -1;
bool relayState = false;
unsigned long lastDebounce = 0;
const int debounceDelay = 300; // button debounce in ms

// --- Software filtering for normal digital signals ---
int readStable(int pin, int samples = 5, int delayMs = 2) {
  int sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += !digitalRead(pin); // invert because PC817 logic
    delay(delayMs);
  }
  return (sum >= (samples / 2 + 1)) ? 1 : 0;
}

// --- Stable current detection for CT ---
int readCurrent(int pin, int windowMs = 20, int intervalMs = 1, float threshold = 0.3) {
    int highCount = 0;
    int totalSamples = windowMs / intervalMs;

    for (int i = 0; i < totalSamples; i++) {
        highCount += !digitalRead(pin); // invert PC817
        delay(intervalMs);
    }

    return ((float)highCount / totalSamples >= threshold) ? 1 : 0;
}

// --- WiFi and MQTT ---
void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected: " + WiFi.localIP().toString());
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(device_id)) {
      Serial.println("MQTT connected");
    } else {
      delay(2000);
    }
  }
}

// --- Send MQTT JSON ---
void sendJson(int a, int b, int c, int d, bool relay) {
  StaticJsonDocument<200> doc;
  doc["i"] = device_id;
  doc["a"] = a;
  doc["b"] = b;
  doc["c"] = c;
  doc["d"] = d;
  doc["r"] = relay ? 1 : 0;

  char buffer[256];
  size_t n = serializeJson(doc, buffer);
  client.publish(mqtt_topic, buffer, n);
  Serial.println(buffer);
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);

  // Input pins
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);

  // LED pins
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);

  // Relay & button
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(relayPin, relayState);

  // Read initial values
  lastA = readCurrent(pinA);
  lastB = readStable(pinB);
  lastC = readStable(pinC);
  lastD = readStable(pinD);

  sendJson(lastA, lastB, lastC, lastD, relayState);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  // --- Read inputs ---
  int a = readCurrent(pinA);   // CT input
  int b = readStable(pinB);    // normal digital
  int c = readStable(pinC);
  int d = readStable(pinD);

  // --- Update LEDs ---
  digitalWrite(ledA, a);
  digitalWrite(ledB, b);
  digitalWrite(ledC, c);
  digitalWrite(ledD, d);

  // --- Send MQTT if changed ---
  if (a != lastA || b != lastB || c != lastC || d != lastD) {
    sendJson(a, b, c, d, relayState);
    lastA = a;
    lastB = b;
    lastC = c;
    lastD = d;
  }

  // --- Relay toggle button ---
  if (digitalRead(buttonPin) == LOW) { // pressed
    if (millis() - lastDebounce > debounceDelay) {
      relayState = !relayState;
      digitalWrite(relayPin, relayState);
      Serial.print("Relay is now: ");
      Serial.println(relayState ? "ON" : "OFF");
      lastDebounce = millis();

      // Send MQTT immediately for relay change
      sendJson(a, b, c, d, relayState);
    }
  }

  delay(50); // loop delay
}