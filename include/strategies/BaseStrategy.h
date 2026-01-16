#pragma once
/*
    This interface is NOT meant for <*State.h> files
    It should be implemented in every <*Simulation.h>
    file inside sim directory
    
    This interface contains no .cpp pair file
*/
#include "../StrategyContext.h"
#include "../fsm_tools/config/DeviceParameters.h"
#include "../fsm_tools/comm/VisualComm.h"
#include "../fsm_tools/data/ConfigData.h"
#include "../fsm_tools/data/EnvironmentData.h"
#include "../fsm_tools/data/LogData.h"
#include "../fsm_tools/data/SelfDiagnosisData.h"
#include "../sensor/EcosystemScanner.h"
#include "../fsm_tools/actuator/EcosystemActuator.h"

class BaseStrategy {
    public:
        virtual ~BaseStrategy() = default;

        bool standBy;                       // deactivate actuators; 1 = deactivate (mainteinance)
        DateTime eventStart;                // microsseconds
        DateTime eventEnd;                  // microsseconds

        
        virtual void enter(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) = 0;
        virtual void setup() = 0;
        virtual void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr) = 0;
        virtual void exit() = 0;
  
    private:
        ConfigData *configDataLocalPtr;
        VisualComm *visualCommLocalPtr;
        RTC_DS3231 *rtc;
};