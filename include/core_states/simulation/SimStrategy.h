#pragma once
#include "../../config/EcosystemParameters.h"
#include "../../sensor/EcosystemScanner.h"
#include "../../actuator/EcosystemActuator.h"

// Forward declarations
class BaseStrategy;
class EcosystemParameters;
class EcosystemScanner;
class EcosystemActuator;

class SimStrategy {
    public:
        SimStrategy(BaseStrategy *initialStrategyPtr);
        void change_strategy(BaseStrategy *newStrategyPtr);
        void setup();
        void simulate_ecosystem(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr);
    private:
        BaseStrategy *currentStrategyPtr;
};