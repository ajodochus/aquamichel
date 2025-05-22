
#ifndef COMPONENT_PUSH_BUTTON_H
#define COMPONENT_PUSH_BUTTON_H
#include <Wire.h>
extern String push_button_state;
extern int cycle_display_state; // 0 for Timer, 1 for Water, 2 for Scale
void component_push_button_setup();
void component_push_button_loop();


#endif