#include <Arduino.h>
#include "../../../../../../include/core_states/simulation/strategy/vivarium/terrarium/TR_LightFanRainThermo.h"
#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/config/DeviceParameters.h"
#include "../../../../../../include/sensor/EcosystemScanner.h"
#include "../../../../../../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../../../../../../include/fsm_tools/comm//VisualComm.h"

/* TERRARIUM */
void TR_LightFanRainThermo::enter() {
    soilMoistureSensor = A0;                // Sensor de umidade do solo pino A0 conectado no A0 do Arduino
    irrigationSystem = A1;                  // Sensor de chuva pino A1 conectado no A1 do Arduino
    relePort = 4;                           // porta de controle do relé conectada no D4 do Arduino
}

/* TERRARIUM */
void TR_LightFanRainThermo::setup(VisualComm *visualCommPtr) {
    pinMode(soilMoistureSensor, INPUT);     // Sensor de umidade do solo - porta A0 é entrada 
    pinMode(irrigationSystem, INPUT);       // Sensor de chuva - porta A1 é entrada 
    pinMode(relePort, OUTPUT);              // Porta de controle do Relé - D4 é saída 
    digitalWrite(relePort, HIGH);           // Mantém relé desligado  
}

/* TERRARIUM */
void TR_LightFanRainThermo::simulate_ecosystem(EcosystemParameters *parametersPtr,
                                                EcosystemScanner *scannerPtr,
                                                EcosystemActuator *actuatorPtr,
                                                VisualComm *visualCommPtr)
{
    // ********* Primary scann *********
    scannerPtr->read_soil_moisture(parametersPtr, visualCommPtr, soilMoistureSensor);

    // ********* Irrigation strategy *********
    if (!parametersPtr->soilIsWet) {
        actuatorPtr->irrigation_system_on(parametersPtr, visualCommPtr, irrigationSystem);
        while (!parametersPtr->soilIsWet)
        {
            scannerPtr->read_soil_moisture(parametersPtr, visualCommPtr, soilMoistureSensor);
        }
        actuatorPtr->irrigation_system_off(parametersPtr, visualCommPtr, irrigationSystem);
    }
}

/* TERRARIUM */
void TR_LightFanRainThermo::exit() {
    return;
}