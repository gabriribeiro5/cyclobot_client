#pragma once
#include <Arduino.h>
#include <WiFiEsp.h>
#include "../config/ClientParameters.h"
#include "../config/WifiParameters.h"
#include "../config/DeviceParameters.h"
#include "../config/EcosystemParameters.h"
#include "../data/SelfDiagnosisData.h"
#include "../data/ConfigData.h"

class ClientComm {
    public:
        void trace_server(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr);
        void post_signature_request(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr);
        const char *get_cyclobot_session_token(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr);
        void put_invalid_cyclobot_session_token();
        void post_cyclobot_config(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, ConfigData *configDataPtr, EcosystemParameters *ecosystemParametersPtr);
        void post_cyclobot_diagnosis(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr);
        void post_cyclobot_environment_state();
        void get_cyclobot_config_update();
        void get_cyclobot_config_rollback();
};