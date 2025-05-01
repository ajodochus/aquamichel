#include <Arduino.h>
#include "component_led.h"
#include "service.h"


void setup() {
  Serial.begin(9600);  // Start serial communication at 115200 baud rate
  component_led_setup();
  countdown_start();
}

void loop() {
  component_led_loop();
  check_countdown();
  delay(1000); // Delay for 1 second  

}
