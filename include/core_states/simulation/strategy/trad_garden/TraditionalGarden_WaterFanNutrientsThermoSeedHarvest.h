#pragma once
#include "../BaseStrategy.h"
#include "../../../../config/EcosystemParameters.h"
#include "../../../../config/PeripheralMapping.h"
#include "../../../../sensor/EnvironmentScan.h"
#include "../../../../actuator/EnvironmentActuator.h"

class TraditionalGarden_WaterFanNutrientsThermoSeedHarvest : public BaseStrategy {
    public:
        TraditionalGarden_WaterFanNutrientsThermoSeedHarvest();
        void pin_map();
        void read_environment_data(EcosystemParameters *param) override;
        void simulate_environment(EcosystemParameters *param) override;
        
        // used by strategyContext.changeStrategy
        void enter(SimStrategy *strategy) override;
        void exit(SimStrategy *strategy) override;
};