#ifndef ESPFileSystem_h
#define ESPFileSystem_h

#include "LittleFS.h"

boolean mountFileSystem();
String readFile(String path);

#endif