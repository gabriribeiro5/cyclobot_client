#pragma once
#include "../../../core_states/simulation/strategy/gardening/trad_garden/Water.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/WaterFanLightNutrientThermo.h"

class TraditionalGardeningStrategies {
    public:
        TraditionalGardeningStrategies();
        
        Water *waterPtr;
        WaterFan *waterFanPtr;
        WaterFanLight *waterFanLightPtr;
        WaterFanLightNutrient *waterFanLightNutrientPtr;
        WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};