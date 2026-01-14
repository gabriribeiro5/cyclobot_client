#include "../include/fsm_tools/ParameterInstances.h"
#include "../include/config/DeviceParameters.h"
#include "../include/config/ErrorHandlingParameters.h"
#include "../include/config/WifiParameters.h"
#include "../include/config/ClientParameters.h"
#include "../include/config/EcosystemParameters.h"
#include "../include/config/BaseMapping.h"
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