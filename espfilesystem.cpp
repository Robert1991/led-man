#include "ESPFileSystem.h"

boolean mountFileSystem()
{
    if (!LittleFS.begin())
    {
        Serial.println("LittleFS mount failed");
        return false;
    }
    return true;
}

String readFile(const String path)
{
    Serial.println("Reading file: " + path);

    String fileContent = "";
    File file = LittleFS.open(path, "r");
    if (!file)
    {
        Serial.println("Failed to open file for reading");
        return fileContent;
    }
    fileContent = file.readString();

    file.close();
    return fileContent;
}
