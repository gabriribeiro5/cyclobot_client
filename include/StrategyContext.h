#pragma once
#include <RTClib.h>
#include "fsm_tools/sensor/EcosystemScanner.h"
#include "fsm_tools/actuator/EcosystemActuator.h"
#include "fsm_tools/comm/VisualComm.h"
#include "fsm_tools/data/ConfigData.h"
#include "fsm_tools/DataInstances.h"

// Forward declarations
class BaseStrategy;
class StrategyParameters;
class EcosystemScanner;
class EcosystemActuator;

class StrategyContext {
    public:
        bool standBy;                       // deactivate actuators; 1 = deactivate (mainteinance)
        DateTime eventStart;                // microsseconds
        DateTime eventEnd;                  // microsseconds
        StrategyContext(ConfigData *configDataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void setup(BaseStrategy *simulationStrategyPtr, DataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, DataInstances *dataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
};