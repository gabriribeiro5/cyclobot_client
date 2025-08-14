#pragma once
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/HG_Water.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/HG_WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/HG_WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/HG_WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/HG_WaterFanLightNutrientThermo.h"

class HidroponicGardeningStrategies {
    public:
        HidroponicGardeningStrategies();
        
        HG_Water *waterPtr;
        HG_WaterFan *waterFanPtr;
        HG_WaterFanLight *waterFanLightPtr;
        HG_WaterFanLightNutrient *waterFanLightNutrientPtr;
        HG_WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};