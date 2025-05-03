
#include <Arduino.h>
const int PushButton = 15;
int current_pushbutton_state = LOW;
String push_button_state = "button released";


void component_push_button_setup(){
    pinMode(PushButton, INPUT);
}
void component_push_button_loop(){
    int Push_button_state = digitalRead(PushButton);
    
    if ( Push_button_state == HIGH and current_pushbutton_state == LOW) // Detects the push button press
    {
        current_pushbutton_state = Push_button_state;
        Serial.println("button pressed");
        push_button_state = "button pressed";
    }
    else if (Push_button_state == LOW and current_pushbutton_state == HIGH) // Detects the push button release
    {
        current_pushbutton_state = Push_button_state;
        Serial.println("button released");
        push_button_state = "button released";
    }

}