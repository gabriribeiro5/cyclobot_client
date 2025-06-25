#pragma once
#include <WifiParameters.h>
#include <SPI.h>
#include <WiFi.h>

class WifiComm {
    public:
        void connect_wifi();
        void scan_wifi();
        void connectToServer();

    private:
        void print_wifi_status();
        void print_encryption_type();
        void check_wifi_firmware_version();
}