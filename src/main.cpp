#include <Arduino.h>
#include "component_led.h"
#include "service.h"
#include "component_display.h"
#include "server.h"
#include "scale.h"
#include "config.h"

const char* ssid = config_ssid;  // Replace with your network credentials
const char* password = config_password;  // Replace with your network credentials

void setup() {
  Serial.begin(9600);  // Start serial communication at 115200 baud rate
  //component_led_setup();
  startWiFiAndServer(ssid, password);
  countdown_start();
  display_setup();
  scale_setup();
  //scale_tare();
  //scale_get_weight();
  //Serial.println(scale_current_weight);
  //component_led_loop();

}

void loop() {
 service_loop();
}