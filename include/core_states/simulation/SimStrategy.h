#pragma once
#include "strategy/BaseStrategy.h"

class SimStrategy {
    public:
        SimStrategy(BaseStrategy *initialStrategyPtr);
        void change_strategy(BaseStrategy *newStrategyPtr);
        void simulate_environment(EcosystemParameters *param);
    private:
        BaseStrategy *currentStrategyPtr;
};