#pragma once
#include "../../BaseStrategy.h"
#include "../../../../../config/EcosystemParameters.h"
#include "../../../../../config/DeviceParameters.h"
#include "../../../../../sensor/EcosystemScanner.h"
#include "../../../../../actuator/EcosystemActuator.h"
#include "../../../../../comm/VisualComm.h"

class AQ_LightNutrient : public BaseStrategy {
    public:
        AQ_LightNutrient();

        void enter() override;
        void setup(VisualComm *visualCommPtr) override;
        void simulate_ecosystem(EcosystemParameters *ecosystemParamPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, VisualComm *visualCommPtr) override;
        void exit() override;    
    private:
        uint8_t soilMoistureSensor;       // Sensor de umidade do solo pino A0 conectado no A0 do Arduino
        uint8_t irrigationSystem;         // Sensor de chuva pino A1 conectado no A1 do Arduino
        int relePort;                     // porta de controle do relé conectada no D4 do Arduino
};