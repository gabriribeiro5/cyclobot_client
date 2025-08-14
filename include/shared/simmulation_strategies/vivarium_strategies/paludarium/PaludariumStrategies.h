#pragma once
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/PL_River.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/PL_RiverLight.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/PL_RiverLightFan.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/PL_RiverLightFanRain.h"
#include "../../../../core_states/simulation/strategy/vivarium/paludarium/PL_RiverLightFanRainThermo.h"

class PaludariumStrategies {
    public:
        PaludariumStrategies();
        ~PaludariumStrategies();
        
        PL_River *riverPtr;
        PL_RiverLight *riverLightPtr;
        PL_RiverLightFan *riverLightFanPtr;
        PL_RiverLightFanRain *riverLightFanRainPtr;
        PL_RiverLightFanRainThermo *riverLightFanRainThermoPtr;
};