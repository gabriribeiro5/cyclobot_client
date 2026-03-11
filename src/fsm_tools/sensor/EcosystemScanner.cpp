#include "Arduino.h"
#include "../../../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/data/ConfigData.h"

void EcosystemScanner::read_soil_moisture(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    ConfigData::Config_Bool soilIsWet = configDataPtr->config_bool("soilIsWet");
    ConfigData::Config_Bool soilMoistureIsOverLimit = configDataPtr->config_bool("soilMoistureIsOverLimit");
    if (configDataPtr->config_int("soilMoistureMinimum").value >
        analogRead(configDataPtr->config_uint8_t("soilMoistureSensor").value) &&
        soilIsWet.name != "")
    {
        soilIsWet.value = true;
        configDataPtr->update_config_bool("soilIsWet", soilIsWet);        
    };
    
    if (configDataPtr->config_int("soilMoistureMaximum").value <
        analogRead(configDataPtr->config_uint8_t("soilMoistureSensor").value) &&
        soilMoistureIsOverLimit.name != "")
    {
        soilMoistureIsOverLimit.value = true;
        configDataPtr->update_config_bool("soilMoistureIsOverLimit", soilMoistureIsOverLimit);        
    };
}

void EcosystemScanner::read_sun_light(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    ConfigData::Config_Bool sunLightAvailable = configDataPtr->config_bool("sunLightAvailable");
    if (configDataPtr->config_int("sunLightMinimum").value <=
        analogRead(configDataPtr->config_uint8_t("sunLightSensor").value) &&
        sunLightAvailable.name != "")
    {
        sunLightAvailable.value = true;
        configDataPtr->update_config_bool("sunLightAvailable", sunLightAvailable);        
    };
}

void EcosystemScanner::read_air_humidity(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    ConfigData::Config_Bool airHumidityIsOverLimit = configDataPtr->config_bool("airHumidityIsOverLimit");
    if (configDataPtr->config_int("airHumidityMaximum").value <
        analogRead(configDataPtr->config_uint8_t("airHumiditySensor").value) &&
        airHumidityIsOverLimit.name != "")
    {
        airHumidityIsOverLimit.value = true;
        configDataPtr->update_config_bool("airHumidityIsOverLimit", airHumidityIsOverLimit);        
    };
}
void EcosystemScanner::read_water_pressure(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_temperature(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("   [EcosystemScanner::read_temperature] Checking temperature limits..."));
    visualCommPtr->print_line(F("   [EcosystemScanner::read_temperature] Checking temperature limits... Done."));
    return;
}

void EcosystemScanner::read_brightness(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_water_ph(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_water_nutrients(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_water_level(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_potentiometer(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_air_pressure(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_flow_rate(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}