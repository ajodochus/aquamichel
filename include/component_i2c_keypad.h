// component_i2c_keypad.h
#ifndef COMPONENT_I2C_KEYPAD_H
#define COMPONENT_I2C_KEYPAD_H

#include <Arduino.h>
// Using Rob Tillaart's I2CKeyPad library
#include <I2CKeyPad.h> 
#include <Wire.h>       // Required for I2C communication

// I2C address of the PCF8574 module connected to the keypad.
// Your scan showed a device at 0x20, which we'll assume is the PCF8574 for the keypad.
#define KEYPAD_I2C_ADDRESS 0x20 

// Keypad dimensions (e.g., 4x4)
// This library might not need explicit row/col pin definitions if the PCF8574 is hardwired
// in a standard way for the keypad, but the keymap is essential.
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

// Keymap: Define the characters for each key
extern char keys[KEYPAD_ROWS * KEYPAD_COLS]; // Changed to 1D array to match definition

// Declare the I2CKeyPad object
extern I2CKeyPad keypad; // Changed from kpd to keypad for clarity with new library

// Function to initialize the keypad
void i2c_keypad_setup();

// Function to get the currently pressed key
char i2c_keypad_get_key_loop();

// Function to get a new key press event (returns key only once per press)
char i2c_keypad_get_new_key();

// Function to process keypad input for menu navigation
void i2c_keypad_process_menu_key(char key);

#endif // COMPONENT_I2C_KEYPAD_H
