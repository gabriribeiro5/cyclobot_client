#pragma once
#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <SPI.h>

class WifiParameters {
    public:
        const char* wifiSsid = "yourNetwork";               //  your network SSID (name)
        const char* wifiSecret = "secretPassword";          // your network password (use for WPA, or use as key for WEP)
        const char* wifiFirmwareLatestVersion = "1.1.0";
        int networkKeyIndex = 0;                     // your network key Index number (needed only for WEP)
        int wifiStatus = WL_IDLE_STATUS;             // if you don't want to use DNS (and reduce your sketch size)
        
        bool wifiShieldIsOn = 0;                     // your network key Index number (needed only for WEP)
        int networkSsidIndex;
        
        int waitTimePerConnectionAttempt = 5000;     // 5 segundos
        int maxConnectoinAttempt = 3;
        int connAttemptCount = 0;
        
        int waitTimePerScanAttempt = 3000;           // 3 segundos
        int wifiMaxScanAttempt = 3;
        int scanCount = 0;
        
        WiFiEspClient client;
};