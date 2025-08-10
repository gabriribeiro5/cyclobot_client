#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/sensor/EnvironmentScan.h"
#include "../../../../../../include/actuator/EnvironmentActuator.h"

class GrassWall_WaterFanNutrientsThermoHarvest : public BaseStrategy {
    public:
        GrassWall_WaterFanNutrientsThermoHarvest();
        
        void pin_map() {
            return;
        }

        void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) {
            return;
        }
        
        void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr) {
            /* ********* START ACTUATORS (USE TIMEOUTS) ********* */
            // LATCHING RELAY COMMAND OUTPUTS WITH DRIVERS
            // --> Fan system
            environmentActuatorPtr->fan_system_on(ecosystemParametersPtr);
            // --> Irrigation system
            environmentActuatorPtr->irrigation_system_on(ecosystemParametersPtr);
            
            /* ********* STOP ACTUATORS (USE TIMEOUTS) ********* */
            // --> Fan system
            environmentActuatorPtr->fan_system_off(ecosystemParametersPtr);
            // --> Irrigation system
            environmentActuatorPtr->irrigation_system_off(ecosystemParametersPtr);
            

            /* ********* REMOTE PROCEDURE CALLS ********* */
            // BLUETOOTH || MKR NB 1500 (LTE Cat-M1 / NB-IoT) || WAN 1310 (LoRa / LoRaWAN)
            // --> Trimming system
            environmentActuatorPtr->trim_system_on(ecosystemParametersPtr);
        }
        
        // used by strategyContext.changeStrategy
        void enter(SimStrategy *strategy) {
            return;
        }
        void exit(SimStrategy *strategy) {
            return;
        }
};