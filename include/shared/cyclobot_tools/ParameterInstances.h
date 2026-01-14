#pragma once
#include "../../config/DeviceParameters.h"
#include "../../config/ErrorHandlingParameters.h"
#include "../../config/WifiParameters.h"
#include "../../config/ClientParameters.h"
#include "../../config/EcosystemParameters.h"
#include "../../config/BaseMapping.h"

class ParameterInstances {
    public:
        ParameterInstances();
        ~ParameterInstances();
        
        // -> Board Pins
        BaseMapping *BaseMappingPtr;

        // -> Parameters
        DeviceParameters *deviceParametersPtr;
        ErrorHandlingParameters *errorHandlingParametersPtr;
        WifiParameters *wifiParametersPtr;
        ClientParameters *clientParametersPtr;
        EcosystemParameters *ecosystemParametersPtr;
};