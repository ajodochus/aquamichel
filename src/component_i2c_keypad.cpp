// component_i2c_keypad.cpp
#include "component_i2c_keypad.h"

// Define the keymap for Rob Tillaart's I2CKeyPad library.
// This library typically uses a linear array for the keymap.
char keys[KEYPAD_ROWS * KEYPAD_COLS] = {
  '1','2','3','A',
  '4','5','6','B',
  '7','8','9','C',
  '*','0','#','D'
};

// Initialize the I2CKeyPad object.
// Parameters: I2C_address, Wire_object (optional, defaults to &Wire)
// Some versions might allow passing SDA, SCL pins if not using default Wire.
I2CKeyPad keypad(KEYPAD_I2C_ADDRESS, &Wire);

void i2c_keypad_setup() {
    // Wire.begin() should be called once in the main setup() function.
    // Initialize the keypad
    if (keypad.begin()) { // The begin() function might take SDA, SCL pins for non-default Wire init.
        Serial.println("I2CKeyPad (Rob Tillaart) initialized at address 0x" + String(KEYPAD_I2C_ADDRESS, HEX));
    } else {
        Serial.println("Failed to initialize I2CKeyPad (Rob Tillaart) at address 0x" + String(KEYPAD_I2C_ADDRESS, HEX));
    }
    // Load the keymap. The method might vary slightly based on library version.
    // For some versions, it might be keypad.loadKeyMap((char*)keys, KEYPAD_ROWS, KEYPAD_COLS);
    // For others, it might be set during construction or a different method.
    // The library typically assumes a PCF8574 mapping where it scans rows/cols.
    // If your keypad module has a specific mapping, you might need to adjust.
    // This version of the library might not require explicit loadKeyMap if keys are standard matrix on PCF8574
}

char i2c_keypad_get_key() {
    // Read the key from the keypad
    if (keypad.isPressed()) {
        int keyValue = keypad.getKey(); // getKey() returns an int (ASCII value)
        if (keyValue >= 0 && keyValue < (KEYPAD_ROWS * KEYPAD_COLS)) { // Check if the index is valid for our keymap
             // The basic getKey() from this library might return an index 0..15 for a 4x4 keypad.
             // We need to map this index to our actual character keymap.
            return keys[keyValue]; 
        }
    }
    return 0; // Return 0 or a specific NO_KEY character if no key is pressed or invalid key
}
