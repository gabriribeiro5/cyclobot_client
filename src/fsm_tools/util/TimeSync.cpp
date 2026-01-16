#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include "../../../include/fsm_tools/util/TimeSync.h"

int TimeSync::get_current_hour(RTC_DS3231 rtc) {
    DateTime now = rtc.now();
    return now.hour(); // hora real em 24h
}
