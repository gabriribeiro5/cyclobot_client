#pragma once
#include <RTClib.h>
#include "fsm_tools/sensor/EcosystemScanner.h"
#include "fsm_tools/actuator/EcosystemActuator.h"
#include "fsm_tools/comm/VisualComm.h"
#include "fsm_tools/data/ConfigData.h"

// Forward declarations
class BaseStrategy;
class EcosystemParameters;
class StrategyParameters;
class EcosystemScanner;
class EcosystemActuator;

class StrategyContext {
    public:
        StrategyContext(ConfigData *configDataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void setup(BaseStrategy *simulationStrategyPtr, ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, ConfigData *configDataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
};