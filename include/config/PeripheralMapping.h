#pragma once

class PeripheralMapping {
    public:
        int soilMoistureSensor = A0;                       // Sensor de umidade do solo pino A0 conectado no A0 do Arduino 
        int wateringSystem = A1;                             // Sensor de chuva pino A1 conectado no A1 do Arduino 
        int temperatureSensor = A2;                       // Sensor de chuva pino A2 conectado no A2 do Arduino 
        int relePort = 4;                                // porta de controle do relé conectada no D4 do Arduino 
}