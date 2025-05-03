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
#endif