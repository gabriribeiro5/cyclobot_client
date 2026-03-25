#pragma once
#include "../../BaseStrategy.h"
#include "../../../fsm_tools/data/EcosystemData.h"
#include "../../../fsm_tools/config/DeviceParameters.h"
#include "../../../fsm_tools/sensor/EcosystemScanner.h"
#include "../../../fsm_tools/actuator/EcosystemActuator.h"
#include "../../../fsm_tools/comm/VisualComm.h"
#include "../../../fsm_tools/StrategyDataInstances.h"

class PL_FogLightFan : public BaseStrategy {
    public:
        void create_pin_map(StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) override;
        void set_self_diagnosis_parameters(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) override;
        void board_setup(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) override;
        void set_ecosystem_params(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) override;
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, StrategyDataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) override;
        void exit(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) override;
};