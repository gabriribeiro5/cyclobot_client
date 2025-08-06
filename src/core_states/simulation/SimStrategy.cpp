#include <Arduino.h>
#include "..\include\core_states\simulation\SimStrategy.h"
#include "..\include\config\EcosystemParameters.h"

SimStrategy::SimStrategy(BaseStrategy *initialStrategyPtr) {
    currentStrategyPtr = initialStrategyPtr;
}

void SimStrategy::simulate_environment(EcosystemParameters *param) {
    currentStrategyPtr->simulate_environment(param);
}

void SimStrategy::change_strategy(BaseStrategy *newStrategyPtr) {
    // get milliseconds + log start
    currentStrategyPtr->exit(this);
    currentStrategyPtr = newStrategyPtr;
    currentStrategyPtr->enter(this); // complete this line
    // log end + execution time
}