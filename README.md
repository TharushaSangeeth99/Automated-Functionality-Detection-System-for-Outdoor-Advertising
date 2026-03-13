<p align="center">
  <img src="Media/banner.webp" width="900">
</p>

<h1 align="center">
Autonomous Portable Water Quality Monitoring Robot
</h1>

<p align="center">
An IoT-based autonomous robotic system designed for real-time water quality monitoring and environmental analysis.
</p>

<p align="center">

![IoT](https://img.shields.io/badge/Project-IoT-blue)
![ESP32](https://img.shields.io/badge/Microcontroller-ESP32-red)
![MQTT](https://img.shields.io/badge/Protocol-MQTT-green)
![React](https://img.shields.io/badge/Dashboard-React-blueviolet)

</p>

---

# Project Overview

Outdoor advertising installations such as LED panels and billboards often suffer from operational failures including power outages, power supply faults, and switching circuit failures.

This project introduces an **IoT-based automated monitoring system** that continuously monitors the operational status of outdoor advertising panels and detects different types of faults in real time.

The system automatically transmits operational data to a **cloud-based monitoring platform**, enabling remote supervision and rapid fault detection.

This project was developed as part of **Industrial Training under the Department of Electronics, Wayamba University of Sri Lanka**.

---

# Parameters Measured

- Total Dissolved Solids (TDS)
- Water Temperature
- Ambient Humidity
- Electrical Conductivity
- Water Hardness
- Water Quality Index

---

# Complete Robot System

<p align="center">
<img src="Media/Complete Unit.webp" width="700">
</p>

The final system consists of a floating robotic platform equipped with sensors, wireless communication modules, and an IoT dashboard for monitoring environmental data.

---

# System Architecture

<p align="center">
<img src="Media/system_architecture.webp" width="800">
</p>

The system architecture integrates hardware sensors, wireless communication, cloud data processing, and a real-time dashboard.

### Hardware Components

- ESP32 Microcontroller
- TDS Sensor
- DS18B20 Temperature Sensor
- DHT11 Humidity Sensor
- nRF24L01 Communication Module
- Motorized Depth Winch System

### Software Components

- MQTT Communication
- Telegraf Data Processing
- InfluxDB Time-Series Database
- React.js Web Dashboard
- Grafana Visualization

---

# Mechanical Design (SolidWorks)

<p align="center">
<img src="Media/Complete Prototype.webp" width="700">
</p>

The mechanical structure was designed using **SolidWorks** with a **catamaran hull design** to provide stability in water.

### Key Mechanical Features

- Twin hull PVC floating structure
- Lightweight PLA mounting platform
- Sensor deployment mechanism
- Integrated motorized winch system

---

# Circuit Design

## Breadboard Prototype

<p align="center">
<img src="Media/breadboard_circuit.webp" width="700">
</p>

Initial circuit testing was performed on a **breadboard prototype** to verify sensor readings, ESP32 communication, and power distribution before PCB development.

---

## Circuit Diagram

<p align="center">
<img src="Media/circuit_diagram.webp" width="750">
</p>

A custom electronic circuit was designed to integrate sensors, communication modules, and power management.

### Main Circuit Blocks

- ESP32 control unit
- Sensor interface circuits
- Motor driver circuits
- Wireless communication module
- Voltage regulation system

---

# PCB Layout Design

The electronic system was implemented using **custom-designed PCBs**.

## Panelized PCB Layout (Top & Bottom)

<p align="center">
<img src="Media/PCB_top_and_bottom" width="750">
</p>

This layout shows the **panelized PCB design including both top and bottom layers** prepared for manufacturing.

---

## PCB Prototype

<p align="center">
<img src="Media/PCB_Prtotype.webp" width="650">
</p>

Prototype PCBs were assembled and tested to validate circuit performance and sensor integration.

---

## Fabricated PCB

<p align="center">
<img src="Media/pcb_fabricated.jpg" width="650">
</p>

The final PCBs were fabricated using **FR4 double-layer boards**, ensuring durability and reliable electrical performance.

---

# IoT Monitoring Dashboard

<p align="center">
<img src="Media/Dashboard.webp" width="850">
</p>

The system includes a **real-time IoT dashboard** displaying sensor readings and historical environmental data.

### Dashboard Features

- Live sensor monitoring
- Historical data visualization
- Water quality analysis
- Remote monitoring capability
- Data logging and reporting

---

# System Unit

<p align="center">
<img src="Media/system_unit.webp" width="750">
</p>

The robotic system integrates sensors, microcontrollers, wireless communication modules, and power systems into a compact floating platform.

---

# Live System Demo

The monitoring dashboard can be accessed here:

🔗 **Live Demo**  
https://wqc-web.web.app

---

# Project Report

You can download the full research report here:

📄 **Download Final Report**  
[Download Report](Documents/Final%20Report.pdf)

---

# Key Features

- Autonomous water monitoring robot
- Real-time IoT data transmission
- Depth-based water sampling
- Custom PCB electronics
- Wireless sensor communication
- Cloud-based data visualization

---

# Technologies Used

### Hardware

- ESP32
- nRF24L01
- TDS Sensor
- DS18B20 Temperature Sensor
- DHT11 Sensor

### Software

- Arduino IDE
- MQTT
- Telegraf
- InfluxDB
- React.js
- Grafana

### Design Tools

- SolidWorks
- Altium Designer

---

# Academic Information

**University**  
Wayamba University of Sri Lanka

**Degree Program**  
B.Sc. (Joint Major) – Electronics and Computing & Information Systems

**Project Type**  
Final Year Undergraduate Research Project

**Research Presentation**  
Presented at **ASRITE Research Symposium**

**Project Supervisor**  
Eng. S.R.L. Gunawardhana

---

# Author

**Tharusha Sangeeth**

Electronics & Embedded Systems Developer  
Wayamba University of Sri Lanka

---
