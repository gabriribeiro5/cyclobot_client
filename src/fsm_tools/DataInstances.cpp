#include "../include/fsm_tools/DataInstances.h"
#include "../include/fsm_tools/data/SelfDiagnosisData.h"
#include "../include/fsm_tools/data/ConfigData.h"

DataInstances::DataInstances() {
    selfDiagnosisDataPtr = new SelfDiagnosisData();
    configDataPtr = new ConfigData();
};

DataInstances::~DataInstances() {
    delete selfDiagnosisDataPtr;
    delete configDataPtr;
};