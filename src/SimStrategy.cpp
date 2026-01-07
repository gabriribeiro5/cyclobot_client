#include <Arduino.h>
#include "../include/SimStrategy.h"
#include "../include/strategy/BaseStrategy.h"
#include "../include/config/EcosystemParameters.h"
#include "../include/config/StrategyParameters.h"
#include "../include/config/DeviceParameters.h"
#include "../include/actuator/EcosystemActuator.h"
#include "../include/sensor/EcosystemScanner.h"
#include "../include/comm/VisualComm.h"

SimStrategy::SimStrategy(StrategyParameters *strategyParameters) {
    strategyParametersLocalPtr = strategyParameters;
    strategyParametersLocalPtr->simulationStrategyPtr->enter(strategyParameters);
}

void SimStrategy::setup(VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("  [SimStrategy::setup] running..."));
    strategyParametersLocalPtr->simulationStrategyPtr->setup(visualCommPtr);
    visualCommPtr->print_line(F("  [SimStrategy::setup] -- done --"));
}

void SimStrategy::simulate_ecosystem(EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr, VisualComm *visualCommPtr) {
    strategyParametersLocalPtr->simulationStrategyPtr->simulate_ecosystem(environmentScanPtr, environmentActuatorPtr, visualCommPtr);
}

void SimStrategy::change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr) {
    // get milliseconds + log start
    strategyParametersLocalPtr->simulationStrategyPtr->exit();
    strategyParametersLocalPtr->simulationStrategyPtr = newStrategyPtr;
    strategyParametersLocalPtr->simulationStrategyPtr->enter(strategyParametersLocalPtr); // complete this line
    // log end + execution time
}