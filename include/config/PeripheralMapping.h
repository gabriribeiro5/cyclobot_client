#pragma once
#include <Arduino.h>

class PeripheralMapping {
    public:
    #ifdef USE_MEGAAVR_ID
        uint8_t soilMoistureSensor = A0;     // Sensor de umidade do solo pino A0 conectado no A0 do Arduino 
        uint8_t wateringSystem = A1;         // Sensor de chuva pino A1 conectado no A1 do Arduino 
        uint8_t temperatureSensor = A2;      // Sensor de chuva pino A2 conectado no A2 do Arduino 
        int relePort = 4;                    // porta de controle do relé conectada no D4 do Arduino 
        int wifiEspRX = 6;                   // receive input from ESP8266 TX
        int wifiEspTX = 7;                   // send data to ESP8266 RX
    #else // Arduino Uno
        uint8_t soilMoistureSensor = A0;     // Sensor de umidade do solo pino A0 conectado no A0 do Arduino 
        uint8_t wateringSystem = A1;         // Sensor de chuva pino A1 conectado no A1 do Arduino 
        uint8_t temperatureSensor = A2;      // Sensor de chuva pino A2 conectado no A2 do Arduino 
        int relePort = 4;                    // porta de controle do relé conectada no D4 do Arduino 
        int wifiEspRX = 6;                   // receive input from ESP8266 TX
        int wifiEspTX = 7;                   // send data to ESP8266 RX
    #endif
};