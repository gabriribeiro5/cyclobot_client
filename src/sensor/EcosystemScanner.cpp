#include "Arduino.h"
#include "LinkedList.h"
#include "../../include/sensor/EcosystemScanner.h"
#include "../../include/config/EcosystemParameters.h"
#include "../../include/config/StreamableData.h"
#include "../../include/comm/VisualComm.h"

void EcosystemScanner::read_soil_moisture(StreamableData *streamsPtr, VisualComm *visualCommPtr, uint8_t soilMoistureSensor) {
    if (streamsPtr->setup_int("soilMoistureLimit") > analogRead(soilMoistureSensor)) {
        streamsPtr->setup_int("soilIsWet") = true;
    };
}

void EcosystemScanner::read_water_pressure(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_temperature(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr, uint8_t temperatureSensor) {
    ecosystemParametersPtr->currentTemperature = analogRead(temperatureSensor);
    if (ecosystemParametersPtr->currentTemperature > analogRead(temperatureSensor)) {
        ecosystemParametersPtr->soilIsWet = true;
    }
}

void EcosystemScanner::read_brightness(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_water_ph(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_water_nutrients(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_water_level(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_potentiometer(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_air_pressure(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemScanner::read_flow_rate(EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
    return;
}