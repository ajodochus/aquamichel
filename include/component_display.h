#ifndef COMPONENT_DISPLAY_H
#define COMPONENT_DISPLAY_H
#include <Wire.h>
#include <String.h> // Added for String type

extern String display_first_line;
extern String display_second_line;
extern String display_third_line;

void display_setup();
void display_refresh();
void display_set_first_line(String text); // Declaration added
void display_set_second_line(String text); // Declaration added
void display_set_third_line(String text); // Declaration added

#endif