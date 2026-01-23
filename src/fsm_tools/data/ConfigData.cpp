#include "../../../include/fsm_tools/data/ConfigData.h"
#include <LinkedList.h>
#include <RTCLib.h>
ConfigData::ConfigData(size_t capacity)
    : config_Json(capacity)
{
    config_bool_list = LinkedList<Config_Bool>();
    config_int_list = LinkedList<Config_Int>();
    config_uint8_t_list = LinkedList<Config_Uint8_t>();
};

/************************ SEARCH METHODS ************************/
// SETUP
ConfigData::Config_Bool ConfigData::config_bool(char *name)
{
    for (int i = 0; i < config_bool_list.size(); i++)
    {
        Config_Bool item = config_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        };
    };
    // Return a "null" object if not found
    Config_Bool empty = { nullptr, false, nullptr, false, false, false, DateTime() };
    return empty;
};
ConfigData::Config_Int ConfigData::config_int(char *name)
{
    for (int i = 0; i < config_int_list.size(); i++)
    {
        Config_Int item = config_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        }
    }
    // Return a "null" object if not found
    Config_Int empty = { nullptr, false, nullptr, false, false, false, DateTime() };
    return empty;
};
ConfigData::Config_Uint8_t ConfigData::config_uint8_t(char *name)
{
    for (int i = 0; i < config_uint8_t_list.size(); i++)
    {
        Config_Uint8_t item = config_uint8_t_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        }
    }
    // Return a "null" object if not found
    Config_Uint8_t empty = { nullptr, false, nullptr, false, false, false, DateTime() };
    return empty;
};

/************************ INSERT METHODS ************************/
// SETUP
void ConfigData::add_pin(char* type,
                                char *name,
                                bool value,
                                char *description,
                                bool updated_by,
                                DateTime last_update
                            )
{
    if (type == "bool") {
        Config_Bool new_bool = {
            name,
            value,
            description,                              // data description (for final user - not admin or server)
            updated_by,                               // default = 0 (server communication); 1 = (user communication)
            true,                                     // default = false
            false,                                    // default = true
            last_update
        };
        config_bool_list.add(new_bool);
    };
    if (type == "int") {
        Config_Int new_int = {
            name,
            value,
            description,                        // data description (for final user - not admin or server)
            true,                               // default = false
            false,                              // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            last_update
        };
        config_int_list.add(new_int);
    };
    if (type == "uint8_t") {
        Config_Uint8_t new_uint8_t = {
            name = name,
            value = value,
            description,                        // data description (for final user - not admin or server)
            true,                               // default = false
            false,                              // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            last_update
        };
        config_uint8_t_list.add(new_uint8_t);
    };
};

/************************ INSERT METHODS ************************/
// SENSOR
void ConfigData::add_parameter(char* type,
                                char *name,
                                bool value,
                                char *description,
                                bool user_can_see,
                                bool updated_by,
                                DateTime last_update
                            )
{
    if (type == "bool") {
        Config_Bool new_bool = {
            name,
            value,
            description,                        // data description (for final user - not admin or server)
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            false,                              // default = false
            true,                               // default = true
            last_update
        };
        config_bool_list.add(new_bool);
    };
    if (type == "int") {
        Config_Int new_int = {
            name,
            value,
            description,                        // data description (for final user - not admin or server)
            false,                              // default = false
            true,                               // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            last_update
        };
        config_int_list.add(new_int);
    };
    if (type == "uint8_t") {
        Config_Uint8_t new_uint8_t = {
            name = name,
            value = value,
            description,                        // data description (for final user - not admin or server)
            false,                              // default = false
            true,                               // default = true
            updated_by,                         // default = 0 (server communication); 1 = (user communication)
            last_update
        };
        config_uint8_t_list.add(new_uint8_t);
    };
};
