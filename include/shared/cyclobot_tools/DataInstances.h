#pragma once
#include "../../data/SelfDiagnosisData.h"
#include "../../data/ConfigData.h"

class DataInstances {
    public:
        DataInstances();
        
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
};