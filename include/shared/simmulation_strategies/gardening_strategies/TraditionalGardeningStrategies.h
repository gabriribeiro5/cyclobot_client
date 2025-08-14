#pragma once
#include "../../../core_states/simulation/strategy/gardening/trad_garden/TG_Water.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/TG_WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/TG_WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/TG_WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/trad_garden/TG_WaterFanLightNutrientThermo.h"

class TraditionalGardeningStrategies {
    public:
        TraditionalGardeningStrategies();
        ~TraditionalGardeningStrategies();
        
        TG_Water *waterPtr;
        TG_WaterFan *waterFanPtr;
        TG_WaterFanLight *waterFanLightPtr;
        TG_WaterFanLightNutrient *waterFanLightNutrientPtr;
        TG_WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};