#include <Arduino.h>
#include "../../../../../../include/core_states/simulation/strategy/gardening/trad_garden/TG_WaterFanLightNutrientThermo.h"
#include "../../../../../../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../../../../../../include/config/EcosystemParameters.h"
#include "../../../../../../include/config/DeviceParameters.h"
#include "../../../../../../include/sensor/EcosystemScanner.h"
#include "../../../../../../include/actuator/EcosystemActuator.h"
#include "../../../../../../include/comm/VisualComm.h"

/* TRADITIONAL GARDEN */
void TG_WaterFanLightNutrientThermo::enter() {
	// ANALOG
	soilMoistureSensor = A0;
	brightnessSensor = A1;       // Photoresistor
	nutrientSensor = A2;
	thermoSensor = A3;
	
	// DIGITAL (PWM ~)
	fanSystem = 3;
	lightSystem = 5;
	thermoSystem = 6;
	
	// DIGITAL (high/low only)
	irrigationSystem = 7;
	nutrientSystem = 8;
}

/* TRADITIONAL GARDEN */
void TG_WaterFanLightNutrientThermo::setup(VisualComm *visualCommPtr) {
	pinMode(soilMoistureSensor, INPUT);
	pinMode(brightnessSensor, INPUT);
	pinMode(nutrientSensor, INPUT);
	pinMode(thermoSensor, INPUT);

	pinMode(irrigationSystem, OUTPUT);
	digitalWrite(irrigationSystem, HIGH); // keep system off

	pinMode(fanSystem, OUTPUT);
	digitalWrite(fanSystem, HIGH);        // keep system off

	pinMode(lightSystem, OUTPUT);
	digitalWrite(lightSystem, HIGH);      // keep system off

	pinMode(nutrientSystem, OUTPUT);
	digitalWrite(nutrientSystem, HIGH);   // keep system off

	pinMode(nutrientSystem, OUTPUT);
	digitalWrite(nutrientSystem, HIGH);   // keep system off
}

/* TRADITIONAL GARDEN */
void TG_WaterFanLightNutrientThermo::simulate_ecosystem(EcosystemParameters *parametersPtr,
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

/* TRADITIONAL GARDEN */
void TG_WaterFanLightNutrientThermo::exit() {
	return;
}