#ifndef TIMER_PAGE_HTML_H
#define TIMER_PAGE_HTML_H

#include <Arduino.h> // For PROGMEM

const char timer_page_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Aquamichel - Timer</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; color: #333; }
    header { background-color: #17a2b8; color: white; padding: 1em 0; text-align: center; }
    .container { padding: 20px; text-align: center; font-size: 1.2em; }
    .value { font-weight: bold; color: #17a2b8; }
    .container a { color: #007bff; }
  </style>
</head>
<body>
  <header><h1>Timer Value Details</h1></header>
  <div class="container">
    <p>Current Timer Value: <span id="timerValue" class="value">--</span> seconds</p>
    <p><a href="/">Back to Main Page</a></p>
  </div>
  <script>
    setInterval(function() {
      var xhr = new XMLHttpRequest();
      xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("timerValue").innerHTML = this.responseText;
        }
      };
      xhr.open("GET", "/current_time", true);
      xhr.send();
    }, 1000); // Update every 1 second
  </script>
</body>
</html>
)rawliteral";

#endif
