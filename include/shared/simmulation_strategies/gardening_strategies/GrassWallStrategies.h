#pragma once
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GW_Water.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GW_WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GW_WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GW_WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GW_WaterFanLightNutrientThermo.h"

class GrassWallStrategies {
    public:
        GrassWallStrategies();
        
        GW_Water *waterPtr;
        GW_WaterFan *waterFanPtr;
        GW_WaterFanLight *waterFanLightPtr;
        GW_WaterFanLightNutrient *waterFanLightNutrientPtr;
        GW_WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};