#include "../../../../include/shared/simmulation_strategies/gardening_strategies/TraditionalGardeningStrategies.h"

TraditionalGardeningStrategies::TraditionalGardeningStrategies() {
    waterPtr = new TG_Water();
    waterFanPtr = new TG_WaterFan();
    waterFanLightPtr = new TG_WaterFanLight();
    waterFanLightNutrientPtr = new TG_WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new TG_WaterFanLightNutrientThermo();
};

TraditionalGardeningStrategies::~TraditionalGardeningStrategies() {
    delete waterPtr;
    delete waterFanPtr;
    delete waterFanLightPtr;
    delete waterFanLightNutrientPtr;
    delete waterFanLightNutrientThermoPtr;
};