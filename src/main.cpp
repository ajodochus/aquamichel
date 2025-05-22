#include <Arduino.h>
#include "component_led.h"
#include "service.h"
#include "component_display.h"
#include "server.h"
#include "scale.h"
#include "config.h"
#include "component_push_button.h"
#include "watersensor.h"

const char* ssid = config_ssid;  // Replace with your network credentials
const char* password = config_password;  // Replace with your network credentials

void setup() {
  Serial.begin(9600);  // Start serial communication at 115200 baud rate
  component_led_setup();
  startWiFiAndServer(ssid, password);
  timer_10s_start();
  display_setup();
  scale_setup();
  component_push_button_setup();
  watersensor_setup();
}

void loop() {
 service_loop();
}