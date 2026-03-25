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
EcosystemData::Sensor_Bool EcosystemData::sensor_bool(char *name)
{
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        EcosystemData::Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        };
    };
    EcosystemData::Sensor_Bool empty = { nullptr, false, nullptr, 0, false, false, DateTime() };
    return empty;
};
EcosystemData::Sensor_Int EcosystemData::sensor_int(char *name)
{
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        EcosystemData::Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            return item;
        };
    };
    EcosystemData::Sensor_Int empty = { nullptr, 0, nullptr, 0, false, false, DateTime() };
    return empty;
};

/************************ INSERT METHODS ************************/
void EcosystemData::add_parameter(char* type,
                            char *name,
                            int value,
                            char *description,
                            double expected_frequency,
                            RTC_DS1307 *rtcPtr
                        )
{
    if (strcmp(type, "bool") == 0) {
        Sensor_Bool new_bool = {
            name,
            value,
            description,
            expected_frequency,
            true,
            false,
            rtcPtr->now()
        };
        sensor_bool_list.add(new_bool);
    };
    if (strcmp(type, "int") == 0) {
        Sensor_Int new_int = {
            name,
            value,
            description,
            expected_frequency,
            true,
            false,
            rtcPtr->now()
        };
        sensor_int_list.add(new_int);
    };
};

/************************ UPDATE METHODS ************************/
void EcosystemData::update_parameter(char* type,
                            char *name,
                            int value,
                            char *description,
                            double expected_frequency,
                            bool measure_now,
                            bool send_now,
                            RTC_DS1307 *rtcPtr
                        )
{
    if (strcmp(type, "bool") == 0) {
        for (int i = 0; i < sensor_bool_list.size(); i++)
        {
            Sensor_Bool item = sensor_bool_list.get(i);
            if (strcmp(item.name, name) == 0)   // compare string contents
            {
                item.value = value;
                item.description = description;
                item.expected_frequency = expected_frequency;
                item.measure_now = measure_now;
                item.send_now = send_now;
                item.last_update = rtcPtr->now();
                sensor_bool_list.set(i, item);
                return;
            };
        };
    };
    if (strcmp(type, "int") == 0) {
        for (int i = 0; i < sensor_int_list.size(); i++)
        {
            Sensor_Int item = sensor_int_list.get(i);
            if (strcmp(item.name, name) == 0)   // compare string contents
            {
                item.value = value;
                item.description = description;
                item.expected_frequency = expected_frequency;
                item.measure_now = measure_now;
                item.send_now = send_now;
                item.last_update = rtcPtr->now();
                sensor_int_list.set(i, item);
                return;
            };
        };
    };
};

void EcosystemData::set_bool_value(char *name, int value, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.value = value;
            item.last_update = rtcPtr->now();
            item.send_now = true;   // if value is updated, mark to send in next stream
            sensor_bool_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_bool_description(char *name, char *description, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.description = description;
            item.last_update = rtcPtr->now();
            sensor_bool_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_bool_expected_frequency(char *name, double expected_frequency, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.expected_frequency = expected_frequency;
            item.last_update = rtcPtr->now();
            sensor_bool_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_bool_measure_now(char *name, bool measure_now, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.measure_now = measure_now;
            item.last_update = rtcPtr->now();
            sensor_bool_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_bool_send_now(char *name, bool send_now, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_bool_list.size(); i++)
    {
        Sensor_Bool item = sensor_bool_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.send_now = send_now;
            item.last_update = rtcPtr->now();
            sensor_bool_list.set(i, item);
            return;
        };
    };
};

// Linked-lists INT UPDATE methods
void EcosystemData::set_int_value(char *name, int value, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.value = value;
            item.send_now = true;   // if value is updated, mark to send in next stream
            item.last_update = rtcPtr->now();
            sensor_int_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_int_description(char *name, char *description, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.description = description;
            item.last_update = rtcPtr->now();
            sensor_int_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_int_expected_frequency(char *name, double expected_frequency, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.expected_frequency = expected_frequency;
            item.last_update = rtcPtr->now();
            sensor_int_list.set(i, item);
            return;
        };
    };
};

void EcosystemData::set_int_measure_now(char *name, bool measure_now, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.measure_now = measure_now;
            item.last_update = rtcPtr->now();
            sensor_int_list.set(i, item);
            return;
        };
    };
};


void EcosystemData::set_int_send_now(char *name, bool send_now, RTC_DS1307 *rtcPtr) {
    for (int i = 0; i < sensor_int_list.size(); i++)
    {
        Sensor_Int item = sensor_int_list.get(i);
        if (strcmp(item.name, name) == 0)   // compare string contents
        {
            item.send_now = send_now;
            item.last_update = rtcPtr->now();
            sensor_int_list.set(i, item);
            return;
        };
    };
};