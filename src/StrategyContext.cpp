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

StrategyContext::StrategyContext(BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr) {
    visualCommLocalPtr = visualCommPtr;
    simulationStrategyLocalPtr = simulationStrategyPtr;
    // simulationStrategyLocalPtr->enter(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc);
}

void StrategyContext::setup() {
    visualCommLocalPtr->print_line(F("  [StrategyContext::setup] running..."));
    // parametersPtr->simulationStrategyPtr->setup();
    visualCommLocalPtr->print_line(F("  [StrategyContext::setup] -- done --"));
}

void StrategyContext::simulate_ecosystem(EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr, RTC_DS3231 *rtc) {
    // parametersPtr->simulationStrategyPtr->simulate_ecosystem(environmentScanPtr, environmentActuatorPtr, rtc);
}

void StrategyContext::change_strategy(BaseStrategy *newStrategyPtr) {
    // get milliseconds + log start
    // parametersPtr->simulationStrategyPtr->exit();
    // parametersPtr->simulationStrategyPtr = newStrategyPtr;
    // parametersPtr->simulationStrategyPtr->enter(parametersPtr, visualCommLocalPtr);
    // log end + execution time
}