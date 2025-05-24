// dht22.cpp
#include "dht22.h"
#include "DHT.h"

#define DHTPIN 13 // Define the pin the DHT22 data pin is connected to
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float current_temperature = 0.0;
float current_humidity = 0.0;

void dht22_setup() {
  dht.begin();
  // Read initial values
  dht22_read_values_loop();
}

void dht22_read_values_loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    // Keep previous valid readings or set to a specific error value
  } else {
    current_humidity = h;
    current_temperature = t;
    /*
    Serial.print("Humidity: ");
    Serial.print(current_humidity);
    Serial.print("%  Temperature: ");
    Serial.print(current_temperature);
    Serial.println(" *C");
    */
  }
}

float dht22_get_temperature() {
  return current_temperature;
}

float dht22_get_humidity() {
  return current_humidity;
}
