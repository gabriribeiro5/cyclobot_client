#pragma once
#include "../../../../core_states/simulation/strategy/vivarium/aquarium/Light.h"
#include "../../../../core_states/simulation/strategy/vivarium/aquarium/LightNutrient.h"
#include "../../../../core_states/simulation/strategy/vivarium/aquarium/LightNutrientThermo.h"

class AquariumStrategies {
    public:
        AquariumStrategies();
        
        Light *lightPtr;
        LightNutrient *lightFanPtr;
        LightNutrientThermo *lightFanRainPtr;
};