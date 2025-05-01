// server.cpp
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "server.h"
#include "component_display.h"

// Declare the server object
AsyncWebServer server(80);

// HTML page content
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head><title>ESP32 Async WebServer</title></head>
<body>
  <h1>Hello from ESP32 Async Server!</h1>
</body>
</html>
)rawliteral";

// Optional template processor
String processor(const String& var) {
  return String();
}

// Start Wi-Fi and initialize the web server
void startWiFiAndServer(const char* ssid, const char* password) {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    display_first_line = WiFi.localIP().toString();

  // Define server routes
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html, processor);
  });

  server.begin();
}
