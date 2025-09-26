#pragma once
#include <Arduino.h>

class PeripheralMapping {
    public:
    PeripheralMapping();
    #ifdef USE_MEGAAVR_ID
        int wifiEspRX = 0;                   // receive input from ESP8266 TX
        int wifiEspTX = 1;                   // send data to ESP8266 RX
        int wifiEspRST = 0;                  // reset activated at low level (GND)
        int wifiEspGPIO2 = 0;                // wifi operations IO
        // int wifiEspCH_PD = 1;                // update wifi firmware at LOW level.
        // int wifiEspGPIO0 = 1;                // firmware update IO. Keep LOW for update.
    #else // Arduino Uno
        int wifiEspRX = 0;                   // receive input from ESP8266 TX
        int wifiEspTX = 1;                   // send data to ESP8266 RX
        int wifiEspRST = 2;                  // reset activated at low level (GND)
        int wifiEspGPIO2 = 4;                // wifi operations IO
        // int wifiEspCH_PD = 7;             // update wifi firmware at LOW level.
        // int wifiEspGPIO0 = 8;             // firmware update IO. Keep LOW for update.
    #endif
};