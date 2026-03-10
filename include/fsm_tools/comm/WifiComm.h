#pragma once
#include "Arduino.h"
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include "../../fsm_tools/config/WifiParameters.h"
#include "VisualComm.h"

#pragma once
#include <Arduino.h>



class WifiComm {
    public:
        static Stream* get_stream();
        static void initialize_wifi_module(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);
        void connect_wifi(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);
        void disconnect_wifi(VisualComm *visualCommPtr);
        void scan_wifi(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);
        void connect_to_server(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);

    private:
        void print_wifi_status(VisualComm *visualCommPtr);
        void print_encryption_type(int thisType, VisualComm *visualCommPtr);
        void print_available_networks(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);
        void check_wifi_firmware_version(VisualComm *visualCommPtr);
};