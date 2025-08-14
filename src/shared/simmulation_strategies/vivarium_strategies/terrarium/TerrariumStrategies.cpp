#include "../../../../../include/shared/simmulation_strategies/vivarium_strategies/terrarium/TerrariumStrategies.h"

TerrariumStrategies::TerrariumStrategies() {
    lightPtr = new TR_Light();
    lightFanPtr = new TR_LightFan();
    lightFanRainPtr = new TR_LightFanRain();
    lightFanRainThermoPtr = new TR_LightFanRainThermo();
};

TerrariumStrategies::~TerrariumStrategies() {
    delete lightPtr;
    delete lightFanPtr;
    delete lightFanRainPtr;
    delete lightFanRainThermoPtr;
};