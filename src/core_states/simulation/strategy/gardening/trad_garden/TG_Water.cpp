#include <Arduino.h>
#include "../../../../../../include/core_states/simulation/strategy/gardening/trad_garden/TG_Water.h"
#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/config/DeviceParameters.h"
#include "../../../../../../include/sensor/EcosystemScanner.h"
#include "../../../../../../include/actuator/EcosystemActuator.h"
#include "../../../../../../include/comm/VisualComm.h"

/* TRADITIONAL GARDEN */
TG_Water::TG_Water() {}

/* TRADITIONAL GARDEN */
void TG_Water::enter() {
	soilMoistureSensor = A0;                // Sensor de umidade do solo pino A0 conectado no A0 do Arduino
	irrigationSystem = A1;                  // Sensor de chuva pino A1 conectado no A1 do Arduino
	relePort = 4;                           // porta de controle do relé conectada no D4 do Arduino
}

/* TRADITIONAL GARDEN */
void TG_Water::setup(VisualComm *visualCommPtr) {
	visualCommPtr->print_line(F("[TG_Water::setup] running"));
	pinMode(soilMoistureSensor, INPUT);     // Sensor de umidade do solo - porta A0 é entrada 
	visualCommPtr->print_line(F("[TG_Water::setup] soilMoistureSensor set to INPUT"));
	pinMode(irrigationSystem, INPUT);       // Sensor de chuva - porta A1 é entrada 
	visualCommPtr->print_line(F("[TG_Water::setup] irrigationSystem set to INPUT"));
	pinMode(relePort, OUTPUT);              // Porta de controle do Relé - D4 é saída 
	visualCommPtr->print_line(F("[TG_Water::setup] relePort set to OUTPUT"));
	digitalWrite(relePort, HIGH);           // Mantém relé desligado  
	visualCommPtr->print_line(F("[TG_Water::setup] relePort set to OUTPUT HIGH"));
}

/* TRADITIONAL GARDEN */
void TG_Water::simulate_ecosystem(EcosystemParameters *parametersPtr,
								  EcosystemScanner *scannerPtr,
								  EcosystemActuator *actuatorPtr,
								  VisualComm *visualCommPtr)
{
	// ********* Primary scann *********
	visualCommPtr->print_line(F("[TG_Water::simulate_ecosystem] reading soil moisture"));
	scannerPtr->read_soil_moisture(parametersPtr, visualCommPtr, soilMoistureSensor);
	
	// ********* Irrigation strategy *********
	if (!parametersPtr->soilIsWet) {
		visualCommPtr->print_line(F("[TG_Water::simulate_ecosystem] initiating irrigation strategy"));
		actuatorPtr->irrigation_system_on(parametersPtr, visualCommPtr, irrigationSystem);
		while (!parametersPtr->soilIsWet)
		{
			scannerPtr->read_soil_moisture(parametersPtr, visualCommPtr, soilMoistureSensor);
		}
		actuatorPtr->irrigation_system_off(parametersPtr, visualCommPtr, irrigationSystem);
	}
	visualCommPtr->print_line(F("[TG_Water::simulate_ecosystem] no irrigation is required"));
}

/* TRADITIONAL GARDEN */
void TG_Water::exit() {
	return;
}