#pragma once
#include "../../../../include/core_states/simulation/BaseSimulation.h"
#include "../../../../include/Context.h"

class RainforestSimulation : public BaseSimulation{
    public:
        // --> ECOSYSTEM SENSORS

        // --> ECOSYSTEM ACTUATORS

        // --> USER ITERACTION

        // --> CUSTOM EVENTS

        // --> SIMM LOGIC
        void RunSimulation() override;
        
        // Constructor
        RainforestSimulation(FiniteStateMachine *cyclobot);
};