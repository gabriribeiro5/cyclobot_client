#pragma once
#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <avr/pgmspace.h>

class WifiParameters {
    public:
        WifiParameters();
        ~WifiParameters();
        
        Stream* wifiStream;

        const char* wifiSsid;                      //  your network SSID (name)
        const char* wifiSecret;                    // your network password (use for WPA, or use as key for WEP)
        const char* wifiFirmwareLatestVersion;
        const int networkKeyIndex;                 // your network key Index number (needed only for WEP)
        
        
        const int waitTimePerConnectionAttempt;    // 5 segundos
        const int maxConnectionAttempt;
        
        const int waitTimePerScanAttempt;          // 3 segundos
        const int wifiMaxScanAttempt;
        
        int wifiStatus;                            // if you don't want to use DNS (and reduce your sketch size)
        bool wifiShieldIsOn;                       // your network key Index number (needed only for WEP)
        int networkSsidIndex;
        int connAttemptCount;
        int scanCount;
        
        WiFiEspClient client;
};