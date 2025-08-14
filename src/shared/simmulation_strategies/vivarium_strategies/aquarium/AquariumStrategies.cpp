#include "../../../../../include/shared/simmulation_strategies/vivarium_strategies/aquarium/AquariumStrategies.h"

AquariumStrategies::AquariumStrategies() {
    lightPtr = new AQ_Light();
    lightFanPtr = new AQ_LightNutrient();
    lightFanRainPtr = new AQ_LightNutrientThermo();
};

AquariumStrategies::~AquariumStrategies() {
    delete lightPtr;
    delete lightFanPtr;
    delete lightFanRainPtr;
};