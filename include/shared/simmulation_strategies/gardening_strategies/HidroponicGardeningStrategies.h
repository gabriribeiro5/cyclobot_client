#pragma once
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/Water.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/hidro_garden/WaterFanLightNutrientThermo.h"

class HidroponicGardeningStrategies {
    public:
        HidroponicGardeningStrategies();
        
        Water *waterPtr;
        WaterFan *waterFanPtr;
        WaterFanLight *waterFanLightPtr;
        WaterFanLightNutrient *waterFanLightNutrientPtr;
        WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};