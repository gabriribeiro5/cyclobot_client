#pragma once
#include "../../../core_states/simulation/strategy/gardening/aero_garden/Water.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/WaterFanLightNutrientThermo.h"

class AeroponicGardeningStrategies {
    public:
        AeroponicGardeningStrategies();
        
        Water *waterPtr;
        WaterFan *waterFanPtr;
        WaterFanLight *waterFanLightPtr;
        WaterFanLightNutrient *waterFanLightNutrientPtr;
        WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};