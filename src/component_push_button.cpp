
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


void component_push_button_setup(){
    pinMode(PushButton, INPUT);
    led_turn_on_red();
}
void component_push_button_loop(){
    int Push_button_state = digitalRead(PushButton);
    
    if ( Push_button_state == HIGH and current_pushbutton_state == LOW) // Detects the push button press
    {
        current_pushbutton_state = Push_button_state;
        Serial.println("button pressed");
        push_button_state = "button pressed";
        led_turn_on_green();
        display_second_line = String(service_timer_10s_current);
        display_refresh();
    }
    else if (Push_button_state == LOW and current_pushbutton_state == HIGH) // Detects the push button release
    {
        current_pushbutton_state = Push_button_state;
        Serial.println("button released");
        push_button_state = "button released";
        led_turn_on_blue();
        display_second_line = String(watersensor_get_percentage()) + "%";
        display_refresh();
    }

}