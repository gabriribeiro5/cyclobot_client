#pragma once
#include "../fsm_tools/data/SelfDiagnosisData.h"
#include "../fsm_tools/data/ConfigData.h"

class DataInstances {
    public:
        DataInstances();
        ~DataInstances();
        
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
};