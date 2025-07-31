#pragma once
#include <RTClib.h>  // ou qual for a biblioteca usada

class TimeSync {
    public:
        int get_current_hour(RTC_DS3231 rtc);
};