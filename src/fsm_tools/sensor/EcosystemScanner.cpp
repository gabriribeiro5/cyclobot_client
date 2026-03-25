#include "Arduino.h"
#include "../../../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/data/ConfigData.h"

void EcosystemScanner::read_soil_moisture(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    // save soil moisture value in ecosystem data
    dataPtr->ecosystemDataPtr->set_int_value("soilMoisture",
        analogRead(dataPtr->configDataPtr->config_uint8_t("soilMoistureSensor").value),
        rtcPtr
    );

    // check soil moisture limits and update config bools accordingly
    if (dataPtr->configDataPtr->config_int("soilMoistureMinimum").value >
        dataPtr->ecosystemDataPtr->sensor_int("soilMoisture").value &&
        dataPtr->configDataPtr->config_bool("soilIsWet").name != "")
    {
        dataPtr->configDataPtr->set_bool_value("soilIsWet", true, rtcPtr);
    };
    
    if (dataPtr->configDataPtr->config_int("soilMoistureMaximum").value <
        dataPtr->ecosystemDataPtr->sensor_int("soilMoisture").value &&
        dataPtr->configDataPtr->config_bool("soilMoistureIsOverLimit").name != "")
    {
        dataPtr->configDataPtr->set_bool_value("soilMoistureIsOverLimit", true, rtcPtr);
    };
}

void EcosystemScanner::read_sun_light(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    // save sun light value in ecosystem data
    dataPtr->ecosystemDataPtr->set_int_value("sunLight",
        analogRead(dataPtr->configDataPtr->config_uint8_t("sunLightSensor").value),
        rtcPtr
    );

    // check sun light limits and update config bools accordingly
    if (dataPtr->configDataPtr->config_int("sunLightMinimum").value <=
        analogRead(dataPtr->configDataPtr->config_uint8_t("sunLightSensor").value) &&
        dataPtr->configDataPtr->config_bool("sunLightAvailable").name != "")
    {
        dataPtr->configDataPtr->set_bool_value("sunLightAvailable", true, rtcPtr);
    };
}

void EcosystemScanner::read_air_humidity(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    // save air humidity value in ecosystem data
    dataPtr->ecosystemDataPtr->set_int_value("airHumidity",
        analogRead(dataPtr->configDataPtr->config_uint8_t("airHumiditySensor").value),
        rtcPtr
    );

    // check air humidity limits and update config bools accordingly
    if (dataPtr->configDataPtr->config_int("airHumidityMaximum").value <
        analogRead(dataPtr->configDataPtr->config_uint8_t("airHumiditySensor").value) &&
        dataPtr->configDataPtr->config_bool("airHumidityIsOverLimit").name != "")
    {
        dataPtr->configDataPtr->set_bool_value("airHumidityIsOverLimit", true, rtcPtr);
    };
}
void EcosystemScanner::read_water_pressure(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}

void EcosystemScanner::read_temperature(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    visualCommPtr->print_line(F("   [EcosystemScanner::read_temperature] Checking temperature limits..."));
    visualCommPtr->print_line(F("   [EcosystemScanner::read_temperature] Checking temperature limits... Done."));
    return;
}

void EcosystemScanner::read_brightness(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    // save brightness value in ecosystem data
    dataPtr->ecosystemDataPtr->set_int_value("brightness",
        analogRead(dataPtr->configDataPtr->config_uint8_t("brightnessSensor").value),
        rtcPtr
    );
    
    // check brightness limits and update config bools accordingly
    if (dataPtr->configDataPtr->config_int("brightnessMinimum").value <=
        analogRead(dataPtr->configDataPtr->config_uint8_t("brightnessSensor").value) &&
        dataPtr->configDataPtr->config_bool("brightnessIsAboveMinimum").name != "")
    {
        dataPtr->configDataPtr->set_bool_value("brightnessIsAboveMinimum", true, rtcPtr);
    };
}

void EcosystemScanner::read_water_ph(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}

void EcosystemScanner::read_water_nutrients(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}

void EcosystemScanner::read_water_level(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}

void EcosystemScanner::read_potentiometer(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}

void EcosystemScanner::read_air_pressure(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
     return;
    return;
}

void EcosystemScanner::read_flow_rate(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}