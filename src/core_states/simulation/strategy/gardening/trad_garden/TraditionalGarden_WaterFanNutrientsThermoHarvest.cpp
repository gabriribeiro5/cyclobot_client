#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/sensor/EnvironmentScan.h"
#include "../../../../../../include/actuator/EnvironmentActuator.h"

class TraditionalGarden_WaterFanNutrientsThermoHarvest : public BaseStrategy {
    public:
        TraditionalGarden_WaterFanNutrientsThermoHarvest();

        void pin_map() {
            return;
        }

        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr){
            return;
        }

        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) {
            return;
        }
        
        // used by strategyContext.changeStrategy
        void enter(SimStrategy *strategy) {
            return;
        }
        void exit(SimStrategy *strategy) {
            return;
        }
};