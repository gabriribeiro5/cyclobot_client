#pragma once
#include "BaseSimmulation.h"

class RainforestSimmulation : public BaseSimmulation{
    public:
        // --> ECOSYSTEM SENSORS

        // --> ECOSYSTEM ACTUATORS

        // --> USER ITERACTION

        // --> CUSTOM EVENTS
        void TimeBuffer();

        // --> SIMM LOGIC
        void RunSimmulation() override;
}