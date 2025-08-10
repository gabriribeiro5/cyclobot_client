#pragma once
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GrassWall_Water.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GrassWall_WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GrassWall_WaterFanNutrients.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GrassWall_WaterFanNutrientsThermo.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GrassWall_WaterFanNutrientsThermoHarvest.h"
#include "../../../core_states/simulation/strategy/gardening/grass_wall/GrassWall_WaterFanNutrientsThermoSeedHarvest.h"

class GrassWallStrategies {
    public:
        GrassWallStrategies();
        
        GrassWall_Water *grassWall_WaterPtr;
        GrassWall_WaterFan *grassWall_WaterFanPtr;
        GrassWall_WaterFanNutrients *grassWall_WaterFanNutrientsPtr;
        GrassWall_WaterFanNutrientsThermo *grassWall_WaterFanNutrientsThermoPtr;
        GrassWall_WaterFanNutrientsThermoHarvest *grassWall_WaterFanNutrientsThermoHarvestPtr;
        GrassWall_WaterFanNutrientsThermoSeedHarvest *grassWall_WaterFanNutrientsThermoSeedHarvestPtr;
};