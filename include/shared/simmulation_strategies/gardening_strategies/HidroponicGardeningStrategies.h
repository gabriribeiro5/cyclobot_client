#pragma once
#include "../../core_states/simulation/strategy/gardening/hidro_garden/HidroponicGarden_Water.h"
#include "../../core_states/simulation/strategy/gardening/hidro_garden/HidroponicGarden_WaterFan.h"
#include "../../core_states/simulation/strategy/gardening/hidro_garden/HidroponicGarden_WaterFanNutrients.h"
#include "../../core_states/simulation/strategy/gardening/hidro_garden/HidroponicGarden_WaterFanNutrientsThermo.h"
#include "../../core_states/simulation/strategy/gardening/hidro_garden/HidroponicGarden_WaterFanNutrientsThermoHarvest.h"
#include "../../core_states/simulation/strategy/gardening/hidro_garden/HidroponicGarden_WaterFanNutrientsThermoSeedHarvest.h"

class HidroponicGardeningStrategies {
    public:
        HidroponicGardeningStrategies();
        
        HidroponicGarden_Water *hidroponicGarden_WaterPtr;
        HidroponicGarden_WaterFan *hidroponicGarden_WaterFanPtr;
        HidroponicGarden_WaterFanNutrients *hidroponicGarden_WaterFanNutrientsPtr;
        HidroponicGarden_WaterFanNutrientsThermo *hidroponicGarden_WaterFanNutrientsThermoHarvestPtr;
        HidroponicGarden_WaterFanNutrientsThermoHarvest *hidroponicGarden_WaterFanNutrientsThermoSeedHarvestPtr;
};