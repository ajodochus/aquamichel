#include <Arduino.h>
// Blink sketch for ESP32

#define INTERNAL_LED 12  // Built-in LED is usually on GPIO 2

const int redPin = 18;    // Red LED 
const int greenPin = 19; // Green LED

void component_led_setup() {
  pinMode(INTERNAL_LED, OUTPUT);  // Set LED pin as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  analogWrite(greenPin, 200);
  analogWrite(redPin, 0);
  
}

void component_led_loop() {
  //Serial.println("Blinking LED...");  // Print message to serial monitor
  digitalWrite(INTERNAL_LED, HIGH);  // Turn the LED on
                // Wait for 1 second
  digitalWrite(INTERNAL_LED, LOW);   // Turn the LED off

}