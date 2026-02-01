#pragma once
#include <ArduinoJson.h>
#include <LinkedList.h>
#include <RTCLib.h>

class ConfigData {
public:
    ConfigData(size_t capacity);
    // Create SETUP structs
    struct Config_Bool {
        char *name;
        bool value;
        char *description;                 // data description (for final user - not admin or server)
        bool is_pin_value;                 // default = false
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        DateTime last_update;
    };
    struct Config_Int {
        char *name;
        int value;
        char *description;                 // data description (for final user - not admin or server)
        bool is_pin_value;                 // default = false
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        DateTime last_update;
    };
    struct Config_Uint8_t {
        char *name;
        uint8_t value;
        char *description;                 // data description (for final user - not admin or server)
        bool is_pin_value;                 // default = false
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        DateTime last_update;
    };

    // Create linked-lists struct
    LinkedList<Config_Bool> config_bool_list;
    LinkedList<Config_Int> config_int_list;
    LinkedList<Config_Uint8_t> config_uint8_t_list;
    
    // Linked-lists SEARCH methods
    Config_Bool *config_bool(char *name);
    Config_Int config_int(char *name);
    Config_Uint8_t config_uint8_t(char *name);

    
    DynamicJsonDocument config_Json;
    char config_Char[sizeof(config_Json)];  // char array to hold serialized JSON
    
    void add_pin(char* type, char *name, bool value, char *description, bool updated_by, DateTime last_update);
    void add_parameter(char* type, char *name, bool value, char *description, bool user_can_see, bool updated_by, DateTime last_update);
    DynamicJsonDocument load_json();

};