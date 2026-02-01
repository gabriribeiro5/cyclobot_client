#include "../include/fsm_tools/DataInstances.h"
#include "../include/fsm_tools/data/SelfDiagnosisData.h"
#include "../include/fsm_tools/data/ConfigData.h"

DataInstances::DataInstances() {
    selfDiagnosisDataPtr = new SelfDiagnosisData(524);
    configDataPtr = new ConfigData(524);
};

DataInstances::~DataInstances() {
    delete selfDiagnosisDataPtr;
    delete configDataPtr;
};