#ifndef WATERSENSOR_H
#define WATERSENSOR_H

extern int g_water_level_raw; // Made external
extern float g_water_level_percentage; // Added for percentage

/**
 * @brief Initializes the water sensor.
 * Call this once in your main setup() function.
 */
void watersensor_setup();

void watersensor_get_percentage(); // Added to get the percentage value

#endif // WATERSENSOR_H
