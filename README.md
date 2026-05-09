# EMS-Based Wireless Gesture-Controlled Smart Lamp

An ESP32-based wireless smart lamp controlled using hand gestures and motion sensing.

## Project Overview

This project uses two ESP32 boards communicating wirelessly using ESP-NOW protocol.

The transmitter node reads gesture and motion data from:
- MPU6050 IMU Sensor
- PAJ7620 Gesture Sensor

The receiver node controls the lamp based on received gesture commands.

---

## Features

- Wireless gesture-based lamp control
- ESP-NOW low latency communication
- Real-time embedded firmware
- Interrupt-driven sensor handling
- Reliable gesture recognition
- Indoor operating range up to 10 meters
- Response latency below 50ms

---

## Hardware Used

| Component | Description |
|---|---|
| ESP32 | Main controller |
| MPU6050 | Motion sensing IMU |
| PAJ7620 | Gesture recognition sensor |
| Relay Module | Lamp switching |
| LED Lamp | Output load |

---

## Software & Technologies

- Embedded C++
- Arduino IDE
- ESP-NOW Protocol
- I2C Communication (400kHz)
- Interrupt-driven Firmware

---

## Supported Gestures

| Gesture | Action |
|---|---|
| Swipe Right | Lamp ON |
| Swipe Left | Lamp OFF |
| Up | Brightness Increase |
| Down | Brightness Decrease |
| Clockwise | Mode Change |
| Anti-Clockwise | Reset |

---

## System Architecture

Transmitter ESP32:
- Reads sensor data
- Detects gestures
- Sends wireless commands

Receiver ESP32:
- Receives ESP-NOW packets
- Controls relay/lamp

---




## Future Improvements

- Mobile App Integration
- Voice Assistant Support
- MQTT Cloud Monitoring
- Smart Home Automation

---



