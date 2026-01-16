#pragma once
#include <RTClib.h>
#include "fsm_tools/sensor/EcosystemScanner.h"
#include "fsm_tools/actuator/EcosystemActuator.h"
#include "fsm_tools/comm/VisualComm.h"

// Forward declarations
class BaseStrategy;
class EcosystemParameters;
class StrategyParameters;
class EcosystemScanner;
class EcosystemActuator;

class StrategyContext {
    public:
        StrategyContext(BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr);
        void change_strategy(BaseStrategy *newStrategyPtr);
        void setup();
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, RTC_DS3231 *rtc);
    private:
        BaseStrategy *simulationStrategyLocalPtr;
        VisualComm *visualCommLocalPtr;
};