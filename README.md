# ESP32 FTP Server

An FTP server running on an ESP32 in Access Point (AP) mode with SD card storage.

## Hardware Requirements
- ESP32 Development Board
- SD Card Module (connected via SPI)
- Wiring:
  - SD Card CS Pin → GPIO 5
  - Green LED → GPIO 32
  - Red LED → GPIO 33

## Setup
1. Install dependencies:
   - Arduino Libraries: `WiFi`, `SD`, and `FTPServer` (install via Arduino Library Manager).
2. Upload the code to ESP32.
3. Connect to the ESP32’s AP:
   - SSID: `ESP32_AP`
   - Password: `12345678`
4. Use an FTP client (e.g., FileZilla) to connect:
   - IP: Check Serial Monitor for AP IP
   - Username: `esp32`
   - Password: `12345`

## Troubleshooting
- If the SD card fails to mount, check wiring and CS pin.
- Ensure the SD card is formatted as FAT16/FAT32.
