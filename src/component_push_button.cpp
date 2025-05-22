#include <Arduino.h>
#include "component_led.h"
#include "component_push_button.h"
#include "component_display.h"
#include "service.h"
#include "scale.h"
#include "watersensor.h"

const int PushButton = 15;
int current_pushbutton_state = LOW;
String push_button_state = "button released";

static int cycle_display_state = 0; // 0 for Timer, 1 for Water, 2 for Scale

void component_push_button_setup(){
    pinMode(PushButton, INPUT);
    led_turn_on_red();
}
void component_push_button_loop(){
    int Push_button_state_current_read = digitalRead(PushButton); // Renamed to avoid conflict with global
    
    if ( Push_button_state_current_read == HIGH && current_pushbutton_state == LOW) // Detects the rising edge (button press)
    {
        current_pushbutton_state = HIGH;
        Serial.println("Button Pressed - Cycling State");

        cycle_display_state = (cycle_display_state + 1) % 3; // Cycle through 0, 1, 2

        switch (cycle_display_state) {
            case 0: // Timer Display
                push_button_state = "Mode: Timer";
                display_second_line = "Timer: " + String(service_timer_10s_current);
                led_turn_on_green();
                break;
            case 1: // Watersensor Display
                push_button_state = "Mode: Water";
                display_second_line = "Water: " + String(watersensor_get_percentage()) + "%";
                led_turn_on_blue();
                break;
            case 2: // Scale Display
                push_button_state = "Mode: Scale";
                display_second_line = "Weight: " + String(scale_current_weight) + "g";
                led_turn_on_red();
                break;
        }
        display_refresh();
    }
    else if (Push_button_state_current_read == LOW && current_pushbutton_state == HIGH) // Detects the falling edge (button release)
    {
        current_pushbutton_state = LOW;
        Serial.println("Button Released");
        // Values set on press will persist. No changes to LED, display_second_line, or push_button_state here.
    }

}