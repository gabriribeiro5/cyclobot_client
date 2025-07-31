#pragma once
#include <ArduinoJson.h>
#include <SPI.h>

class ConfigData {
    public:
        StaticJsonDocument<384> config_Json;
        char config_Char[384];
};