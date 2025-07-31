#pragma once
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include "../config/WifiParameters.h"

class WifiComm {
    public:
        void connect_wifi(WifiParameters *wifiParametersPtr);
        void disconnect_wifi();
        void scan_wifi(WifiParameters *wifiParametersPtr);
        void connectToServer();

    private:
        void print_wifi_status();
        void print_encryption_type(int thisType);
        void print_available_networks(WifiParameters *wifiParametersPtr);
        void check_wifi_firmware_version();
};