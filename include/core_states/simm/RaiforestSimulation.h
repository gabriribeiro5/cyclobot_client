#pragma once
#include "BaseSimmulation.h"

class RainforestSimmulation : public BaseSimmulation{
    public:
        // --> ECOSYSTEM SENSORS

        // --> ECOSYSTEM ACTUATORS

        // --> USER ITERACTION

        // --> CUSTOM EVENTS

        // --> SIMM LOGIC
        void RunSimmulation() override;
        
        // Constructor
        void RainforestSimmulation(FiniteStateMachine *cyclobot);
}