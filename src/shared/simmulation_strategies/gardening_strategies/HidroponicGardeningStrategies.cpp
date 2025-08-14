#include "../../../../include/shared/simmulation_strategies/gardening_strategies/HidroponicGardeningStrategies.h"

HidroponicGardeningStrategies::HidroponicGardeningStrategies() {
    waterPtr = new HG_Water();
    waterFanPtr = new HG_WaterFan();
    waterFanLightPtr = new HG_WaterFanLight();
    waterFanLightNutrientPtr = new HG_WaterFanLightNutrient();
    waterFanLightNutrientThermoPtr = new HG_WaterFanLightNutrientThermo();
};

HidroponicGardeningStrategies::~HidroponicGardeningStrategies() {
    delete waterPtr;
    delete waterFanPtr;
    delete waterFanLightPtr;
    delete waterFanLightNutrientPtr;
    delete waterFanLightNutrientThermoPtr;
};