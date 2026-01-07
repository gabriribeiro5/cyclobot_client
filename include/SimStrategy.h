#pragma once
#include "config/StrategyParameters.h"
#include "sensor/EcosystemScanner.h"
#include "actuator/EcosystemActuator.h"

// Forward declarations
class BaseStrategy;
class EcosystemParameters;
class StrategyParameters;
class EcosystemScanner;
class EcosystemActuator;

class SimStrategy {
    public:
        SimStrategy(StrategyParameters *strategyParameters);
        void change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr);
        void setup(VisualComm *visualCommPtr);
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, VisualComm *visualCommPtr);
    private:
        StrategyParameters *strategyParametersLocalPtr;
};