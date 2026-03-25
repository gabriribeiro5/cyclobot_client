#pragma once
#include <LinkedList.h>
#include <RTCLib.h>

class EcosystemData {
    public:
        EcosystemData();
        // Create SENSOR structs
        struct Sensor_Bool {
            char *name;
            bool value;
            char *description;                 // data description (for final user - not admin or server)
            double expected_frequency;         // measurements per sec (Hz) used by stream_sensors_data();
            bool measure_now;                  // used by stream_sensors_data();
            bool send_now;                     // used by stream_sensors_data();
            DateTime last_update;
        };
        struct Sensor_Int {
            char *name;
            int value;
            char *description;                 // data description (for final user - not admin or server)
            double expected_frequency;         // measurements per sec (Hz) used by stream_sensors_data();
            bool measure_now;                  // used by stream_sensors_data();
            bool send_now;                     // used by stream_sensors_data();
            DateTime last_update;
        };

        // Create linked-lists struct
        LinkedList<Sensor_Bool> sensor_bool_list;
        LinkedList<Sensor_Int> sensor_int_list;
        
        /**
         * @brief JSON serialization buffer for sensor data
         * @details Transient JSON documents are allocated on-demand when needed,
         * then freed after use to optimize SRAM usage.
         */
        static const size_t SENSOR_JSON_CAPACITY = 256;
        char sensorData_Char[SENSOR_JSON_CAPACITY];  // char array to hold serialized JSON
        
        // Linked-lists SEARCH methods
        Sensor_Bool sensor_bool(char *name);
        Sensor_Int sensor_int(char *name);
        
        // Linked-lists INSERTITION methods
        void add_parameter(char* type, char *name, int value, char *description, double expected_frequency, RTC_DS1307 *rtcPtr);
        void update_parameter(char* type, char *name, int value, char *description, double expected_frequency, bool measure_now, bool send_now, RTC_DS1307 *rtcPtr);
        
        // Linked-lists BOOL UPDATE methods
        void set_bool_value(char *name, int value, RTC_DS1307 *rtcPtr);
        void set_bool_description(char *name, char *description, RTC_DS1307 *rtcPtr);
        void set_bool_expected_frequency(char *name, double expected_frequency, RTC_DS1307 *rtcPtr);
        void set_bool_measure_now(char *name, bool measure_now, RTC_DS1307 *rtcPtr);
        void set_bool_send_now(char *name, bool send_now, RTC_DS1307 *rtcPtr);
        
        // Linked-lists INT UPDATE methods
        void set_int_value(char *name, int value, RTC_DS1307 *rtcPtr);
        void set_int_description(char *name, char *description, RTC_DS1307 *rtcPtr);
        void set_int_expected_frequency(char *name, double expected_frequency, RTC_DS1307 *rtcPtr);
        void set_int_measure_now(char *name, bool measure_now, RTC_DS1307 *rtcPtr);
        void set_int_send_now(char *name, bool send_now, RTC_DS1307 *rtcPtr);
};