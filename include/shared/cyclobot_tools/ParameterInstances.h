#pragma once
#include "../../config/DeviceParameters.h"
#include "../../config/ErrorHandlingParameters.h"
#include "../../config/WifiParameters.h"
#include "../../config/ClientParameters.h"
#include "../../config/EcosystemParameters.h"
#include "../../config/StrategyParameters.h"
#include "../../config/WifiMapping.h"

class ParameterInstances {
    public:
        ParameterInstances();
        ~ParameterInstances();
        
        // -> Board Pins
        WifiMapping *wifiMappingPtr;

        // -> Parameters
        DeviceParameters *deviceParametersPtr;
        ErrorHandlingParameters *errorHandlingParametersPtr;
        WifiParameters *wifiParametersPtr;
        ClientParameters *clientParametersPtr;
        EcosystemParameters *ecosystemParametersPtr;
        StrategyParameters *strategyParametersPtr;
};