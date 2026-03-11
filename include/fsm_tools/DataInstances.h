#pragma once
#include "../fsm_tools/data/SelfDiagnosisData.h"
#include "../fsm_tools/data/ConfigData.h"
#include "../fsm_tools/data/EcosystemData.h"

class DataInstances {
    public:
        DataInstances();
        DataInstances(const DataInstances&) = delete;                // forbid copy constructor
        DataInstances& operator=(const DataInstances&) = delete;     // forbid copy assignment
        ~DataInstances();
        
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
        EcosystemData *ecosystemDataPtr;
};