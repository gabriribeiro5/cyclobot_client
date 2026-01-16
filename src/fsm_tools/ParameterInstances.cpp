#include "../include/fsm_tools/ParameterInstances.h"
#include "../include/fsm_tools/config/DeviceParameters.h"
#include "../include/fsm_tools/config/ErrorHandlingParameters.h"
#include "../include/fsm_tools/config/WifiParameters.h"
#include "../include/fsm_tools/config/ClientParameters.h"
#include "../include/fsm_tools/config/EcosystemParameters.h"
#include "../include/fsm_tools/config/BaseMapping.h"
#include <Arduino.h>

ParameterInstances::ParameterInstances() {
    // DEBUG
    Serial.println(F("[ParameterInstances::ParameterInstances] creating parameter instances..."));
    Serial.flush();
    
    // -> Board Pins
    BaseMappingPtr = new BaseMapping();
    
    // -> Parameters
    deviceParametersPtr = new DeviceParameters();
    errorHandlingParametersPtr = new ErrorHandlingParameters();
    wifiParametersPtr = new WifiParameters();
    clientParametersPtr = new ClientParameters();
    ecosystemParametersPtr = new EcosystemParameters();
};

ParameterInstances::~ParameterInstances() {
    // -> Board Pins
    delete BaseMappingPtr;

    // -> Parameters
    delete deviceParametersPtr;
    // delete errorHandlingParametersPtr;
    // delete wifiParametersPtr;
    delete clientParametersPtr;
    // delete ecosystemParametersPtr;
};