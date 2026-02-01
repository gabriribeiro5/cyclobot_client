#pragma once
#include "../../BaseStrategy.h"
#include "../../../fsm_tools/config/EcosystemParameters.h"
#include "../../../fsm_tools/config/DeviceParameters.h"
#include "../../../fsm_tools/sensor/EcosystemScanner.h"
#include "../../../fsm_tools/actuator/EcosystemActuator.h"
#include "../../../fsm_tools/comm/VisualComm.h"

class PL_FogLightFan : public BaseStrategy {
    public:
        void enter(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) override;
        void setup(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) override;
        void simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) override;
        void exit(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) override;
};