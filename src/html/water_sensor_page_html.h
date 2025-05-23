#ifndef WATER_SENSOR_PAGE_HTML_H
#define WATER_SENSOR_PAGE_HTML_H

#include <Arduino.h> // For PROGMEM

const char water_sensor_page_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Aquamichel - Water Sensor</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; color: #333; }
    header { background-color: #28a745; color: white; padding: 1em 0; text-align: center; }
    .container { padding: 20px; text-align: center; font-size: 1.2em; }
    .value { font-weight: bold; color: #28a745; }
    .container a { color: #007bff; }
  </style>
</head>
<body>
  <header><h1>Water Sensor Details</h1></header>
  <div class="container">
    <p>Current Water Level: <span id="waterValue" class="value"></span>%</p>
    <p><a href="/">Back to Main Page</a></p>
  </div>
  <script>
    setInterval(function() {
      var xhr = new XMLHttpRequest();
      xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("waterValue").innerHTML = this.responseText;
        }
      };
      xhr.open("GET", "/current_water_percentage", true);
      xhr.send();
    }, 3000); // Update every 3 seconds
  </script>
</body>
</html>
)rawliteral";

#endif
