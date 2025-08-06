#pragma once
#include "..\config\EcosystemParameters.h"
#include "..\config\PeripheralMapping.h"

class EnvironmentScan {
    public:
        void read_aeroponic_garden_inputs(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr);
    
    private:
        void read_soil_moisture(EcosystemParameters *ecosystemParametersPtr, int soilMoistureSensor);
        void read_water_pressure(EcosystemParameters *ecosystemParametersPtr);
        void read_temperature(EcosystemParameters *ecosystemParametersPtr, int temperatureSensor);
        void read_brightness(EcosystemParameters *ecosystemParametersPtr);
        void read_water_ph(EcosystemParameters *ecosystemParametersPtr);
        void read_water_nutrients(EcosystemParameters *ecosystemParametersPtr);
        void read_potentiometer(EcosystemParameters *ecosystemParametersPtr);
        void read_water_level(EcosystemParameters *ecosystemParametersPtr);
        void read_air_pressure(EcosystemParameters *ecosystemParametersPtr);
        void read_flow_rate(EcosystemParameters *ecosystemParametersPtr);
};