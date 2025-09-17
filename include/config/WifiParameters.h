#pragma once
#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <avr/pgmspace.h>

class WifiParameters {
    public:
        const PROGMEM char* wifiSsid = "yourNetwork";              //  your network SSID (name)
        const PROGMEM char* wifiSecret = "secretPassword";         // your network password (use for WPA, or use as key for WEP)
        const PROGMEM char* wifiFirmwareLatestVersion = "1.1.0";
        const PROGMEM int networkKeyIndex = 0;                     // your network key Index number (needed only for WEP)
        
        int wifiStatus = WL_IDLE_STATUS;                           // if you don't want to use DNS (and reduce your sketch size)
        bool wifiShieldIsOn = 0;                                   // your network key Index number (needed only for WEP)
        int networkSsidIndex;
        
        const PROGMEM int waitTimePerConnectionAttempt = 5000;     // 5 segundos
        const PROGMEM int maxConnectoinAttempt = 3;      
        int connAttemptCount = 0;      
        
        const PROGMEM int waitTimePerScanAttempt = 3000;           // 3 segundos
        const PROGMEM int wifiMaxScanAttempt = 3;
        int scanCount = 0;
        
        WiFiEspClient client;
};