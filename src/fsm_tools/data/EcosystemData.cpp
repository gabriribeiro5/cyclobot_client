#include "../../../include/fsm_tools/data/EcosystemData.h"
#include <LinkedList.h>
#include <RTCLib.h>
EcosystemData::EcosystemData()
{
    // sensor_bool_list = LinkedList<Sensor_Bool>();
    // sensor_int_list = LinkedList<Sensor_Int>();
};

/************************ SEARCH METHODS ************************/
// SETUP
EcosystemData::Sensor_Bool *EcosystemData::sensor_bool(char *name)
{
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool *item = sensor_bool_list.getNodeData(i);
        if (item && strcmp(item->name, name) == 0)   // compare string contents
        {
            return item;
        };
    };
    return nullptr;
};
EcosystemData::Sensor_Int *EcosystemData::sensor_int(char *name)
{
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int *item = sensor_int_list.getNodeData(i);
        if (item && strcmp(item->name, name) == 0)   // compare string contents
        {
            return item;
        };
    };
    return nullptr;
};

/************************ INSERT METHODS ************************/
void EcosystemData::add(char* type,
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
        // sensor_bool_list.add(new_bool);
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
        // sensor_int_list.add(new_int);
    };
};

/************************ UPDATE METHODS ************************/