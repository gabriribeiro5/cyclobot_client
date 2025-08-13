#include "../../../../include/shared/simmulation_strategies/gardening_strategies/GrassWallStrategies.h"

GrassWallStrategies::GrassWallStrategies() {
    waterPtr = new Water();
    waterFanPtr = new WaterFan();
    waterFanLightPtr = new WaterFanLight();
    waterFanLightNutrientPtr = new WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new WaterFanLightNutrientThermo();
};