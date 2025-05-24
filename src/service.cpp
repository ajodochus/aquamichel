#include <neotimer.h>
#include <Arduino.h>
#include "component_display.h"
#include "server.h"
#include "watersensor.h"
#include "scale.h"
#include "dht22.h" // Include DHT22 header for temperature and humidity
#include "component_i2c_keypad.h" // Include I2C Keypad header

// Function prototype
void timer_10s_start();
void timer_10s_loop();
unsigned long startTime; // Consider if this is shared or if each timer needs its own.
int countdownTime = 10000;
int service_timer_10s_current = 0;
Neotimer timer_10_seconds = Neotimer(countdownTime);

// New 1-second timer variables
void timer_1s_start();
void timer_1s_loop();
int countdownTime_1s = 1000; // 1 second
int service_timer_1s_current = 0;
Neotimer timer_1_second = Neotimer(countdownTime_1s);
unsigned long startTime_1s; // Separate start time for 1s timer

// Global variable to control display state, now managed by keypad and service.
// This might be better placed in a central state management if it grows more complex.
int cycle_display_state = 0; // 0: DHT22 (Menu A), 1: Water (Menu B), 2: Scale (Menu C), 3: System (Menu D)


void service_loop() {
    // component_push_button_loop(); // No longer called
    timer_10s_loop();
    timer_1s_loop(); // Call the 1s timer loop
    dht22_read_values_loop(); 
   
    char new_key = i2c_keypad_get_new_key(); // Get new key press events
    if (new_key) { // If a new key was pressed
        i2c_keypad_process_menu_key(new_key); // Process it for menu navigation
    }
}


void timer_10s_start(){
    timer_10_seconds.set(countdownTime);
    timer_10_seconds.start();
    startTime = millis();
}
void timer_10s_loop(){
    if (timer_10_seconds.waiting()) {
        //Serial.print("Timer: ");
        service_timer_10s_current = timer_10_seconds.stop() / 1000;
        //Serial.println(timer_current_time);
        timer_10_seconds.restart();
    }
    if (timer_10_seconds.done()) {
        //Serial.println("Timer done!");
        timer_10s_start();

    } 
}

// New 1-second timer functions
void timer_1s_start(){
    timer_1_second.set(countdownTime_1s);
    timer_1_second.start();
    startTime_1s = millis(); // Use separate start time
}

void timer_1s_loop(){
    if (timer_1_second.done()) { // Check if the timer is done
        timer_1_second.restart(); // Restart the timer for the next 1-second interval

        display_set_first_line(server_msg); // Always show server_msg (IP or status) on the first line

        if (!is_wifi_connected) {
            display_set_second_line("Keypad Locked");
            display_set_third_line("WiFi Connecting...");
            i2c_keypad_init_password_state(); // Reset password state if WiFi disconnects
        } else {
            // WiFi is connected
            if (!password_entered_correctly) {
                display_set_second_line("Enter Password:");
                display_set_third_line(current_password_input); // Show current password input
            } else {
                // WiFi connected and password entered correctly
                // Normal menu display logic (cycled by button or selected by keypad)
                // If a keypad menu was selected, i2c_keypad_process_menu_key already updated the display.
                // If no keypad menu is active, cycle through default displays.
                // For now, we'll rely on the push button to cycle or keypad to select a menu.
                // If a menu was just selected via keypad, its content is already on display.
                // If we want a default cycling display after password entry, that logic goes here.
                // For now, let's assume the keypad selection is sticky or button cycles.

                // This switch handles the button-based cycling display when a menu is not actively forced by keypad.
                // We need to ensure this doesn't override a menu selected by the keypad immediately.
                // A simple way is to only cycle if no specific menu was recently selected.
                // However, the current structure has i2c_keypad_process_menu_key directly setting the display.
                // So, this switch will effectively be the "default" display when no keypad key is pressed.

                // If a menu item was selected by keypad, it will show. 
                // If the push button is pressed, it will cycle through these items.
                // If password was just entered, Menu A is shown by i2c_keypad_process_menu_key.
                // This section will take over if the button is pressed or if no keypad interaction occurs for a while (not implemented yet)

                // Let's refine this: if a menu is active (e.g. after keypad press), 
                // the button press should perhaps exit the menu or cycle. 
                // For now, this is the button-cycle display logic.
                // Since the button is removed, this switch now dictates what is shown based on 'cycle_display_state'
                // which is set by the keypad.
                switch (cycle_display_state) {
                    case 0: // DHT22 Sensor Display (Default or after Menu A)
                        display_set_second_line("Menu A: DHT22");
                        display_set_third_line("H:" + String(dht22_get_humidity()) + "% T:" + String(dht22_get_temperature()) + "C");
                        // led_turn_on_green(); // Example: Set LED for Menu A
                        break;
                    case 1: // Watersensor Display (Menu B)
                        display_set_second_line("Menu B: Water");
                        display_set_third_line("Level: " + String(watersensor_get_percentage()) + "%");
                        // led_turn_on_blue(); // Example: Set LED for Menu B
                        break;
                    case 2: // Scale Display (Menu C)
                        display_set_second_line("Menu C: Scale");
                        display_set_third_line("Weight: " + String(scale_current_weight) + "g");
                        // led_turn_on_red(); // Example: Set LED for Menu C
                        break;
                    case 3: // System Display (Menu D)
                        display_set_second_line("Menu D: System");
                        display_set_third_line("Status: OK"); 
                        // Set LED for Menu D if desired
                        break;
                    default:
                        // Default case, could be Menu A or a specific idle screen
                        display_set_second_line("Menu A: DHT22");
                        display_set_third_line("H:" + String(dht22_get_humidity()) + "% T:" + String(dht22_get_temperature()) + "C");
                        break;
                }
            }
        }
        display_refresh();
    } 
    // The .waiting() part of Neotimer is for checking if it's running but not yet done.
    // We only need to act when .done() is true for a periodic timer.
}



