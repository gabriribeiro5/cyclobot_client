#pragma once
#include <WiFi.h>

class WifiParameters {
    public:
        char ssid[] = "yourNetwork"; //  your network SSID (name)
        char pass[] = "secretPassword";    // your network password (use for WPA, or use as key for WEP)
        int keyIndex = 0;            // your network key Index number (needed only for WEP)
        int wifiStatus = WL_IDLE_STATUS;        // if you don't want to use DNS (and reduce your sketch size)
        // use the numeric IP instead of the name for the server:
        //IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
        char server[] = "www.google.com";    // name address for Google (using DNS)

        int networkSsidNum;
        
        int waitTimePerConnectionAttempt = 5000; // 5 segundos
        int wifiMaxConnectoinAttempt = 3;
        
        int waitTimePerScanAttempt = 3000; // 3 segundos
        int wifiMaxScanAttempt = 3;
        int scanCount = 0;
        
        WiFiClient client;
}