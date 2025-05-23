#ifndef COMPONENT_DISPLAY_H
#define COMPONENT_DISPLAY_H
#include <Wire.h>
extern String display_first_line;
extern String display_second_line;
extern String display_third_line;

void display_setup();
void display_refresh();    
#endif