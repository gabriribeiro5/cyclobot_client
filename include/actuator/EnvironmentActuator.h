#pragma once
#include "..\..\include\config\EcosystemParameters.h"
#include "..\..\include\config\PeripheralMapping.h"

class EnvironmentActuator {
    public:
        void increase_water_nutrients(EcosystemParameters *ecosystemParametersPtr);
        void dilute_water_nutrients(EcosystemParameters *ecosystemParametersPtr);
        void fan_system_on(EcosystemParameters *ecosystemParametersPtr);
        void fan_system_off(EcosystemParameters *ecosystemParametersPtr);
        void irrigation_system_on(EcosystemParameters *ecosystemParametersPtr);
        void irrigation_system_off(EcosystemParameters *ecosystemParametersPtr);
        void trim_system_on(EcosystemParameters *ecosystemParametersPtr);
        void trim_system_off(EcosystemParameters *ecosystemParametersPtr);
};