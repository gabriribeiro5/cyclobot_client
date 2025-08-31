#pragma once
#include "../../config/DeviceParameters.h"
#include "../../config/WifiParameters.h"
#include "../../config/ClientParameters.h"
#include "../../config/EcosystemParameters.h"
#include "../../config/PeripheralMapping.h"

class ParameterInstances {
    public:
        ParameterInstances();
        ~ParameterInstances();
        
        // -> Board Pins
        PeripheralMapping *peripheralMappingPtr;

        // -> Parameters
        DeviceParameters *deviceParametersPtr;
        WifiParameters *wifiParametersPtr;
        ClientParameters *clientParametersPtr;
        EcosystemParameters *ecosystemParametersPtr;
};