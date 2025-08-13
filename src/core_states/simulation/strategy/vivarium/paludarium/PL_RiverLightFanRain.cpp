#include <Arduino.h>
#include "../../../../../../include/core_states/simulation/strategy/vivarium/paludarium/PL_RiverLightFanRain.h"
#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/config/DeviceParameters.h"
#include "../../../../../../include/sensor/EcosystemScanner.h"
#include "../../../../../../include/actuator/EcosystemActuator.h"

/* PALUDARIUM */
void PL_RiverLightFanRain::enter() {
    soilMoistureSensor = A0;                // Sensor de umidade do solo pino A0 conectado no A0 do Arduino
    irrigationSystem = A1;                  // Sensor de chuva pino A1 conectado no A1 do Arduino
    relePort = 4;                           // porta de controle do relé conectada no D4 do Arduino
}

/* PALUDARIUM */
void PL_RiverLightFanRain::setup() {
    pinMode(soilMoistureSensor, INPUT);     // Sensor de umidade do solo - porta A0 é entrada 
    pinMode(irrigationSystem, INPUT);       // Sensor de chuva - porta A1 é entrada 
    pinMode(relePort, OUTPUT);              // Porta de controle do Relé - D4 é saída 
    digitalWrite(relePort, HIGH);           // Mantém relé desligado  
}

/* PALUDARIUM */
void PL_RiverLightFanRain::simulate_ecosystem(EcosystemParameters *parametersPtr,
                                                   EcosystemScanner *scannerPtr,
                                                   EcosystemActuator *actuatorPtr)
{
    // ********* Primary scann *********
    scannerPtr->read_soil_moisture(parametersPtr, soilMoistureSensor);

    // ********* Irrigation strategy *********
    if (!parametersPtr->soilIsWet) {
        actuatorPtr->irrigation_system_on(parametersPtr, irrigationSystem);
        while (!parametersPtr->soilIsWet)
        {
            scannerPtr->read_soil_moisture(parametersPtr, soilMoistureSensor);
        }
        actuatorPtr->irrigation_system_off(parametersPtr, irrigationSystem);
    }
}

/* PALUDARIUM */
void PL_RiverLightFanRain::exit() {
    return;
}