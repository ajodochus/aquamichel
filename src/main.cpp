#include <Arduino.h>
#include "component_led.h"
#include "service.h"
#include "component_display.h"


void setup() {
  Serial.begin(9600);  // Start serial communication at 115200 baud rate
  component_led_setup();
  countdown_start();
  display_setup();
}

void loop() {
  component_led_loop();
  check_countdown();
  
  display_show_message(String(timer_current_time));

}