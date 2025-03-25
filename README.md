Alcohol Detection System with Fingerprint Authentication
🚗 A smart vehicle safety system to prevent drunk driving by combining alcohol detection with biometric authentication and real-time alerts.

📌 Overview
This project implements an IoT-based alcohol detection system integrated with fingerprint authentication to enhance vehicle security and prevent drunk driving. The system ensures that only authorized users with acceptable blood alcohol concentration (BAC) levels can start the vehicle. If alcohol levels exceed the threshold, the system triggers an alarm and sends an SMS alert with GPS coordinates to a predefined contact.

🔑 Key Features
✅ Fingerprint Authentication – Ensures only registered users can operate the vehicle.
✅ MQ3 Alcohol Sensor – Accurately detects alcohol levels in breath.
✅ GSM & GPS Integration – Sends real-time SMS alerts with location if alcohol is detected.
✅ ESP32 Microcontroller – Processes sensor data and controls system logic.
✅ Ignition Lock Mechanism – Prevents engine start if alcohol levels are unsafe.
✅ Buzzer & LCD Alerts – Provides immediate local warnings.

🛠 Hardware Components
ESP32 (Wi-Fi & Bluetooth-enabled microcontroller)

Fingerprint Sensor (R305) – Biometric authentication

MQ3 Alcohol Sensor – Detects ethanol concentration

SIM800L GSM Module – For SMS alerts

GPS Module – Tracks vehicle location

Relay Module – Controls DC motor (simulates ignition)

DC Motor – Represents vehicle ignition system

Buzzer – Audio alarm for high BAC levels

LCD Display – Shows system status & BAC levels

Ignition Key Switch – Manual override option

💻 Software & Libraries
Arduino IDE (for ESP32 programming)

Embedded C (firmware logic)

Adafruit Fingerprint Library (biometric handling)

TinyGPS++ (GPS data parsing)

SoftwareSerial (for GSM communication)

🚀 How It Works
User inserts the ignition key to activate the system.

Fingerprint authentication verifies the driver's identity.

MQ3 sensor checks alcohol levels in the breath.

If BAC is below threshold:

Relay activates, allowing the DC motor (vehicle ignition) to start.

If BAC exceeds threshold:

Buzzer sounds & LCD displays a warning.

GSM module sends an SMS alert with GPS coordinates to a predefined number.

Engine remains locked.

📂 Repository Contents
/docs – Project report, literature survey, and datasheets.

/hardware – Circuit schematics & component details.

/software – Arduino code and required libraries.

/images – System photos and diagrams.

🔧 Installation & Setup
Clone the repository

bash
Copy
git clone https://github.com/yourusername/Alcohol-Detection-System-with-Fingerprint-Authentication.git
Open alcohol_detection.ino in Arduino IDE.

Install required libraries (Adafruit Fingerprint, TinyGPS++, etc.).

Upload to ESP32 and connect hardware as per schematics.

📜 License
This project is open-source under the MIT License.

🌟 Potential Applications
Smart vehicles & anti-drunk driving systems

Fleet management & employee safety compliance

College/Corporate transportation security

🔗 Contribute or Fork! Suggestions and improvements are welcome!

🚫 Don't Drink & Drive – Stay Safe! 🚗💨

(For detailed documentation, check the /docs folder.)
