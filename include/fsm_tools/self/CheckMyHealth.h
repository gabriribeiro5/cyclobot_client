#pragma once
#include "../comm/ClientComm.h"
#include "../comm/WifiComm.h"
#include "../comm/VisualComm.h"
#include "WiFiEsp.h"

// CycloBot Finite State Machine
class CheckMyHealth {
    public:
        bool wifi_shield_is_on(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);
        void check_wifi_firmware_version(WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_wifi_networks(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_wifi_connection(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_client_communication(ClientComm *clientCommPtr, WifiParameters *wifiParametersPtr, ClientParameters *clientParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_watering_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_river_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_wind_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_lighting_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void check_components_list(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void clear_runtime_data(VisualComm *visualCommPtr);
};