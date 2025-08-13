#include "../../../../../include/shared/simmulation_strategies/habitat_strategies/home_room/HomeRoomStrategies.h"

HomeRoomStrategies::HomeRoomStrategies() {
    lightPtr = new Light();
    lightFanPtr = new LightFan();
    lightFanThermoPtr = new LightFanThermo();
    lightFanThermoHumidifierPtr = new LightFanThermoHumidifier();
    lightFanThermoHumidifierPlayerPtr = new LightFanThermoHumidifierPlayer();
};