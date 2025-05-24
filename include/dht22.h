// dht22.h
#ifndef DHT22_H
#define DHT22_H

#include <Arduino.h>

void dht22_setup();
void dht22_read_values_loop();
float dht22_get_temperature();
float dht22_get_humidity();

extern float current_temperature;
extern float current_humidity;

#endif
