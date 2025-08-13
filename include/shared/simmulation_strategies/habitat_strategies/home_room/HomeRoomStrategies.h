#pragma once
#include "../../../../core_states/simulation/strategy/habitat/home_room/Light.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/LightFan.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/LightFanThermo.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/LightFanThermoHumidifier.h"
#include "../../../../core_states/simulation/strategy/habitat/home_room/LightFanThermoHumidifierPlayer.h"

class HomeRoomStrategies {
    public:
        HomeRoomStrategies();
        
        Light *lightPtr;
        LightFan *lightFanPtr;
        LightFanThermo *lightFanThermoPtr;
        LightFanThermoHumidifier *lightFanThermoHumidifierPtr;
        LightFanThermoHumidifierPlayer *lightFanThermoHumidifierPlayerPtr;
};