#include <Arduino.h>
#include "component_led.h"
#include "service.h"
#include "component_display.h"
#include "server.h"
#include "scale.h"
#include "config.h"
#include "component_push_button.h"
#include "watersensor.h"
#include "dht22.h" // Add this line
#include "component_i2c_keypad.h" // Add this for the I2C Keypad
#include <Wire.h> // Add this for I2C communication

const char* ssid = config_ssid;  // Replace with your network credentials
const char* password = config_password;  // Replace with your network credentials

// Define I2C pins (if not using defaults, though display.cpp already defines them)
// const int I2C_SDA_PIN = 21;
// const int I2C_SCL_PIN = 22;

void setup() {
  Serial.begin(9600);  // Start serial communication
  
  // Initialize I2C bus. This should be done once.
  // The display component uses I2C_SDA (21) and I2C_SCL (22) defined in component_display.cpp
  // If your display setup doesn't call Wire.begin(), or if you want to be explicit:
  Wire.begin(21, 22); // Using GPIO21 for SDA, GPIO22 for SCL

  component_led_setup();
  dht22_setup(); 
  display_setup(); // Setup display (uses I2C address 0x3C as per component_display.cpp)
  i2c_keypad_setup(); // Setup keypad (uses I2C address 0x20 as per component_i2c_keypad.h)
  i2c_keypad_init_password_state(); // Initialize password state
  startWiFiAndServer(ssid, password);
  //timer_10s_start();
  timer_1s_start(); 
  scale_setup();
  component_push_button_setup();
  watersensor_setup();
}

void loop() {
 service_loop();

}