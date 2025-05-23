// server.cpp
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "server.h"
#include "component_display.h"
#include "service.h"
#include "index_html.h"
#include "scale.h"
#include "component_push_button.h"
#include "component_display.h"
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

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server_msg = WiFi.localIP().toString();



  // Define server routes
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/page2", HTTP_GET, [](AsyncWebServerRequest *request) { // Added route for /page2
    request->send_P(200, "text/html", page2_html, processor);
  });
   server.on("/current_time", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(service_timer_10s_current));
  });
  server.on("/current_weight", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(scale_current_weight));
  });
  server.on("/push_button_state", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(push_button_state));
  });

  server.begin();
}
