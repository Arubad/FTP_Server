// Connect to Wi-Fi
#include <WiFi.h>
#include <SD.h>
#include "FTPServer.h"

// Define your network credentials for the AP mode
const char* apSSID = "ESP32_AP";
const char* apPassword = "12345678";  // Password must be at least 8 characters

// Create an FTP server instance using the SD filesystem
FTPServer ftpSrv(SD);

// Define SD card chip select pin (usually 5, 13, 14, or 15 for ESP32 boards)
const int SD_CS_PIN = 5;

// LED pin definitions
const int GREEN_LED_PIN = 32;
const int RED_LED_PIN = 33;

void setup() {
  Serial.begin(115200);

  // Set LED pins as outputs
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Set ESP32 to Access Point Mode (AP)
  WiFi.mode(WIFI_AP);
  WiFi.softAP(apSSID, apPassword);

  Serial.println("ESP32 running as Access Point in AP mode");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Initialize the SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD Card Mount Failed");
    blinkRedLED();
    return;
  }
  Serial.println("SD Card mounted successfully");

  // Start the FTP server with a username and password
  if (ftpSrv.begin("esp32", "12345")) {
    Serial.println("FTP server started successfully");
    blinkGreenLED();
  } else {
    Serial.println("FTP server failed to start");
    blinkRedLED();
  }
}

void loop() {
  // Continuously handle FTP server requests
  ftpSrv.handleFTP();
}

// Function to blink the Green LED for FTP success
void blinkGreenLED() {
  for (int i = 0; i < 3; i++) {  // Blink 3 times
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(200);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(200);
  }
}

// Function to blink the Red LED for errors
void blinkRedLED() {
  for (int i = 0; i < 3; i++) {  // Blink 3 times
    digitalWrite(RED_LED_PIN, HIGH);
    delay(200);
    digitalWrite(RED_LED_PIN, LOW);
    delay(200);
  }
}
