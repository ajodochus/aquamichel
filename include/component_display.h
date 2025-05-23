#ifndef COMPONENT_DISPLAY_H
#define COMPONENT_DISPLAY_H
#include <Wire.h>
extern String display_first_line;
extern String display_second_line;
extern String display_third_line;

void display_set_first_line(String text); // Add this line
void display_set_second_line(String text); // Add this line
void display_set_third_line(String text); // Add this line

void display_setup();
void display_refresh();    
#endif