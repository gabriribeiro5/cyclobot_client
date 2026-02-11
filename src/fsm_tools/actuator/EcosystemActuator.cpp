#include "../../../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../../../../include/fsm_tools/config/BaseMapping.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/data/ConfigData.h"

void EcosystemActuator::increase_water_nutrients(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::dilute_water_nutrients(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::fan_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::fan_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::irrigation_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("  [EcosystemActuator::irrigation_system_on] Turning irrigation system ON..."));
    digitalWrite(configDataPtr->config_uint8_t("irrigationSystem").value, HIGH);
}

void EcosystemActuator::irrigation_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("  [EcosystemActuator::irrigation_system_off] Turning irrigation system OFF..."));
    digitalWrite(configDataPtr->config_uint8_t("irrigationSystem").value, LOW);
}

void EcosystemActuator::trim_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}