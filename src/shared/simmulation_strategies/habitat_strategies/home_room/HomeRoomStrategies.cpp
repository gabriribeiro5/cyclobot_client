#include "../../../../../include/shared/simmulation_strategies/habitat_strategies/home_room/HomeRoomStrategies.h"

HomeRoomStrategies::HomeRoomStrategies() {
    lightPtr = new HR_Light();
    lightFanPtr = new HR_LightFan();
    lightFanThermoPtr = new HR_LightFanThermo();
    lightFanThermoHumidifierPtr = new HR_LightFanThermoHumidifier();
    lightFanThermoHumidifierPlayerPtr = new HR_LightFanThermoHumidifierPlayer();
};