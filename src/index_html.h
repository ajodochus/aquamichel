#ifndef INDEX_HTML_H
#define INDEX_HTML_H
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head><title>ESP32 Async WebServer</title></head>
<body>
  <h1>Aquamichel</h1>
  <p>var1: %VALUE1%</p>
  <p>var2: %VALUE2%</p>
  
  <p>Timer: <span id="current_time">...</span></p>
  <p>Weight: <span id="current_weight">...</span></p>
  <p>Push Button State: <span id="push_button_state">...</span></p>
  
  <p><a href="/page2">Go to Page 2</a></p> // Link to the new page

    <script>
      setInterval(() => {
        fetch("/current_time")
          .then(response => response.text())
          .then(data => {
            document.getElementById("current_time").textContent = data;
          });
        fetch("/current_weight")
          .then(response => response.text())
          .then(data => {
            document.getElementById("current_weight").textContent = data;
          });
        fetch("/push_button_state")
          .then(response => response.text())
          .then(data => {
            document.getElementById("push_button_state").textContent = data;
          });
      }, 500);
    </script>
</body>
</html>
)rawliteral";

// New HTML for Page 2
const char page2_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Page 2</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
  <h1>hello</h1>
  <p><a href="/">Go to Page 1</a></p>
</body>
</html>
)rawliteral";

#endif