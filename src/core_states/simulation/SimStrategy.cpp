#include <Arduino.h>
#include "../../../include/core_states/simulation/SimStrategy.h"
#include "../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../include/config/EcosystemParameters.h"
#include "../../../include/config/DeviceParameters.h"
#include "../../../include/actuator/EcosystemActuator.h"
#include "../../../include/sensor/EcosystemScanner.h"
#include "../../../include/comm/VisualComm.h"

SimStrategy::SimStrategy(BaseStrategy *initialStrategyPtr) {
    currentStrategyPtr = initialStrategyPtr;
    currentStrategyPtr->enter(); // complete this line
}

void SimStrategy::setup(VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("[SimStrategy::setup] running..."));
    currentStrategyPtr->setup(visualCommPtr);
    visualCommPtr->print_line(F("[SimStrategy::setup] -- done --"));
}

void SimStrategy::simulate_ecosystem(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr, VisualComm *visualCommPtr) {
    currentStrategyPtr->simulate_ecosystem(ecosystemParametersPtr, environmentScanPtr, environmentActuatorPtr, visualCommPtr);
}

void SimStrategy::change_strategy(BaseStrategy *newStrategyPtr) {
    // get milliseconds + log start
    currentStrategyPtr->exit();
    currentStrategyPtr = newStrategyPtr;
    currentStrategyPtr->enter(); // complete this line
    // log end + execution time
}