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

const char* ssid = config_ssid;  // Replace with your network credentials
const char* password = config_password;  // Replace with your network credentials

void setup() {
  Serial.begin(9600);  // Start serial communication at 115200 baud rate
  component_led_setup();
  dht22_setup(); // Add this line
  startWiFiAndServer(ssid, password);
  timer_10s_start();
  timer_1s_start(); // Start the 1s timer
  display_setup();
  scale_setup();
  component_push_button_setup();
  watersensor_setup();
}

void loop() {
 service_loop();
 dht22_read_values(); // Add this line, or call it from a timer in service.cpp
}