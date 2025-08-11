#include <Arduino.h>
#include "../../../include/core_states/simulation/SimStrategy.h"
#include "../../../include/config/EcosystemParameters.h"
#include "../../../include/config/DeviceParameters.h"
#include "../../../include/actuator/EcosystemActuator.h"
#include "../../../include/sensor/EcosystemScanner.h"

SimStrategy::SimStrategy(BaseStrategy *initialStrategyPtr) {
    currentStrategyPtr = initialStrategyPtr;
    currentStrategyPtr->enter(); // complete this line
}

void SimStrategy::setup() {
    currentStrategyPtr->setup();
}

void SimStrategy::simulate_environment(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr) {
    currentStrategyPtr->simulate_environment(ecosystemParametersPtr, environmentScanPtr, environmentActuatorPtr);
}

void SimStrategy::change_strategy(BaseStrategy *newStrategyPtr) {
    // get milliseconds + log start
    currentStrategyPtr->exit();
    currentStrategyPtr = newStrategyPtr;
    currentStrategyPtr->enter(); // complete this line
    // log end + execution time
}