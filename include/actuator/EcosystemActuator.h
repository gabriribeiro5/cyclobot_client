#pragma once
#include "..\..\include\config\EcosystemParameters.h"
#include "..\..\include\config\BaseMapping.h"
#include "..\..\include\comm\VisualComm.h"

class EcosystemActuator {
    public:
        void increase_water_nutrients(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void dilute_water_nutrients(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void fan_system_on(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void fan_system_off(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void irrigation_system_on(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr, uint8_t relayPort);
        void irrigation_system_off(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr, uint8_t relayPort);
        void trim_system_on(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void trim_system_off(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
};