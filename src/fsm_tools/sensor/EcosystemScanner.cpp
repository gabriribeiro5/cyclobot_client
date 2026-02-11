#include "Arduino.h"
#include "../../../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../../../include/fsm_tools/config/EcosystemParameters.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/data/ConfigData.h"

void EcosystemScanner::read_soil_moisture(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    ConfigData::Config_Bool soilIsWet = configDataPtr->config_bool("soilIsWet");
    if (configDataPtr->config_int("soilMoistureLimit").value >
        analogRead(configDataPtr->config_uint8_t("soilMoistureSensor").value) &&
        soilIsWet.name != "")
    {
        soilIsWet.value = true;
        configDataPtr->update_config_bool("soilIsWet", soilIsWet);        
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