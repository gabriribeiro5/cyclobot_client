#pragma once
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/TR_Light.h"
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/TR_LightFan.h"
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/TR_LightFanRain.h"
#include "../../../../core_states/simulation/strategy/vivarium/terrarium/TR_LightFanRainThermo.h"

class TerrariumStrategies {
    public:
        TerrariumStrategies();
        
        TR_Light *lightPtr;
        TR_LightFan *lightFanPtr;
        TR_LightFanRain *lightFanRainPtr;
        TR_LightFanRainThermo *lightFanRainThermoPtr;
};