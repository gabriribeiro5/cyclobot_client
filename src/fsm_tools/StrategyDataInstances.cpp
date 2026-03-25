#include "../include/fsm_tools/StrategyDataInstances.h"
#include "../include/fsm_tools/data/SelfDiagnosisData.h"
#include "../include/fsm_tools/data/ConfigData.h"

StrategyDataInstances::StrategyDataInstances() {
    selfDiagnosisDataPtr = new SelfDiagnosisData();
    configDataPtr = new ConfigData();
};

StrategyDataInstances::~StrategyDataInstances() {
    delete selfDiagnosisDataPtr;
    delete configDataPtr;
};