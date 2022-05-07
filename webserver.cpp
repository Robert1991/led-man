#include "WebServer.h"

ESP8266WebServer webServer(80);

ESP8266WebServer *configureWebServer()
{
    webServer.onNotFound([]()
                         { webServer.send(404, "text/html", SIDE_NOT_FOUND); });
    webServer.on("/", handleRoot);
    webServer.begin();
    return &webServer;
}

void handleRoot()
{
    Serial.println("root page called");

    String fileContent = readFile("/test_example.txt");

    Serial.println(fileContent);

    
    sendToClient(SIDE_BODY + "<p>" + fileContent + "</p>" + SIDE_FOOTER);
}

void sendToClient(String response) { webServer.send(200, "text/html", response); }

void handleWebServerClient() { webServer.handleClient(); }
