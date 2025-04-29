#pragma once
#include "BaseData.h"

class Circuit : public BaseData {
    public:
        int sensorSoilMoisture = A0;       // Sensor de umidade do solo pino A0 conectado no A0 do Arduino 
        int sensorRain = A1;             // Sensor de chuva pino A1 conectado no A1 do Arduino 
        int sensorTemperature = A2;       // Sensor de chuva pino A2 conectado no A2 do Arduino 
        int portRelay = 4;                // porta de controle do relé conectada no D4 do Arduino
}