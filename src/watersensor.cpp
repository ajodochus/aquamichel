#include "watersensor.h"
#include <Arduino.h>

const int WATERSENSOR_PIN = 36;

// !!! REPLACE THESE WITH YOUR ACTUAL CALIBRATED VALUES !!!
const int SENSOR_DRY_VALUE = 0; // Example: Lower value when dry
const int SENSOR_WET_VALUE = 4095; // Example: Higher value when wet (typical for capacitive)

int g_water_level_raw = 0;
float g_water_level_percentage = 0.0;

void watersensor_setup() {
    pinMode(WATERSENSOR_PIN, INPUT);
    Serial.println("Capacitive soil moisture sensor setup. Pin: " + String(WATERSENSOR_PIN));
}

void watersensor_loop() {
    int sensorValue = analogRead(WATERSENSOR_PIN);
    g_water_level_raw = sensorValue;

    // Map the raw sensor value to a percentage.
    // Note: For capacitive sensors, wet is often a higher value than dry.
    // If your sensor is the opposite, swap SENSOR_DRY_VALUE and SENSOR_WET_VALUE in the map input,
    // or swap 0 and 100 in the map output.
    g_water_level_percentage = map(sensorValue, SENSOR_DRY_VALUE, SENSOR_WET_VALUE, 0, 100);

    // Constrain the percentage to be between 0 and 100
    if (g_water_level_percentage < 0) {
        g_water_level_percentage = 0;
    } else if (g_water_level_percentage > 100) {
        g_water_level_percentage = 100;
    }

    Serial.print("Soil Moisture Raw: ");
    Serial.print(g_water_level_raw);
    Serial.print(" | Percentage: ");
    Serial.print(g_water_level_percentage);
    Serial.println("%");
}

float watersensor_get_percentage() {
    // Option 1: Return the last calculated percentage from watersensor_loop()
    return g_water_level_percentage;

    // Option 2: Perform a fresh read and calculation (more resource-intensive if called frequently)
    /*
    int sensorValue = analogRead(WATERSENSOR_PIN);
    float percentage = map(sensorValue, SENSOR_DRY_VALUE, SENSOR_WET_VALUE, 0, 100);
    if (percentage < 0) percentage = 0;
    if (percentage > 100) percentage = 100;
    return percentage;
    */
}

int watersensor_get_raw_value() {
    return g_water_level_raw; // Or return analogRead(WATERSENSOR_PIN) for an immediate fresh read
}
