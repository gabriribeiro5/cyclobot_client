#pragma once
#include "strategy/BaseStrategy.h"
#include "../../config/EcosystemParameters.h"
#include "../../sensor/EnvironmentScan.h"
#include "../../actuator/EnvironmentActuator.h""

// Forward declarations
class BaseStrategy;
class EcosystemParameters;
class EnvironmentScan;
class EnvironmentActuator;

class SimStrategy {
    public:
        SimStrategy(BaseStrategy *initialStrategyPtr);
        void change_strategy(BaseStrategy *newStrategyPtr);
        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr);
    private:
        BaseStrategy *currentStrategyPtr;
};