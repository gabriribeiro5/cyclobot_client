#include "../../../../include/shared/simmulation_strategies/gardening_strategies/AeroponicGardeningStrategies.h"

AeroponicGardeningStrategies::AeroponicGardeningStrategies() {
    waterPtr = new Water();
    waterFanPtr = new WaterFan();
    waterFanLightPtr = new WaterFanLight();
    waterFanLightNutrientPtr = new WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new WaterFanLightNutrientThermo();
};