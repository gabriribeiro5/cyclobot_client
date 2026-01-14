#include "../include/fsm_tools/DataInstances.h"
#include "../include/data/SelfDiagnosisData.h"
#include "../include/data/ConfigData.h"

DataInstances::DataInstances() {
    selfDiagnosisDataPtr = new SelfDiagnosisData();
    configDataPtr = new ConfigData();
};

DataInstances::~DataInstances() {
    delete selfDiagnosisDataPtr;
    delete configDataPtr;
};