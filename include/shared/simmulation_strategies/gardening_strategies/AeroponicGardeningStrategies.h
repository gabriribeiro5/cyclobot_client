#pragma once
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_Water.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFan.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrients.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrientsThermo.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrientsThermoHarvest.h"
#include "../../core_states/simulation/strategy/gardening/trad_garden/TraditionalGarden_WaterFanNutrientsThermoSeedHarvest.h"

class AeroponicGardeningStrategies {
    public:
        AeroponicGardeningStrategies();

        TraditionalGarden_Water *traditionalGarden_WaterPtr;
        TraditionalGarden_WaterFan *traditionalGarden_WaterFanPtr;
        TraditionalGarden_WaterFanNutrients *traditionalGarden_WaterFanNutrientsPtr;
        TraditionalGarden_WaterFanNutrientsThermo *traditionalGarden_WaterFanNutrientsThermoPtr;
        TraditionalGarden_WaterFanNutrientsThermoHarvest *traditionalGarden_WaterFanNutrientsThermoHarvestPtr;
        TraditionalGarden_WaterFanNutrientsThermoSeedHarvest *traditionalGarden_WaterFanNutrientsThermoSeedHarvestPtr;
};