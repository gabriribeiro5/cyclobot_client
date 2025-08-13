#pragma once
#include "../../BaseStrategy.h"
#include "../../../../../config/EcosystemParameters.h"
#include "../../../../../config/DeviceParameters.h"
#include "../../../../../sensor/EcosystemScanner.h"
#include "../../../../../actuator/EcosystemActuator.h"

class PR_DoorThermoPlayerToy : public BaseStrategy {
    public:
        PR_DoorThermoPlayerToy();

        void enter() override;
        void setup() override;
        void simulate_ecosystem(EcosystemParameters *ecosystemParamPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr) override;
        void exit() override;    
    private:
        uint8_t soilMoistureSensor;       // Sensor de umidade do solo pino A0 conectado no A0 do Arduino
        uint8_t irrigationSystem;         // Sensor de chuva pino A1 conectado no A1 do Arduino
        int relePort;                     // porta de controle do relé conectada no D4 do Arduino
};