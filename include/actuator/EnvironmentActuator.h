#pragma once
#include "..\..\include\config\EcosystemParameters.h"
#include "..\..\include\config\PeripheralMapping.h"

class EnvironmentActuator {
    public:
        void increase_water_nutrients(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void dilute_water_nutrients(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void fan_system_on(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void fan_system_off(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void irrigation_system_on(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void irrigation_system_off(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void trim_system_on(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
        void trim_system_off(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
};