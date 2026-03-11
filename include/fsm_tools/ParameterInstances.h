#pragma once
#include "../fsm_tools/config/DeviceParameters.h"
#include "../fsm_tools/config/ErrorHandlingParameters.h"
#include "../fsm_tools/config/WifiParameters.h"
#include "../fsm_tools/config/ClientParameters.h"
#include "../fsm_tools/config/BaseMapping.h"

class ParameterInstances {
    public:
        ParameterInstances();
        ParameterInstances(const ParameterInstances&) = delete;                // forbid copy constructor
        ParameterInstances& operator=(const ParameterInstances&) = delete;     // forbid copy assignment
        ~ParameterInstances();
        
        // -> Board Pins
        BaseMapping *BaseMappingPtr;

        // -> Parameters
        DeviceParameters *deviceParametersPtr;
        ErrorHandlingParameters *errorHandlingParametersPtr;
        WifiParameters *wifiParametersPtr;
        ClientParameters *clientParametersPtr;
};