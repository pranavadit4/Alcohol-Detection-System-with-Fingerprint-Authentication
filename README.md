# Alcohol Detection System with Fingerprint Authentication

A comprehensive system to prevent drunk driving by combining alcohol detection with fingerprint authentication and real-time alerts.

## Features
- Fingerprint authentication for authorized users only
- MQ3 alcohol sensor for accurate BAC detection
- GSM/GPS module for sending alerts with location
- ESP32 microcontroller for processing
- Buzzer and LCD for local alerts
- DC motor control (simulating vehicle ignition)

## Hardware Components
- ESP32 microcontroller
- MQ3 Alcohol Sensor
- Fingerprint Sensor (R305)
- GSM Module (SIM800L)
- GPS Module
- Relay Module
- DC Motor
- Buzzer
- LCD Display
- Ignition Key Switch

## Software Requirements
- Arduino IDE 1.8.5+
- Embedded C
- Required libraries (see software/libraries)

## Installation
1. Clone this repository
2. Open the Arduino sketch in `/software/src/alcohol_detection.ino`
3. Install required libraries
4. Upload to ESP32 board

## Usage
1. Insert ignition key
2. Authenticate with registered fingerprint
3. System checks alcohol level
4. If below threshold, motor activates
5. If above threshold, buzzer sounds and alert sent

## Project Documentation
See [docs/Project_Report.pdf](docs/Project_Report.pdf) for complete details.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
