#include <Arduino.h>
// Blink sketch for ESP32


const int redPin = 25;    // Red LED 
const int greenPin = 26; // Green LED
const int bluePin = 27;   // Blue LED

void component_led_setup() {
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  analogWrite(greenPin, 200);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
  
}

void led_turn_on_green() {
  analogWrite(greenPin, 200);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 0);
}
void led_turn_on_blue() {
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 200);
  analogWrite(redPin, 0);
}
void led_turn_on_red() {
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(redPin, 200);
}