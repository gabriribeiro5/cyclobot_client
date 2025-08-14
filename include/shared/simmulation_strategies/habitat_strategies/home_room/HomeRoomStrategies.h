#pragma once
#include "../../../../core_states/simulation/strategy/habitat/home_room/HR_Light.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/HR_LightFan.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/HR_LightFanThermo.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/HR_LightFanThermoHumidifier.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/HR_LightFanThermoHumidifierPlayer.h"

class HomeRoomStrategies {
    public:
        HomeRoomStrategies();
        ~HomeRoomStrategies();
        
        HR_Light *lightPtr;
        HR_LightFan *lightFanPtr;
        HR_LightFanThermo *lightFanThermoPtr;
        HR_LightFanThermoHumidifier *lightFanThermoHumidifierPtr;
        HR_LightFanThermoHumidifierPlayer *lightFanThermoHumidifierPlayerPtr;
};