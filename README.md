# esp32*weather*dashboard
An IoT project using ESP32 that retrieves real*time weather data from the OpenWeatherMap API and uploads it to the ThingSpeak Cloud Dashboard for visualization and analysis.

This project demonstrates WiFi communication, REST API integration, JSON parsing, and cloud data logging using ESP32.
## Project Overview
The ESP32 connects to WiFi and periodically fetches weather information such as temperature and humidity from an online weather API. The data is then processed and sent to ThingSpeak, where it can be monitored through graphical dashboards.

This project shows how IoT devices can interact with cloud platforms without external sensors, using public APIs.
### Features
*🌐 Connects ESP32 to WiFi network

*☁ Fetches live weather data using OpenWeatherMap API

*📊 Uploads data to ThingSpeak Cloud Platform

*🔎 Parses JSON response using ArduinoJson library

*🖥 Displays results in Serial Monitor

*📡 Fully wireless operation (no GPIO sensors required)

#### Setup
1️⃣ Install Required Software

Install the following:

VS Code

PlatformIO Extension

Git (optional for version control)

2️⃣ Clone the Repository
```Bash
git clone https://github.com/yourusername/esp32*weather*dashboard.git
```
3️⃣ Install Required Libraries

PlatformIO automatically installs dependencies defined in platformio.ini.
Main library used:
```
ArduinoJson
```
4️⃣ Configure WiFi Credentials

Edit the following variables in main.cpp
```C++
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```
5️⃣ Configure OpenWeatherMap API
Create a free API key from:
(https://openweathermap.org/api)
```C++
const char* apiKey = "YOUR_OPENWEATHER_API_KEY";
```
6️⃣ Configure ThingSpeak Channel
[Create a channel on:](https://thingspeak.com)
Copy your Write API Key and insert in the code.
```C++
String writeAPIKey = "YOUR_THINGSPEAK_WRITE_KEY";
```
▶ Running the Project
1. Connect ESP32 to your computer / laptop
2. Open the project in VS Code
3. Build and Upload firmware
```
PlatformIO → Upload
```
Open the Serial Monitor to view live data.
Expected output example:
```
Connecting to WiFi...
Connected to WiFi

Temperature: 32.4°C
Humidity: 71%

Uploading data to ThingSpeak...
Upload successful
```
📊 Cloud Dashboard
The ESP32 sends weather data to ThingSpeak, which generates graphs like:

*Temperature vs Time

*Humidity vs Time
Example dashboard:
```
ThingSpeak Channel
Field 1 → Temperature
Field 2 → Humidity
```

🔮 Future Improvements
Possible extensions for this project:

*Add BME280 or DHT22 sensor for local weather measurement

*Create a web dashboard hosted on ESP32

*Implement data logging and analytics

*Use MQTT instead of HTTP

*Build a mobile IoT dashboard
