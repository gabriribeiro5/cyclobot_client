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

void StreamableData::setup_add(char* type, char *name, bool value, char *description, bool is_pin_value, bool user_can_see, bool updated_by, DateTime last_update) {
    if (type == "bool") {
        Setup_Bool new_bool = {
            name,
            value,
            description,                 // data description (for final user - not admin or server)
            is_pin_value,                 // default = false
            user_can_see,                 // default = true
            updated_by,                   // default = 0 (server communication); 1 = (user communication)
            last_update
        };
    };
    if (type == "int") {
        Setup_Int new_int = {
            
        };
        setup_ints.add(new_int);
    }
    if (type == "uint8_t") {
        return;
    }
    // soilIsWet(0),
    // soilMoistureLimit(500),
    // currentTemperature(20),
    // minTemperatureExpected(18),
    // maxTemperatureExpected(22),
    // initialWateringTimeLimit(2000),
    // growthRate(0),
    // decreaseRate(0),
    // wateringTimeLimit(3000),
    // climate(1),
    // sunLightAvailable(1),
    // standBy(0),
    // timeBufferMicroSec(1800000000)
};
void StreamableData::sensor_add(char* type, char *name, int value, char *description, int expected_frequency, bool measure_now, bool send_now, DateTime last_update);