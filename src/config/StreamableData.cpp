#include "../include/config/StreamableData.h"
#include <LinkedList.h>
#include <RTCLib.h>

StreamableData::StreamableData()
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
    setup_ints = LinkedList<Setup_Int>();
    setup_bools = LinkedList<Setup_Bool>();
    setup_uint8_ts = LinkedList<Setup_Uint8_t>();
    sensor_bools = LinkedList<Sensor_Bool>();
    sensor_ints = LinkedList<Sensor_Int>();
};

/************************ SEARCH METHODS ************************/
// SETUP
StreamableData::Setup_Bool StreamableData::setup_bool(char *name)
{
    for (int i = 0; i < sizeof(setup_bool); i++)
    {
        Setup_Bool item = setup_bools.get(i);
        if (item.name == name)
        {
            return item;
        };
    };
    return;
};
StreamableData::Setup_Int StreamableData::setup_int(char *name)
{
    for (int i = 0; i < sizeof(setup_int); i++)
    {
        Setup_Int item = setup_ints.get(i);
        if (item.name == name)
        {
            return item;
        }
    }
    return;
};
StreamableData::Setup_Uint8_t StreamableData::setup_uint8_t(char *name)
{
    for (int i = 0; i < sizeof(setup_uint8_t); i++)
    {
        Setup_Uint8_t item = setup_uint8_ts.get(i);
        if (item.name == name)
        {
            return item;
        }
    }
    return;
};
// SENSOR
StreamableData::Sensor_Bool StreamableData::sensor_bool(char *name)
{
    for (int i = 0; i < sizeof(sensor_bool); i++)
    {
        Sensor_Bool item = sensor_bools.get(i);
        if (item.name == name)
        {
            return item;
        }
    };
    return;
};
StreamableData::Sensor_Int StreamableData::sensor_int(char *name)
{
    for (int i = 0; i < sizeof(sensor_int); i++)
    {
        Sensor_Int item = sensor_ints.get(i);
        if (item.name == name)
        {
            return item;
        }
    };
    return;
};

/************************ INSERT METHODS ************************/
// SETUP
void StreamableData::add_setup_param(char* type,
                                char *name,
                                bool value,
                                char *description,
                                bool is_pin_value,
                                bool user_can_see,
                                bool updated_by,
                                DateTime last_update
                            )
{
    if (type == "bool") {
        Setup_Bool new_bool = {
            name = name,
            value = value,
            description = description,                 // data description (for final user - not admin or server)
            is_pin_value = is_pin_value,               // default = false
            user_can_see = user_can_see,               // default = true
            updated_by = updated_by,                   // default = 0 (server communication); 1 = (user communication)
            last_update = last_update
        };
        setup_bools.add(new_bool);
    };
    if (type == "int") {
        Setup_Int new_int = {
            name = name,
            value = value,
            description = description,                 // data description (for final user - not admin or server)
            is_pin_value = is_pin_value,               // default = false
            user_can_see = user_can_see,               // default = true
            updated_by = updated_by,                   // default = 0 (server communication); 1 = (user communication)
            last_update = last_update
        };
        setup_ints.add(new_int);
    };
    if (type == "uint8_t") {
        Setup_Uint8_t new_uint8_t = {
            name = name,
            value = value,
            description = description,                 // data description (for final user - not admin or server)
            is_pin_value = is_pin_value,               // default = false
            user_can_see = user_can_see,               // default = true
            updated_by = updated_by,                   // default = 0 (server communication); 1 = (user communication)
            last_update = last_update
        };
        setup_uint8_ts.add(new_uint8_t);
    };
};

/************************ INSERT METHODS ************************/
// SENSOR
void StreamableData::add_sensor_param(char* type,
                                char *name,
                                int value,
                                char *description,
                                int expected_frequency,
                                bool measure_now,
                                bool send_now,
                                DateTime last_update
                            )
{
    if (type == "bool") {
        Sensor_Bool new_bool = {
            name = name,
            value = value,
            description = description,                 // data description (for final user - not admin or server)
            expected_frequency = expected_frequency,   // used by stream_sensors_data();
            measure_now = measure_now,                 // used by stream_sensors_data();
            send_now = send_now,                       // used by stream_sensors_data();
            last_update = last_update
        };
        sensor_bools.add(new_bool);
    };
    return;
    if (type == "int") {
        Sensor_Int new_int = {
            name = name,
            value = value,
            description = description,                 // data description (for final user - not admin or server)
            expected_frequency = expected_frequency,   // used by stream_sensors_data();
            measure_now = measure_now,                 // used by stream_sensors_data();
            send_now = send_now,                       // used by stream_sensors_data();
            last_update = last_update
        };
        sensor_ints.add(new_int);
    };
    return;
};
