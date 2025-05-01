#include <Arduino.h>
// Blink sketch for ESP32

#define INTERNAL_LED 12  // Built-in LED is usually on GPIO 2

const int redPin = 23;    // Red LED 
const int greenPin = 22; // Green LED

void setup() {
  pinMode(INTERNAL_LED, OUTPUT);  // Set LED pin as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  analogWrite(greenPin, 100);
  analogWrite(redPin, 100);
  Serial.begin(9600);  // Start serial communication at 115200 baud rate
}

void loop() {
  Serial.println("Blinking LED...");  // Print message to serial monitor
  digitalWrite(INTERNAL_LED, HIGH);  // Turn the LED on
  delay(100);                  // Wait for 1 second
  digitalWrite(INTERNAL_LED, LOW);   // Turn the LED off
  delay(100);                  // Wait for 1 second
}
