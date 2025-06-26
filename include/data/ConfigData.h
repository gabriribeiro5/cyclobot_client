#pragma once

class ConfigData {
    public:
        StaticJsonDocument<384> config_Json;
        String config_String;
}