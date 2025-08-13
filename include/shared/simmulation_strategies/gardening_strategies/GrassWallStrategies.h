#pragma once
#include "../../../core_states/simulation/strategy/gardening/grass_wall/Water.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/WaterFanLightNutrientThermo.h"

class GrassWallStrategies {
    public:
        GrassWallStrategies();
        
        Water *waterPtr;
        WaterFan *waterFanPtr;
        WaterFanLight *waterFanLightPtr;
        WaterFanLightNutrient *waterFanLightNutrientPtr;
        WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};