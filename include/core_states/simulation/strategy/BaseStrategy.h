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

class BaseStrategy {
    public:
        virtual ~BaseStrategy();
        virtual void pin_map();
        virtual void read_environment_data(EcosystemParameters *param);
        virtual void simulate_environment(EcosystemParameters *param);
        
        // used by strategyContext.changeStrategy
        virtual void enter(SimStrategy *strategy);
        virtual void exit(SimStrategy *strategy);
};