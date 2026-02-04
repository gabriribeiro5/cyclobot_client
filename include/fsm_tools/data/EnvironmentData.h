#pragma once
#include <LinkedList.h>
#include <RTCLib.h>

class EnvironmentData {
    public:
        EnvironmentData();
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
        // LinkedList<Sensor_Bool> sensor_bool_list;
        // LinkedList<Sensor_Int> sensor_int_list;
        
        // Linked-lists SEARCH methods
        Sensor_Bool sensor_bool(char *name);
        Sensor_Int sensor_int(char *name);
        
        // Linked-lists INSERTITION methods
        void add(char* type, char *name, int value, char *description, int expected_frequency, bool measure_now, bool send_now, DateTime last_update);
        void update(char* type, char *name, int value, char *description, int expected_frequency, bool measure_now, bool send_now, DateTime last_update);
};