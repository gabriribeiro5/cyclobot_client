#pragma once
/*
    This interface is NOT meant for <*State.h> files
    It should be implemented in every <*Simulation.h>
    file inside sim directory
    
    This interface contains no .cpp pair file
*/
#include "../SimStrategy.h"
#include "../../../config/EcosystemParameters.h"
#include "../../../sensor/EnvironmentScan.h"
#include "../../../actuator/EnvironmentActuator.h"

class SimStrategy;

class BaseStrategy {
    public:
        virtual ~BaseStrategy();
        virtual void pin_map();
        virtual void read_environment_data(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr);
        virtual void simulate_environment(EcosystemParameters *ecosystemParametersPtr, EnvironmentScan *environmentScanPtr, EnvironmentActuator *environmentActuatorPtr);
        
        // used by strategyContext.changeStrategy
        virtual void enter(SimStrategy *strategy);
        virtual void exit(SimStrategy *strategy);
};