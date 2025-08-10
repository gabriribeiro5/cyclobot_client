#pragma once
#include "../../BaseStrategy.h"
#include "../../../../../config/EcosystemParameters.h"
#include "../../../../../config/PeripheralMapping.h"
#include "../../../../../sensor/EnvironmentScan.h"
#include "../../../../../actuator/EnvironmentActuator.h"

class TerrariumGarden_WaterFanNutrientsThermoHarvest : public BaseStrategy {
    public:
        TerrariumGarden_WaterFanNutrientsThermoHarvest();
        void pin_map() override;
        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) override;
        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) override;
        
        // used by strategyContext.changeStrategy
        void enter(SimStrategy *strategy) override;
        void exit(SimStrategy *strategy) override;
};