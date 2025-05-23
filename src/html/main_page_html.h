#ifndef MAIN_PAGE_HTML_H
#define MAIN_PAGE_HTML_H

#include <Arduino.h> // For PROGMEM

const char main_page_html[] PROGMEM = R"rawliteral(
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
  </div>
</body>
</html>
)rawliteral";

#endif
