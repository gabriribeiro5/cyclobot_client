#pragma once
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_Water.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFan.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrients.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrientsThermo.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrientsThermoHarvest.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrientsThermoSeedHarvest.h"

class TraditionalGardeningStrategies {
    public:
        TraditionalGardeningStrategies();
        
        TraditionalGarden_Water *traditionalGarden_WaterPtr;
        TraditionalGarden_WaterFan *TraditionalGarden_WaterFanPtr;
        TraditionalGarden_WaterFanNutrients *TraditionalGarden_WaterFanNutrientsPtr;
        TraditionalGarden_WaterFanNutrientsThermo *TraditionalGarden_WaterFanNutrientsThermoPtr;
        TraditionalGarden_WaterFanNutrientsThermoHarvest *TraditionalGarden_WaterFanNutrientsThermoHarvestPtr;
        TraditionalGarden_WaterFanNutrientsThermoSeedHarvest *TraditionalGarden_WaterFanNutrientsThermoSeedHarvestPtr;
};