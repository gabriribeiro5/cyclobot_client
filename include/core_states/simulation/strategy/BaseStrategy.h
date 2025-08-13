#pragma once
/*
    This interface is NOT meant for <*State.h> files
    It should be implemented in every <*Simulation.h>
    file inside sim directory
    
    This interface contains no .cpp pair file
*/
#include "../SimStrategy.h"
#include "../../../config/EcosystemParameters.h"
#include "../../../config/DeviceParameters.h"
#include "../../../sensor/EcosystemScanner.h"
#include "../../../actuator/EcosystemActuator.h"

class BaseStrategy {
    public:
        virtual ~BaseStrategy();
        
        virtual void enter();
        virtual void setup();
        virtual void simulate_ecosystem(EcosystemParameters *ecosystemParamPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr);
        virtual void exit();
};