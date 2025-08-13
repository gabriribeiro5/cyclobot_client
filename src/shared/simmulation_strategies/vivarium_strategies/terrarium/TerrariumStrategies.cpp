#include "../../../../../include/shared/simmulation_strategies/vivarium_strategies/terrarium/TerrariumStrategies.h"

TerrariumStrategies::TerrariumStrategies() {
    lightPtr = new Light();
    lightFanPtr = new LightFan();
    lightFanRainPtr = new LightFanRain();
    lightFanRainThermoPtr = new LightFanRainThermo();
};