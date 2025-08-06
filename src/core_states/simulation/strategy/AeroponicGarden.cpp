#include "../../../../include/core_states/simulation/strategy/AeroponicGarden.h"
#include "../../../../include/config/EcosystemParameters.h"
#include "../../../../include/config/PeripheralMapping.h"
#include "../../../../include/sensor/EnvironmentScan.h"
#include "../../../../include/actuator/EnvironmentActuator.h"
#include "Arduino.h"

AeroponicGarden::AeroponicGarden() {
    Serial.println(F("[AeroponicGarden] Instantiated..."));
}

void AeroponicGarden::enter(SimStrategy *strategy) {
    Serial.println(F("[AeroponicGarden] Simulating environment..."));
}

void AeroponicGarden::pin_map(PeripheralMapping *peripheralMapping) {
    return;
}

void AeroponicGarden::read_environment_data(EcosystemParameters *param) {
    Serial.println(F("[AeroponicGarden] Reading environment data..."));
    // HYDROSTATIC INPUTS
    
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

void AeroponicGarden::simulate_environment(EcosystemParameters *param, PeripheralMapping *pin) {
    Serial.println(F("[AeroponicGarden] Simulating environment..."));
}

void AeroponicGarden::exit(SimStrategy *strategy) {
    Serial.println(F("[AeroponicGarden] Simulating environment..."));
}