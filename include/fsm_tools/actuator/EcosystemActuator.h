#pragma once
#include "../../fsm_tools/config/BaseMapping.h"
#include "../../fsm_tools/comm/VisualComm.h"
#include "../../fsm_tools/data/ConfigData.h"

class EcosystemActuator {
    public:
        // Actuator methods for ecosystem control in alphabetical order
        void fan_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void fan_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void fog_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void fog_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void irrigation_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void irrigation_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void light_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void light_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void light_system_pwm(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void trim_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void trim_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void water_nutrients_dilution(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void water_nutrients_increase(ConfigData *configDataPtr, VisualComm *visualCommPtr);
};