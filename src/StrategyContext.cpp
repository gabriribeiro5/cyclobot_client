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
    visualCommPtr->print_line(F("  [StrategyContext::StrategyContext] entering StrategyContext..."));
    simulationStrategyPtr->enter(configDataPtr, visualCommPtr, rtcPtr);
}

void StrategyContext::setup(BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    visualCommPtr->print_line(F("  [StrategyContext::setup] running..."));
    // parametersPtr->simulationStrategyPtr->setup();
    visualCommPtr->print_line(F("  [StrategyContext::setup] -- done --"));
}

void StrategyContext::simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    // parametersPtr->simulationStrategyPtr->simulate_ecosystem(environmentScanPtr, environmentActuatorPtr, rtc);
}

void StrategyContext::change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtcPtr) {
    // get milliseconds + log start
    // parametersPtr->simulationStrategyPtr->exit();
    // parametersPtr->simulationStrategyPtr = newStrategyPtr;
    // parametersPtr->simulationStrategyPtr->enter(parametersPtr, visualCommPtr);
    // log end + execution time
}