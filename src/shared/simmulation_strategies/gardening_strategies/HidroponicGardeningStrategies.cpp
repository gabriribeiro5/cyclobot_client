#include "../../../../include/shared/simmulation_strategies/gardening_strategies/HidroponicGardeningStrategies.h"

HidroponicGardeningStrategies::HidroponicGardeningStrategies() {
    waterPtr = new Water();
    waterFanPtr = new WaterFan();
    waterFanLightPtr = new WaterFanLight();
    waterFanLightNutrientPtr = new WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new WaterFanLightNutrientThermo();
};