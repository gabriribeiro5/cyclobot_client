#include <Arduino.h>
#include "../../../include/core_states/simulation/SimStrategy.h"
#include "../../../include/config/EcosystemParameters.h"
#include "../../../include/actuator/EnvironmentActuator.h"
#include "../../../include/sensor/EnvironmentScan.h"

SimStrategy::SimStrategy(BaseStrategy *initialStrategyPtr) {
    currentStrategyPtr = initialStrategyPtr;
}

void SimStrategy::simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) {
    currentStrategyPtr->simulate_environment(ecosystemParametersPtr, environmentScanPtr, environmentActuatorPtr);
}

void SimStrategy::change_strategy(BaseStrategy *newStrategyPtr) {
    // get milliseconds + log start
    currentStrategyPtr->exit(this);
    currentStrategyPtr = newStrategyPtr;
    currentStrategyPtr->enter(this); // complete this line
    // log end + execution time
}