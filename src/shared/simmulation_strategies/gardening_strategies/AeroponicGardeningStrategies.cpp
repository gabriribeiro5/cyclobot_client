#include "../../../../include/shared/simmulation_strategies/gardening_strategies/AeroponicGardeningStrategies.h"

AeroponicGardeningStrategies::AeroponicGardeningStrategies() {
    waterPtr = new AG_Water();
    waterFanPtr = new AG_WaterFan();
    waterFanLightPtr = new AG_WaterFanLight();
    waterFanLightNutrientPtr = new AG_WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new AG_WaterFanLightNutrientThermo();
};