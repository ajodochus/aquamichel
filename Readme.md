# Aquamichel ESP32 Firmware

This document outlines the pinout configuration for the Aquamichel ESP32 project.

## GPIO Pin Assignments

| Pin Name (in code) | GPIO Number | Component                       | Purpose                                           |
|--------------------|-------------|---------------------------------|---------------------------------------------------|
| `DHTPIN`           | 13          | DHT22 Sensor                    | Data pin for temperature and humidity sensing     |
| `LOADCELL_DOUT_PIN`| 4           | HX711 Load Cell Amplifier       | Data output from the load cell amplifier          |
| `LOADCELL_SCK_PIN` | 5           | HX711 Load Cell Amplifier       | Serial clock for the load cell amplifier          |
| `I2C_SDA`          | 21          | OLED Display (SSD1306)          | I2C Serial Data line for the display            |
| `I2C_SCL`          | 22          | OLED Display (SSD1306)          | I2C Serial Clock line for the display           |
| `redPin`           | 25          | RGB LED / Red LED               | Controls the red color component of the status LED|
| `greenPin`         | 26          | RGB LED / Green LED             | Controls the green color component of the status LED|
| `bluePin`          | 27          | RGB LED / Blue LED              | Controls the blue color component of the status LED |
| `PushButton`       | 15          | Push Button                     | Input for cycling through display modes/states    |
| `WATERSENSOR_PIN`  | 36          | Capacitive Soil Moisture Sensor | Analog input for soil moisture level detection    |

**Notes:**
*   Ensure that the physical wiring matches these assignments.
*   GPIO 36 is an ADC1 channel, which is appropriate for the analog `WATERSENSOR_PIN`.
*   The I2C pins (21, 22) are the default I2C pins for many ESP32 boards.
*   Verify that no other components are unintentionally sharing these pins.
