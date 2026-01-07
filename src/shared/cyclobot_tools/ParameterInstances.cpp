#include "../../../include/shared/cyclobot_tools/ParameterInstances.h"
#include "../../../include/config/DeviceParameters.h"
#include "../../../include/config/ErrorHandlingParameters.h"
#include "../../../include/config/WifiParameters.h"
#include "../../../include/config/ClientParameters.h"
#include "../../../include/config/EcosystemParameters.h"
#include "../../../include/config/StrategyParameters.h"
#include "../../../include/config/WifiMapping.h"
#include <Arduino.h>

ParameterInstances::ParameterInstances() {
    // DEBUG
    Serial.println(F("[ParameterInstances::ParameterInstances] creating parameter instances..."));
    Serial.flush();
    
    // -> Board Pins
    wifiMappingPtr = new WifiMapping();
    
    // -> Parameters
    deviceParametersPtr = new DeviceParameters();
    errorHandlingParametersPtr = new ErrorHandlingParameters();
    wifiParametersPtr = new WifiParameters();
    clientParametersPtr = new ClientParameters();
    ecosystemParametersPtr = new EcosystemParameters();
    strategyParametersPtr = new StrategyParameters();
};

ParameterInstances::~ParameterInstances() {
    // -> Board Pins
    delete wifiMappingPtr;

    // -> Parameters
    delete deviceParametersPtr;
    // delete errorHandlingParametersPtr;
    // delete wifiParametersPtr;
    delete clientParametersPtr;
    // delete ecosystemParametersPtr;
};