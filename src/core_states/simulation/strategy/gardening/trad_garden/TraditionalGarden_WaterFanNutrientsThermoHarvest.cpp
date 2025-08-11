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

        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr){
            return;
        }

        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EcosystemScanner *environmentScanPtr, EcosystemActuator *environmentActuatorPtr) {
            return;
        }
        
        // used by SimStrategy.changeStrategy
        void enter(SimStrategy *strategy) {
            return;
        }
        void exit(SimStrategy *strategy) {
            return;
        }
};