#pragma once
#include "../../BaseStrategy.h"
#include "../../../../../config/EcosystemParameters.h"
#include "../../../../../config/PeripheralMapping.h"
#include "../../../../../sensor/EnvironmentScan.h"
#include "../../../../../actuator/EnvironmentActuator.h"

class AeroponicGarden_WaterFan : public BaseStrategy {
    public:
        AeroponicGarden_WaterFan();
        void pin_map() override;
        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr) override;
        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr) override;
        
        // used by SimStrategy.changeStrategy
        void enter(SimStrategy *strategy) override;
        void exit(SimStrategy *strategy) override;
};