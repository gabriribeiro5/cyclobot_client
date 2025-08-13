#pragma once
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/River.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/RiverLight.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/RiverLightFan.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/RiverLightFanRain.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/RiverLightFanRainThermo.h"

class PaludariumStrategies {
    public:
        PaludariumStrategies();
        
        River *riverPtr;
        RiverLight *riverLightPtr;
        RiverLightFan *riverLightFanPtr;
        RiverLightFanRain *riverLightFanRainPtr;
        RiverLightFanRainThermo *riverLightFanRainThermoPtr;
};