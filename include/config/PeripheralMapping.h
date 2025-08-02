#pragma once

class PeripheralMapping {
    public:
        const PROGMEM int soilMoistureSensor = A0;     // Sensor de umidade do solo pino A0 conectado no A0 do Arduino 
        const PROGMEM int wateringSystem = A1;         // Sensor de chuva pino A1 conectado no A1 do Arduino 
        const PROGMEM int temperatureSensor = A2;      // Sensor de chuva pino A2 conectado no A2 do Arduino 
        const PROGMEM int relePort = 4;                // porta de controle do relé conectada no D4 do Arduino 
        const PROGMEM int wifiEspRX = 6;               // receive input from ESP8266 TX
        const PROGMEM int wifiEspTX = 7;               // send data to ESP8266 RX
};