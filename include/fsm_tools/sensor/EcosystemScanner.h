#pragma once
#include "../config/EcosystemParameters.h"
#include "../config/BaseMapping.h"
#include "../comm/VisualComm.h"
#include "../data/ConfigData.h"

class EcosystemScanner {
    public:
        void read_soil_moisture(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_water_pressure(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_temperature(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_brightness(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_water_ph(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_water_nutrients(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_potentiometer(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_water_level(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_air_pressure(ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void read_flow_rate(ConfigData *configDataPtr, VisualComm *visualCommPtr);
};