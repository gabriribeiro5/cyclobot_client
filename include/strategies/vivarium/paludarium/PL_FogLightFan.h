#pragma once
#include "../../BaseStrategy.h"
#include "../../../fsm_tools/config/EcosystemParameters.h"
#include "../../../fsm_tools/config/DeviceParameters.h"
#include "../../../sensor/EcosystemScanner.h"
#include "../../../fsm_tools/actuator/EcosystemActuator.h"
#include "../../../fsm_tools/comm/VisualComm.h"

class PL_FogLightFan : public BaseStrategy {
    public:
        void enter(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) override;
        void setup() override;
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr) override;
        void exit() override;    
    private:
        VisualComm *visualCommLocalPtr;
        ConfigData *configDataLocalPtr;
        RTC_DS3231 *rtc;
};