#pragma once
#include "../fsm_tools/data/SelfDiagnosisData.h"
#include "../fsm_tools/data/ConfigData.h"
#include "../fsm_tools/data/EcosystemData.h"

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