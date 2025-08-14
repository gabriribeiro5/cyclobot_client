#pragma once
#include "../../../../core_states/simulation/strategy/vivarium/aquarium/AQ_Light.h"
#include "../../../../core_states/simulation/strategy/vivarium/aquarium/AQ_LightNutrient.h"
#include "../../../../core_states/simulation/strategy/vivarium/aquarium/AQ_LightNutrientThermo.h"

class AquariumStrategies {
    public:
        AquariumStrategies();
        
        AQ_Light *lightPtr;
        AQ_LightNutrient *lightFanPtr;
        AQ_LightNutrientThermo *lightFanRainPtr;
};