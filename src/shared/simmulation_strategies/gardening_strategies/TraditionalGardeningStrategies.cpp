#include "../../../../include/shared/simmulation_strategies/gardening_strategies/TraditionalGardeningStrategies.h"

TraditionalGardeningStrategies::TraditionalGardeningStrategies() {
    waterPtr = new Water();
    waterFanPtr = new WaterFan();
    waterFanLightPtr = new WaterFanLight();
    waterFanLightNutrientPtr = new WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new WaterFanLightNutrientThermo();
};