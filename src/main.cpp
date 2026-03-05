#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// ===== WiFi Credentials =====
const char* ssid = "narzo 50i";         // Replace with your WiFi name
const char* password = "Jone1236"; // Replace with your WiFi password

// ===== OpenWeatherMap API =====
String apiKey = "5011e311451a9ff99e736cccfb5e86a1"; // Replace with your API key
String city = "Chennai";
String weatherURL = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

// ===== ThingSpeak API =====
String writeAPIKey = "7GXZ21HTIOGTPNMS";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi!");
  Serial.println("ESP32 IP Address: " + WiFi.localIP().toString());
}

void sendToThingSpeak(float temp, float humidity) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String thingspeakURL = "http://api.thingspeak.com/update?api_key=" + writeAPIKey;
    thingspeakURL += "&field1=" + String(temp) + "&field2=" + String(humidity);

    http.begin(thingspeakURL);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("✅ Data sent to ThingSpeak successfully");
    } else {
      Serial.println("❌ Failed to send data to ThingSpeak");
    }
    http.end();
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(weatherURL);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      float temp = doc["main"]["temp"];
      float humidity = doc["main"]["humidity"];
      String weather = doc["weather"][0]["description"];

      Serial.println("===== Weather Data =====");
      Serial.println("City: " + city);
      Serial.println("Temperature: " + String(temp) + " °C");
      Serial.println("Humidity: " + String(humidity) + " %");
      Serial.println("Condition: " + weather);
      Serial.println("========================\n");

      // Send to ThingSpeak
      sendToThingSpeak(temp, humidity);

    } else {
      Serial.println("❌ HTTP request failed");
    }
    http.end();
  } else {
    Serial.println("❌ WiFi Disconnected!");
  }

  delay(60000); // Fetch & send data every 60 seconds
}