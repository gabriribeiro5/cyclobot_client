#pragma once
#include "../../data/SelfDiagnosisData.h"
#include "../../data/ConfigData.h"

class DataInstances {
    public:
        DataInstances();
        ~DataInstances();
        
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
};