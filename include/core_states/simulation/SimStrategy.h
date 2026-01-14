#pragma once
#include "../../config/EcosystemParameters.h"
#include "../../sensor/EcosystemScanner.h"
#include "../../fsm_tools/actuator/EcosystemActuator.h"

// Forward declarations
class BaseStrategy;
class EcosystemParameters;
class EcosystemScanner;
class EcosystemActuator;

class SimStrategy {
    public:
        SimStrategy(BaseStrategy *initialStrategyPtr);
        void change_strategy(BaseStrategy *newStrategyPtr);
        void setup(VisualComm *visualCommPtr);
        void simulate_ecosystem(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, VisualComm *visualCommPtr);
    private:
        BaseStrategy *currentStrategyPtr;
};