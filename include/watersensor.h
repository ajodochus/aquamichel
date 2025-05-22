#ifndef WATERSENSOR_H
#define WATERSENSOR_H


/**
 * @brief Initializes the water sensor.
 * Call this once in your main setup() function.
 */
void watersensor_setup();

int watersensor_get_percentage(); // Changed to int to match definition in .cpp file

#endif // WATERSENSOR_H
