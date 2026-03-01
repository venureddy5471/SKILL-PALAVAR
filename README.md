## 👨‍💻 Team Members

BATCH 11
2300049003 - **THALLAM VENKATA SAGAR**
2300040396 - **ANNAPAREDDY VISHNU VARDHAN REDDY**
2300040200 - **EPPALA VENU MADHAVA REDDY**

---

# 🅿️ Smart Parking System Using ESP32 and Blynk Web Dashboard with OTA Support

## 📌 Project Overview

This project focuses on the design and implementation of a **Smart Parking System** that uses **ESP32 microcontrollers**, ultrasonic sensors, and the **Blynk IoT platform** to monitor parking slot availability in real time.
The system enables users to view live parking occupancy status through a **Blynk Web Dashboard** accessible from any browser or mobile device, eliminating the need to physically search for available slots.
The solution also supports **Over-the-Air (OTA) firmware updates**, allowing the system to be upgraded remotely without any physical access to the hardware.
> ⚠️ **Project Status:** This project is currently under development as part of academic evaluation and ongoing implementation.

---

## 🎯 Objectives

- Detect vehicle presence in parking slots using ultrasonic sensors.
- Display real-time slot availability on the Blynk Web Dashboard.
- Enable remote monitoring from any device via WiFi.
- Support OTA firmware updates for seamless maintenance.
- Provide instant notifications when parking slot status changes.
- Build a scalable and low-cost smart parking prototype.

---

## 🚨 Problem Statement

Urban parking areas often cause frustration due to the lack of real-time information about slot availability, leading to wasted time, traffic congestion, and fuel consumption.

Existing smart parking solutions are typically expensive and require dedicated infrastructure.

This project aims to develop a **low-cost, IoT-based prototype** that demonstrates real-time parking management using affordable embedded hardware and cloud-connected dashboards.

---

## ⚙️ System Features

- ✅ Real-Time Slot Occupancy Detection
- ✅ Blynk Web Dashboard Monitoring
- ✅ WiFi-Based Remote Access
- ✅ Over-the-Air (OTA) Firmware Updates
- ✅ Push Notifications on Status Change
- ✅ Available Slot Counter Display
- ✅ Scalable Multi-Slot Architecture
- ✅ Low-Cost and Energy-Efficient Design

---

## 🛠 Hardware Components

| Component | Description |
|---|---|
| ESP32 Development Board | Main microcontroller with built-in WiFi |
| HC-SR04 Ultrasonic Sensor | Detects vehicle presence per parking slot |
| LEDs (Red / Green) | Visual occupancy status indicator per slot |
| 330Ω Resistors | Current limiting for LEDs |
| Buzzer (optional) | Audible alert on status change |
| Breadboard / PCB | Circuit assembly platform |
| 5V USB Power Supply | Power source for ESP32 |
| Connecting Wires | Circuit connections |

---

## 💻 Software Tools

- Arduino IDE / PlatformIO
- Embedded C / C++
- Blynk IoT Platform (blynk.cloud)
- ESP32 Arduino Core
- ArduinoOTA Library
- Serial Monitor for Debugging

---

## 🧩 System Architecture

The ESP32 continuously polls ultrasonic sensors connected to each parking slot. When a vehicle is detected within a threshold distance, the slot is marked as **Occupied**; otherwise, it is marked as **Available**.
The ESP32 connects to the internet via WiFi and pushes live slot status to the **Blynk cloud server**. Users can monitor the dashboard from any web browser or the Blynk mobile app in real time.
OTA support allows firmware to be updated remotely via the Arduino OTA protocol once the device is connected to the network.

---

## 🔄 Methodology

1. ESP32 initializes WiFi connection and connects to the Blynk server.
2. Ultrasonic sensors continuously measure distance to detect vehicle presence.
3. If distance is below the threshold, the slot is marked **Occupied** (Red LED ON).
4. If distance is above the threshold, the slot is marked **Available** (Green LED ON).
5. Slot status and available count are sent to Blynk Virtual Pins in real time.
6. The Blynk Web Dashboard updates live for remote monitoring.
7. Notifications are triggered when a slot status changes.
8. OTA update mode allows firmware flashing over the network when required.

---

## 📱 Blynk Dashboard Setup

1. Register at [blynk.cloud](https://blynk.cloud) and create a new **Template**.
2. Create the following **Datastreams** (Virtual Pins):

| Virtual Pin | Name | Data Type |
|---|---|---|
| V0 | Slot 1 Status | String |
| V1 | Slot 2 Status | String |
| V2 | Available Slots | Integer |
| V3 | Total Slots | Integer |

3. Design the **Web Dashboard** with Label, LED, and Value Display widgets.
4. Copy your `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN` into the code.

---

## 🔄 OTA Update Support

This project uses the `ArduinoOTA` library for wireless firmware updates.

Once the ESP32 is powered on and connected to WiFi, it can be updated directly from the Arduino IDE:

1. Open Arduino IDE → **Tools → Port** → Select the OTA network port (ESP32 hostname).
2. Click **Upload** — the firmware will be flashed over WiFi without any USB connection.

```

## 📁 Project Structure

```
Smart-Parking-System/
│
├── Smart_Parking_System.ino   # Main Arduino sketch
├── README.md                  # Project documentation
├── block_diagram.jpeg         # System block diagram
└── circuit_diagram.jpeg       # Circuit wiring diagram
```

---

## 🚀 Applications

- Shopping Mall and Commercial Parking Management
- Hospital and Emergency Zone Parking
- Corporate Campus Parking Systems
- Airport Parking Monitoring
- Smart City Infrastructure Projects

---

## 🔮 Future Scope

- Integration with Google Maps for navigation to nearest available slot
- Mobile app with slot reservation and pre-booking system
- AI-based parking demand prediction and analytics
- Automated barrier gate control using servo motors
- Multi-floor parking management with a centralized dashboard
- Solar-powered deployment for off-grid energy efficiency

---

## 📌 Note

This repository contains the implementation code, circuit diagrams, and documentation related to the Smart Parking System prototype developed using ESP32 and the Blynk IoT platform.

---

## 📜 License

This project is developed for academic and educational purposes.

---

⭐ If you find this project useful, feel free to star the repository and contribute!
