#pragma once
#include "../fsm_tools/config/EcosystemParameters.h"
#include "../fsm_tools/config/BaseMapping.h"
#include "../fsm_tools/comm/VisualComm.h"

class EcosystemScanner {
    public:
        void read_soil_moisture(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr, uint8_t soilMoistureSensor);
        void read_water_pressure(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_temperature(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr, uint8_t temperatureSensor);
        void read_brightness(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_water_ph(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_water_nutrients(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_potentiometer(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_water_level(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_air_pressure(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
        void read_flow_rate(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr);
};