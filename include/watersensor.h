#ifndef WATERSENSOR_H
#define WATERSENSOR_H

extern int g_water_level_raw; // Made external
extern float watersensor_current_value; // Changed from g_water_level_percentage to watersensor_current_value

/**
 * @brief Initializes the water sensor.
 * Call this once in your main setup() function.
 */
void watersensor_setup();

void watersensor_get_percentage(); // Added to get the percentage value

#endif // WATERSENSOR_H
