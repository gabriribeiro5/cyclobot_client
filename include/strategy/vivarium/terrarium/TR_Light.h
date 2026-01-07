#pragma once
#include "../../BaseStrategy.h"
#include "../../../config/StrategyParameters.h"
#include "../../../config/DeviceParameters.h"
#include "../../../sensor/EcosystemScanner.h"
#include "../../../actuator/EcosystemActuator.h"
#include "../../../comm/VisualComm.h"

class TR_Light : public BaseStrategy {
    public:
        TR_Light();

        void enter(StrategyParameters *strategyParameters) override;
        void setup(VisualComm *visualCommPtr) override;
        void simulate_ecosystem(StrategyParameters *strategyParametersPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, VisualComm *visualCommPtr) override;
        void exit() override;    
    private:
        uint8_t soilMoistureSensor;       // Sensor de umidade do solo pino A0 conectado no A0 do Arduino
        uint8_t irrigationSystem;         // Sensor de chuva pino A1 conectado no A1 do Arduino
        int relePort;                     // porta de controle do relé conectada no D4 do Arduino
};