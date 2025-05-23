#ifndef SCALE_PAGE_HTML_H
#define SCALE_PAGE_HTML_H

#include <Arduino.h> // For PROGMEM

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

#endif
