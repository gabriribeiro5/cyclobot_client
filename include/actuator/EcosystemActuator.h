#pragma once
#include "..\..\include\config\EcosystemParameters.h"
#include "..\..\include\config\PeripheralMapping.h"

class EcosystemActuator {
    public:
        void increase_water_nutrients(EcosystemParameters *ecosystemParametersPtr);
        void dilute_water_nutrients(EcosystemParameters *ecosystemParametersPtr);
        void fan_system_on(EcosystemParameters *ecosystemParametersPtr);
        void fan_system_off(EcosystemParameters *ecosystemParametersPtr);
        void irrigation_system_on(EcosystemParameters *ecosystemParametersPtr, uint8_t relePort);
        void irrigation_system_off(EcosystemParameters *ecosystemParametersPtr, uint8_t relePort);
        void trim_system_on(EcosystemParameters *ecosystemParametersPtr);
        void trim_system_off(EcosystemParameters *ecosystemParametersPtr);
};