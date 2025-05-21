#ifndef WATERSENSOR_H
#define WATERSENSOR_H

// If you use specific libraries or have global variables for the water sensor,
// declare them here. For example:
extern int g_water_level_raw; // Made external
extern float g_water_level_percentage; // Added for percentage

/**
 * @brief Initializes the water sensor.
 * Call this once in your main setup() function.
 */
void watersensor_setup();

/**
 * @brief Reads the water sensor and performs periodic tasks like updating g_water_level_raw.
 * Call this in your main loop() or a service loop.
 */
void watersensor_loop();

// You might also want a function to get the current water level, similar to scale_get_weight()
// For example:
int watersensor_get_raw_value(); // Renamed from get_level to be more specific
float watersensor_get_percentage(); // Added to get the percentage value

#endif // WATERSENSOR_H
