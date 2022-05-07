#ifndef WebServer_h
#define WebServer_h

#include <ESP8266WebServer.h>
#include "ESPFileSystem.h"

const String SIDE_NOT_FOUND = "<!DOCTYPE html>"
                              "<html lang=\"en\">"
                              "<head>"
                              "<meta charset=\"utf-8\">"
                              "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
                              "<title>Nirvana</title>"
                              "</head>"
                              "<body>"
                              "<p>Welcome to Nothing.</p>"
                              "</body>"
                              "</html>";

const String SIDE_BODY = "<!DOCTYPE html>"
                         "<html lang=\"en\">"
                         "<head>"
                         "<meta charset=\"utf-8\">"
                         "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
                         "<title>That's Me</title>"
                         "</head>"
                         "<body>"
                         "<p>Welcome to my inner self.</p>"
                         "</body>"
                         "</html>";

const String SIDE_FOOTER = "</body>"
                           "</html>";

ESP8266WebServer *
configureWebServer();
void handleRoot();
void handleWebServerClient();

void sendToClient(String response);

#endif