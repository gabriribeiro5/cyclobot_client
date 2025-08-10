#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/sensor/EnvironmentScan.h"
#include "../../../../../../include/actuator/EnvironmentActuator.h"

class Aquarium_Nutrients : public BaseStrategy {
    public:
        Aquarium_Nutrients();
        void pin_map() override;
        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) override;
        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) override;
        
        // used by strategyContext.changeStrategy
        void enter(SimStrategy *strategy) override;
        void exit(SimStrategy *strategy) override;
};