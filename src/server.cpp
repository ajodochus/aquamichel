// server.cpp
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h> // Keep if used for other purposes, otherwise can be removed if only for HTML templating
#include "FS.h" // Include FS for SPIFFS
#include "SPIFFS.h" // Include SPIFFS
#include "server.h"
#include "component_display.h"
#include "service.h"
#include "scale.h"
#include "component_push_button.h"
#include "component_display.h"
#include "watersensor.h" // Added include for watersensor functions
// Declare the server object
AsyncWebServer server(80);
String server_msg = "initialize server";

// Optional template processor
String processor(const String& var) {
  if(var == "VALUE1"){
    return String("value1");
  }
  if(var == "VALUE2"){
    return String("value2");
  }
  return String();
}

// Start Wi-Fi and initialize the web server
void startWiFiAndServer(const char* ssid, const char* password) {
  Serial.println("Connecting to WiFi...");
  server_msg = "Connecting to WiFi...";

  WiFi.begin(ssid, password);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  Serial.println("DEBUG: Exited WiFi connection loop"); // DEBUG

  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server_msg = WiFi.localIP().toString();
  Serial.println("DEBUG: Before display_set_first_line (IP Address)"); // DEBUG

  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    server_msg = "SPIFFS Mount Failed";
    display_set_first_line(server_msg);
    display_refresh();
    return;
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/watersensor.html", HTTP_GET, [](AsyncWebServerRequest *request) { 
    request->send(SPIFFS, "/watersensor.html", "text/html");
  });

  server.on("/scale.html", HTTP_GET, [](AsyncWebServerRequest *request) { 
    request->send(SPIFFS, "/scale.html", "text/html");
  });

  server.on("/timer.html", HTTP_GET, [](AsyncWebServerRequest *request) { 
    request->send(SPIFFS, "/timer.html", "text/html");
  });

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  server.on("/current_time", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(service_timer_10s_current));
  });

  server.on("/current_weight", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(scale_current_weight));
  });

  server.on("/current_water_percentage", HTTP_GET, [](AsyncWebServerRequest *request){ 
    request->send(200, "text/plain", String(watersensor_get_percentage()));
  });

  server.on("/push_button_state", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(push_button_state));
  });

  server.begin();
}
