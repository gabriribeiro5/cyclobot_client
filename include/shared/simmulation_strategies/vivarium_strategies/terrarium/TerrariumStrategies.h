#pragma once
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/Light.h"
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/LightFan.h"
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/LightFanRain.h"
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/LightFanRainThermo.h"

class TerrariumStrategies {
    public:
        TerrariumStrategies();
        
        Light *lightPtr;
        LightFan *lightFanPtr;
        LightFanRain *lightFanRainPtr;
        LightFanRainThermo *lightFanRainThermoPtr;
};