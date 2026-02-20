#include <Arduino.h>
#include <RTClib.h>
#include "../include/StrategyContext.h"
#include "../include/strategies/BaseStrategy.h"
#include "../include/fsm_tools/config/EcosystemParameters.h"
#include "../include/fsm_tools/config/DeviceParameters.h"
#include "../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../include/fsm_tools/comm/VisualComm.h"
#include "../include/fsm_tools/data/ConfigData.h"

StrategyContext::StrategyContext(ConfigData *configDataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    return;
}

void StrategyContext::setup(BaseStrategy *simulationStrategyPtr, ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    simulationStrategyPtr->enter(configDataPtr, visualCommPtr, rtcPtr);
    simulationStrategyPtr->setup(configDataPtr, visualCommPtr, rtcPtr);
}

void StrategyContext::simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, ConfigData *configDataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    simulationStrategyPtr->simulate_ecosystem(scannerPtr, actuatorPtr, configDataPtr, visualCommPtr, rtcPtr);
}

void StrategyContext::change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    // get milliseconds + log start
    // parametersPtr->simulationStrategyPtr->exit();
    // parametersPtr->simulationStrategyPtr = newStrategyPtr;
    // parametersPtr->simulationStrategyPtr->enter(parametersPtr, visualCommPtr);
    // log end + execution time
}