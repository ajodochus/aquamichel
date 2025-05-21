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

void watersensor_get_percentage() {
    int sensorValue = analogRead(WATERSENSOR_PIN);
    g_water_level_raw = sensorValue;
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