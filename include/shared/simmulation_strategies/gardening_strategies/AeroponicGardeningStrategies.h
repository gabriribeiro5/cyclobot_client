#pragma once
#include "../../../core_states/simulation/strategy/gardening/aero_garden/AG_Water.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/AG_WaterFan.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/AG_WaterFanLight.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/AG_WaterFanLightNutrient.h"
#include "../../../core_states/simulation/strategy/gardening/aero_garden/AG_WaterFanLightNutrientThermo.h"

class AeroponicGardeningStrategies {
    public:
        AeroponicGardeningStrategies();
        ~AeroponicGardeningStrategies();
        
        AG_Water *waterPtr;
        AG_WaterFan *waterFanPtr;
        AG_WaterFanLight *waterFanLightPtr;
        AG_WaterFanLightNutrient *waterFanLightNutrientPtr;
        AG_WaterFanLightNutrientThermo *waterFanLightNutrientThermoPtr;
};