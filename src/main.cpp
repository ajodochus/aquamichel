#include <Arduino.h>
#include "component_led.h"
#include "service.h"
#include "component_display.h"
#include "server.h"
#include "scale.h"

const char* ssid = "33rn4";
const char* password = "51141929344873172890";

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
  //component_led_loop();
  check_countdown();
  display_second_line = timer_current_time;
  display_show_message();
  scale_get_weight();
}