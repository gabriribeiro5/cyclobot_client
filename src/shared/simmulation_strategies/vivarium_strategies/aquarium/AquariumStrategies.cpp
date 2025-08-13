#include "../../../../../include/shared/simmulation_strategies/vivarium_strategies/aquarium/AquariumStrategies.h"

AquariumStrategies::AquariumStrategies() {
    lightPtr = new Light();
    lightFanPtr = new LightNutrient();
    lightFanRainPtr = new LightNutrientThermo();
};