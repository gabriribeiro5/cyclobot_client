#pragma once
#include "data/SelfDiagnosisData.h"
#include "data/ConfigData.h"
#include "data/EcosystemData.h"

class StrategyDataInstances {
    public:
        StrategyDataInstances();
        StrategyDataInstances(const StrategyDataInstances&) = delete;                // forbid copy constructor
        StrategyDataInstances& operator=(const StrategyDataInstances&) = delete;     // forbid copy assignment
        ~StrategyDataInstances();
        
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
        EcosystemData *ecosystemDataPtr;
};