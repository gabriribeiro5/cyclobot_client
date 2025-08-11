#pragma once
#include <Arduino.h>

class PeripheralMapping {
    public:
    #ifdef USE_MEGAAVR_ID
        int relePort = 4;                    // porta de controle do relé conectada no D4 do Arduino 
        int wifiEspRX = 6;                   // receive input from ESP8266 TX
        int wifiEspTX = 7;                   // send data to ESP8266 RX
    #else // Arduino Uno
        int relePort = 4;                    // porta de controle do relé conectada no D4 do Arduino 
        int wifiEspRX = 6;                   // receive input from ESP8266 TX
        int wifiEspTX = 7;                   // send data to ESP8266 RX
    #endif
};