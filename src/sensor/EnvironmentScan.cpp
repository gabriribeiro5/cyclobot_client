#include "Arduino.h"
#include "..\..\include\sensor\EnvironmentScan.h"
#include "..\..\include\config\EcosystemParameters.h"
#include "..\..\include\config\PeripheralMapping.h"

void EnvironmentScan::read_aeroponic_garden_inputs(EcosystemParameters *ecosystemParametersPtr, PeripheralMapping *peripheralMappingPtr) {
    // HYDROSTATIC INPUTS
    // --> soil moisture (watermark)
    read_soil_moisture(ecosystemParametersPtr, peripheralMappingPtr->soilMoistureSensor);
    
    // --> water pressure (hydrostatic)
    read_water_pressure(ecosystemParametersPtr);
    
    // ANALOG INPUTS
    // --> temperature
    read_temperature(ecosystemParametersPtr, peripheralMappingPtr->temperatureSensor);
    // --> light
    read_brightness(ecosystemParametersPtr);
    // --> PH
    read_water_ph(ecosystemParametersPtr);
    // --> potentiometers
    read_potentiometer(ecosystemParametersPtr);
    
    // 4-20mA INPUTS
    // --> water level
    read_water_pressure(ecosystemParametersPtr);
    // --> pressure
    read_water_pressure(ecosystemParametersPtr);
    // --> flow rate
    read_flow_rate(ecosystemParametersPtr);
}

void EnvironmentScan::read_soil_moisture(EcosystemParameters *ecosystemParametersPtr, int soilMoistureSensor) {
    if (ecosystemParametersPtr->soilMoistureLimit > analogRead(soilMoistureSensor)) {
        ecosystemParametersPtr->soilIsWet = true;
    }
}

void EnvironmentScan::read_water_pressure(EcosystemParameters *ecosystemParametersPtr) {
    return;
}

void EnvironmentScan::read_temperature(EcosystemParameters *ecosystemParametersPtr, int temperatureSensor) {
    ecosystemParametersPtr->currentTemperature = analogRead(temperatureSensor);
    if (ecosystemParametersPtr->currentTemperature > analogRead(temperatureSensor)) {
        ecosystemParametersPtr->soilIsWet = true;
    }
}

void EnvironmentScan::read_brightness(EcosystemParameters *ecosystemParametersPtr) {
    return;
}

void EnvironmentScan::read_water_ph(EcosystemParameters *ecosystemParametersPtr) {
    return;
}

void EnvironmentScan::read_water_nutrients(EcosystemParameters *ecosystemParametersPtr) {
    return;
}
 
void EnvironmentScan::read_water_level(EcosystemParameters *ecosystemParametersPtr) {
    return;
}

void EnvironmentScan::read_potentiometer(EcosystemParameters *ecosystemParametersPtr) {
    return;
}

void EnvironmentScan::read_air_pressure(EcosystemParameters *ecosystemParametersPtr) {
    return;
}

void EnvironmentScan::read_flow_rate(EcosystemParameters *ecosystemParametersPtr) {
    return;
}