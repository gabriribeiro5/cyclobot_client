#include <Arduino.h>
#include <RTClib.h>
#include "../include/StrategyContext.h"
#include "../include/strategies/BaseStrategy.h"
#include "../include/fsm_tools/config/DeviceParameters.h"
#include "../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../include/fsm_tools/comm/VisualComm.h"
#include "../include/fsm_tools/data/ConfigData.h"
#include "../include/fsm_tools/DataInstances.h"

StrategyContext::StrategyContext(ConfigData *configDataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    return;
}

void StrategyContext::setup(BaseStrategy *simulationStrategyPtr, DataInstances *dataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    simulationStrategyPtr->create_pin_map(dataPtr->configDataPtr, visualCommPtr, rtcPtr);
    simulationStrategyPtr->set_self_diagnosis_parameters(dataPtr->selfDiagnosisDataPtr, visualCommPtr, rtcPtr);
    simulationStrategyPtr->board_setup(dataPtr->configDataPtr, visualCommPtr, rtcPtr);
    simulationStrategyPtr->create_ecosystem_params(dataPtr->ecosystemDataPtr, visualCommPtr, rtcPtr);
}

void StrategyContext::simulate_ecosystem(EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, DataInstances *dataPtr, BaseStrategy *simulationStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    simulationStrategyPtr->simulate_ecosystem(scannerPtr, actuatorPtr, dataPtr, visualCommPtr, rtcPtr);
}

void StrategyContext::change_strategy(BaseStrategy *newStrategyPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
    // get milliseconds + log start
    // parametersPtr->simulationStrategyPtr->exit();
    // parametersPtr->simulationStrategyPtr = newStrategyPtr;
    // parametersPtr->simulationStrategyPtr->enter(parametersPtr, visualCommPtr);
    // log end + execution time
}