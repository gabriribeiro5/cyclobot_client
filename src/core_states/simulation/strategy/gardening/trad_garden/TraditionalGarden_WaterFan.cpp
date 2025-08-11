#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/sensor/EnvironmentScan.h"
#include "../../../../../../include/actuator/EnvironmentActuator.h"

class TraditionalGarden_WaterFan : public BaseStrategy {
    public:
        TraditionalGarden_WaterFan();
        void pin_map() override;
        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr) override;
        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr) override;
        
        // used by SimStrategy.changeStrategy
        void enter(SimStrategy *strategy) override;
        void exit(SimStrategy *strategy) override;
};