#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include <RTClib.h>
#include "../strategy/BaseStrategy.h"
#include "../config/StreamableData.h"

class StrategyParameters {
    public:
        StrategyParameters();
        ~StrategyParameters();
        
        bool standBy;                          // deactivate actuators; 1 = deactivate (mainteinance)
        DateTime eventStart;                   // valor em microsegundos
        
        BaseStrategy *simulationStrategyPtr;
        StreamableData *streamsPtr;

        DateTime eventEnd;                     // valor em microsegundos
        


    };