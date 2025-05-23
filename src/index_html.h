#ifndef INDEX_HTML_H
#define INDEX_HTML_H

// Main Index Page
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Aquamichel - Main</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; color: #333; }
    header { background-color: #007bff; color: white; padding: 1em 0; text-align: center; }
    nav ul { list-style-type: none; padding: 0; text-align: center; }
    nav ul li { display: inline; margin-right: 20px; }
    nav ul li a { text-decoration: none; color: #007bff; font-size: 1.2em; }
    nav ul li a:hover { text-decoration: underline; }
    .container { padding: 20px; text-align: center; }
  </style>
</head>
<body>
  <header><h1>Aquamichel Control Panel</h1></header>
  <nav>
    <ul>
      <li><a href="/watersensor">Water Sensor</a></li>
      <li><a href="/scale">Scale Value</a></li>
      <li><a href="/timer">Timer Value</a></li>
    </ul>
  </nav>
  <div class="container">
    <p>Welcome to the Aquamichel control panel. Select an option above to view details.</p>
    <!-- Existing script for VALUE1, VALUE2, current_time, current_weight, push_button_state can be removed or adapted later -->
  </div>
</body>
</html>
)rawliteral";

// Water Sensor Page
const char water_sensor_page_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Aquamichel - Water Sensor</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; color: #333; }
    header { background-color: #28a745; color: white; padding: 1em 0; text-align: center; }
    .container { padding: 20px; text-align: center; }
    .container a { color: #007bff; }
  </style>
</head>
<body>
  <header><h1>Water Sensor Details</h1></header>
  <div class="container">
    <p>This page will display water sensor information.</p>
    <p><a href="/">Back to Main Page</a></p>
  </div>
</body>
</html>
)rawliteral";

// Scale Value Page
const char scale_page_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Aquamichel - Scale</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; color: #333; }
    header { background-color: #ffc107; color: white; padding: 1em 0; text-align: center; }
    .container { padding: 20px; text-align: center; }
    .container a { color: #007bff; }
  </style>
</head>
<body>
  <header><h1>Scale Value Details</h1></header>
  <div class="container">
    <p>This page will display scale value information.</p>
    <p><a href="/">Back to Main Page</a></p>
  </div>
</body>
</html>
)rawliteral";

// Timer Value Page
const char timer_page_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Aquamichel - Timer</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; color: #333; }
    header { background-color: #17a2b8; color: white; padding: 1em 0; text-align: center; }
    .container { padding: 20px; text-align: center; }
    .container a { color: #007bff; }
  </style>
</head>
<body>
  <header><h1>Timer Value Details</h1></header>
  <div class="container">
    <p>This page will display timer value information.</p>
    <p><a href="/">Back to Main Page</a></p>
  </div>
</body>
</html>
)rawliteral";

#endif