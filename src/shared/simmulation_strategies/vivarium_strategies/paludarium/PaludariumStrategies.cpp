#include "../../../../../include/shared/simmulation_strategies/vivarium_strategies/paludarium/PaludariumStrategies.h"

PaludariumStrategies::PaludariumStrategies() {
    riverPtr = new PL_River();
    riverLightPtr = new PL_RiverLight();
    riverLightFanPtr = new PL_RiverLightFan();
    riverLightFanRainPtr = new PL_RiverLightFanRain();
    riverLightFanRainThermoPtr = new PL_RiverLightFanRainThermo();
};

PaludariumStrategies::~PaludariumStrategies() {
    delete riverPtr;
    delete riverLightPtr;
    delete riverLightFanPtr;
    delete riverLightFanRainPtr;
    delete riverLightFanRainThermoPtr;
};