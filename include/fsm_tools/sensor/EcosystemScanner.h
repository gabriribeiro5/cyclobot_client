#pragma once
#include "../config/BaseMapping.h"
#include "../comm/VisualComm.h"
#include "../StrategyDataInstances.h"

class EcosystemScanner {
    public:
        void read_soil_moisture(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_sun_light(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_air_humidity(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_water_pressure(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_temperature(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_brightness(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_water_ph(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_water_nutrients(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_potentiometer(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_water_level(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_air_pressure(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void read_flow_rate(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
};