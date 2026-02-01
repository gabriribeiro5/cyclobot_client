#include "../../../include/fsm_tools/data/EnvironmentData.h"
#include <LinkedList.h>
#include <RTCLib.h>
EnvironmentData::EnvironmentData()
{
    sensor_bool_list = LinkedList<Sensor_Bool>();
    sensor_int_list = LinkedList<Sensor_Int>();
};

/************************ SEARCH METHODS ************************/
// SETUP
EnvironmentData::Sensor_Bool EnvironmentData::sensor_bool(char *name)
{
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        };
    };
    // Return a safe "empty" object if not found
    Sensor_Bool empty = {
        nullptr,        // name
        false,          // value
        nullptr,        // description
        false,          // is_pin_value (or whatever fields you have)
        false,          // user_can_see
        false,          // updated_by
        DateTime()      // last_update
    };
    return empty;
};
EnvironmentData::Sensor_Int EnvironmentData::sensor_int(char *name)
{
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        }
    }
    // Return a safe "empty" object if not found
    Sensor_Int   empty = {
        nullptr,        // name
        false,          // value
        nullptr,        // description
        false,          // is_pin_value (or whatever fields you have)
        false,          // user_can_see
        false,          // updated_by
        DateTime()      // last_update
    };
    return empty;
};

/************************ INSERT METHODS ************************/
void EnvironmentData::add(char* type,
                            char *name,
                            int value,
                            char *description,
                            int expected_frequency,
                            bool measure_now,
                            bool send_now,
                            DateTime last_update
                        )
{
    if (strcmp(type, "bool") == 0) {
        Sensor_Bool new_bool = {
            name,
            value,
            description,
            expected_frequency,
            measure_now,
            send_now,
            last_update
        };
        sensor_bool_list.add(new_bool);
    };
    if (strcmp(type, "int") == 0) {
        Sensor_Int new_int = {
            name,
            value,
            description,
            expected_frequency,
            measure_now,
            send_now,
            last_update
        };
        sensor_int_list.add(new_int);
    };
};

/************************ UPDATE METHODS ************************/