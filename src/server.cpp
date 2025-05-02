// server.cpp
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "server.h"
#include "component_display.h"
#include "service.h"

// Declare the server object
AsyncWebServer server(80);

// HTML page content
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head><title>ESP32 Async WebServer</title></head>
<body>
  <h1>Aquamichel</h1>
  <p>var1: %VALUE1%</p>
  <p>var2: %VALUE2%</p>
  
    <p>Timer: <span id="current_time">...</span></p>

    <script>
      setInterval(() => {
        fetch("/current_time")
          .then(response => response.text())
          .then(data => {
            document.getElementById("current_time").textContent = data;
          });
      }, 1000);
    </script>
</body>
</html>
)rawliteral";

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
   server.on("/current_time", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(timer_current_time));
  });

  server.begin();
}
