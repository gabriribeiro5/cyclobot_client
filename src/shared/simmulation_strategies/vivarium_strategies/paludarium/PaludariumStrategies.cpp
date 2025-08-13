#include "../../../../../include/shared/simmulation_strategies/vivarium_strategies/paludarium/PaludariumStrategies.h"

PaludariumStrategies::PaludariumStrategies() {
    riverPtr = new River();
    riverLightPtr = new RiverLight();
    riverLightFanPtr = new RiverLightFan();
    riverLightFanRainPtr = new RiverLightFanRain();
    riverLightFanRainThermoPtr = new RiverLightFanRainThermo();
};