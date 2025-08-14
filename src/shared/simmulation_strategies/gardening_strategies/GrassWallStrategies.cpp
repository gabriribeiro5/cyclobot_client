#include "../../../../include/shared/simmulation_strategies/gardening_strategies/GrassWallStrategies.h"

GrassWallStrategies::GrassWallStrategies() {
    waterPtr = new GW_Water();
    waterFanPtr = new GW_WaterFan();
    waterFanLightPtr = new GW_WaterFanLight();
    waterFanLightNutrientPtr = new GW_WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new GW_WaterFanLightNutrientThermo();
};

GrassWallStrategies::~GrassWallStrategies() {
    delete waterPtr;
    delete waterFanPtr;
    delete waterFanLightPtr;
    delete waterFanLightNutrientPtr;
    delete waterFanLightNutrientThermoPtr;
};