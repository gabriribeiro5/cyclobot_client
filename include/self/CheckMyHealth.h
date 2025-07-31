#pragma once
#include "..\comm\ClientComm.h"
#include "..\comm\WifiComm.h"
#include "WiFiEsp.h"

// CycloBot Finite State Machine
class CheckMyHealth {
    public:
        bool wifi_shield_is_on(WifiParameters *wifiParametersPtr);
        void check_wifi_firmware_version(WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_wifi_networks(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_wifi_connection(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_client_communication(ClientComm *clientCommPtr, WifiParameters *wifiParametersPtr, ClientParameters *clientParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_watering_system(SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_river_system(SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_wind_system(SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_lighting_system(SelfDiagnosisData *selfDiagnosisDataPtr);
        void check_components_list(SelfDiagnosisData *selfDiagnosisDataPtr);
        void clear_runtime_data();
};