#include "watersensor.h"
#include <Arduino.h>

const int WATERSENSOR_PIN = 36;

// !!! REPLACE THESE WITH YOUR ACTUAL CALIBRATED VALUES !!!
const int SENSOR_DRY_VALUE = 0; // Example: Lower value when dry
const int SENSOR_WET_VALUE = 4095; // Example: Higher value when wet (typical for capacitive)

int g_water_level_raw = 0;
float watersensor_current_value = 0.0; // Define as a global variable for this file

void watersensor_setup() {
    pinMode(WATERSENSOR_PIN, INPUT);
    Serial.println("Capacitive soil moisture sensor setup. Pin: " + String(WATERSENSOR_PIN));
}

int watersensor_get_percentage() { // Changed return type to int to match header declaration
    int sensorValue = analogRead(WATERSENSOR_PIN);
    g_water_level_raw = sensorValue;
    watersensor_current_value = map(sensorValue, SENSOR_DRY_VALUE, SENSOR_WET_VALUE, 0, 100);
    // Constrain the percentage to be between 0 and 100
    if (watersensor_current_value < 0) {
        watersensor_current_value = 0;
    } else if (watersensor_current_value > 100) {
        watersensor_current_value = 100;
    }

    Serial.print("Soil Moisture Raw: ");
    Serial.print(g_water_level_raw);
    Serial.print(" | Percentage: ");
    Serial.print(watersensor_current_value);
    Serial.println("%");

    return static_cast<int>(watersensor_current_value); // Return int to match declaration
}