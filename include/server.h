// server.h
#ifndef SERVER_H
#define SERVER_H

#include <ESPAsyncWebServer.h>

extern AsyncWebServer server;

void startWiFiAndServer(const char* ssid, const char* password);
extern String server_msg;

#endif
