#pragma once
#include "../../fsm_tools/config/BaseMapping.h"
#include "../../fsm_tools/comm/VisualComm.h"
#include "../../fsm_tools/data/ConfigData.h"

class EcosystemActuator {
    public:
        void increase_water_nutrients(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void dilute_water_nutrients(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void fan_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void fan_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void irrigation_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void irrigation_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void trim_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void trim_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr);
};