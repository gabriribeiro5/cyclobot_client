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
#include "../fsm_tools/data/EcosystemData.h"
#include "../fsm_tools/data/LogData.h"
#include "../fsm_tools/data/SelfDiagnosisData.h"
#include "../fsm_tools/StrategyDataInstances.h"
#include "../fsm_tools/sensor/EcosystemScanner.h"
#include "../fsm_tools/actuator/EcosystemActuator.h"

class BaseStrategy {
    public:
        virtual ~BaseStrategy() = default;
        
        virtual void create_pin_map(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) = 0;
        virtual void set_self_diagnosis_parameters(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) = 0;
        virtual void board_setup(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) = 0;
        virtual void set_ecosystem_params(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) = 0;
        virtual void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) = 0;
        virtual void exit(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) = 0;

};