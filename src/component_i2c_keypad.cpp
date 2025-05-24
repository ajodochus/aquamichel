// component_i2c_keypad.cpp
#include "component_i2c_keypad.h"
#include "component_display.h" // For display functions
#include "dht22.h"             // For dht22 functions
#include "watersensor.h"       // For watersensor functions

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

// Variable to store the last key state to detect changes
static char last_key_pressed = 0;
static bool key_was_pressed_in_last_check = false;

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

// Forward declaration if i2c_keypad_handle_password_entry is defined after its call
// For simplicity, we can define it before i2c_keypad_process_menu_key or make it static.

static void i2c_keypad_handle_password_entry() {
    String entered_keys = "";
    int press_count = 0;

    display_set_first_line("Enter 4 keys:");
    display_set_second_line("");
    display_set_third_line("");
    display_refresh();

    while (press_count < 4) {
        char key = 0;
        // Wait for a new key press
        while (key == 0) {
            key = i2c_keypad_get_new_key();
            delay(50); // Small delay to prevent busy-waiting too aggressively
        }

        entered_keys += key;
        display_set_second_line(entered_keys);
        display_refresh();
        press_count++;
    }

    display_set_first_line("Keys entered:");
    // display_set_second_line(entered_keys); // Already showing
    display_set_third_line("Done.");
    display_refresh();

    delay(2000); // Show the final input for a couple of seconds

    // Optionally, clear the display or return to a default state after this
    // For now, it will just return, and the next service_loop call will update the display
    // based on cycle_display_state or other logic.
}

char i2c_keypad_get_key_loop() {
    // Read the key from the keypad
    if (keypad.isPressed()) {
        int keyValue = keypad.getKey(); // getKey() returns an int (ASCII value)
        if (keyValue >= 0 && keyValue < (KEYPAD_ROWS * KEYPAD_COLS)) { // Check if the index is valid for our keymap
             // The basic getKey() from this library might return an index 0..15 for a 4x4 keypad.
             // We need to map this index to our actual character keymap.
            //Serial.print("Keypad key index: ");
            //Serial.println(keys[keyValue]);
            return keys[keyValue];
        }
    }
    return 0; // Return 0 or a specific NO_KEY character if no key is pressed or invalid key
}

char i2c_keypad_get_new_key() {
    char current_key_char = 0;
    bool key_is_currently_pressed = keypad.isPressed();

    if (key_is_currently_pressed) {
        int keyValue = keypad.getKey(); // Get the raw key value (index or ASCII)
        if (keyValue >= 0 && keyValue < (KEYPAD_ROWS * KEYPAD_COLS)) {
            current_key_char = keys[keyValue]; // Map to our character
        }

        if (!key_was_pressed_in_last_check) {
            // Key was just pressed (was not pressed in the last check)
            last_key_pressed = current_key_char;
            key_was_pressed_in_last_check = true;
            Serial.print("New key pressed: ");
            Serial.println(current_key_char);
            return current_key_char; // Return the new key press
        } else if (current_key_char != last_key_pressed) {
            // A different key is now pressed while a key was already held down
            // This case might be complex depending on desired behavior (e.g. rollover)
            // For simple "new key since last release" this might not be hit often
            // or could be treated as a new press of the new_key.
            last_key_pressed = current_key_char;
            // key_was_pressed_in_last_check remains true
            return current_key_char; // Return the new different key
        }
        // else: Same key is still being held, do nothing, return 0 later

    } else {
        // No key is currently pressed
        if (key_was_pressed_in_last_check) {
            // Key was just released
            last_key_pressed = 0; // Reset last key
            key_was_pressed_in_last_check = false;
        }
        // else: No key was pressed, and no key was pressed before either
    }

    return 0; // No new distinct key press event
}

void i2c_keypad_process_menu_key(char key) {
    if (key == 0) { // No new key, do nothing
        return;
    }

    Serial.print("Menu key pressed: ");
    Serial.println(key);
    
    switch (key) {
        case 'A':
            display_set_first_line("Menu A");
            display_set_second_line("Hum: " + String(dht22_get_humidity()) + "%");
            display_set_third_line("Temp: " + String(dht22_get_temperature()) + " C");
            display_refresh();
            break;
        case 'B':
            display_set_first_line("Menu B");
            display_set_second_line("Water: " + String(watersensor_get_percentage()) + "%");
            display_set_third_line(""); // Clear third line
            display_refresh();
            break;
        case 'C':
            display_set_first_line("Menu C");
            display_set_second_line(""); // Clear second line
            display_set_third_line("");  // Clear third line
            display_refresh();
            break;
        case '#': // Handle password entry
            i2c_keypad_handle_password_entry();
            break;
        // Add cases for other keys if needed (e.g., 'D', '*', numbers for password entry)
        default:
            // Optional: handle other keys, or do nothing
            // Serial.print("Key "); Serial.print(key); Serial.println(" not assigned to menu.");
            break;
    }
}

