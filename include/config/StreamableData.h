#pragma once
#include <LinkedList.h>
#include <RTCLib.h>

class StreamableData {
    public:
        StreamableData();
        ~StreamableData();
        /*
        Each Strategy uses different parameters.
        The following structures enable creation of linked-lists,
            allowing, thus, the implementation of controlled stream methods,
            regardless how many parameters are created.
        */

        // Create SETUP structs
        struct Setup_Bool {
            char *name;
            bool value;
            char *description;                 // data description (for final user - not admin or server)
            bool is_pin_value;                 // default = false
            bool user_can_see;                 // default = true
            bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
            DateTime last_update;
        };
        struct Setup_Int {
            char *name;
            bool value;
            char *description;                 // data description (for final user - not admin or server)
            bool is_pin_value;                 // default = false
            bool user_can_see;                 // default = true
            bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
            DateTime last_update;
        };
        struct Setup_Uint8_t {
            char *name;
            uint8_t value;
            char *description;                 // data description (for final user - not admin or server)
            bool is_pin_value;                 // default = false
            bool user_can_see;                 // default = true
            bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
            DateTime last_update;
        };
        
        // Create SENSOR structs
        struct Sensor_Bool {
            char *name;
            bool value;
            char *description;                 // data description (for final user - not admin or server)
            int expected_frequency;            // used by stream_sensors_data();
            bool measure_now;                  // used by stream_sensors_data();
            bool send_now;                     // used by stream_sensors_data();
            DateTime last_update;
        };
        struct Sensor_Int {
            char *name;
            int value;
            char *description;                 // data description (for final user - not admin or server)
            int expected_frequency;            // used by stream_sensors_data();
            bool measure_now;                  // used by stream_sensors_data();
            bool send_now;                     // used by stream_sensors_data();
            DateTime last_update;
        };

        // Create linked-lists struct
        // Every list must end with an 's'
        LinkedList<Setup_Bool> setup_bools;
        LinkedList<Setup_Int> setup_ints;
        LinkedList<Setup_Uint8_t> setup_uint8_ts;
        LinkedList<Sensor_Bool> sensor_bools;
        LinkedList<Sensor_Int> sensor_ints;
        
        // Linked-lists SEARCH methods
        Setup_Bool setup_bool(char *name);
        Setup_Int setup_int(char *name);
        Setup_Uint8_t setup_uint8_t(char *name);
        Sensor_Bool sensor_bool(char *name);
        Sensor_Int sensor_int(char *name);
        
        // Linked-lists INSERTITION methods
        void add_setup_param(char* type, char *name, bool value, char *description, bool is_pin_value, bool user_can_see, bool updated_by, DateTime last_update);
        void add_sensor_param(char* type, char *name, int value, char *description, int expected_frequency, bool measure_now, bool send_now, DateTime last_update);        
    };