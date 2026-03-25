#pragma once
#include <Arduino.h>
#include <WiFiEsp.h>
#include "../../fsm_tools/config/ClientParameters.h"
#include "../../fsm_tools/config/WifiParameters.h"
#include "../../fsm_tools/config/DeviceParameters.h"
#include "../../fsm_tools/data/SelfDiagnosisData.h"
#include "../../fsm_tools/StrategyDataInstances.h"
#include "./VisualComm.h"

class ClientComm {
    public:
        void trace_server(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr);
        void post_signature_request(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, VisualComm *visualCommPtr);
        const char *get_cyclobot_session_token(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, VisualComm *visualCommPtr);
        void put_invalid_cyclobot_session_token(VisualComm *visualCommPtr);
        void post_cyclobot_config(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, ConfigData *configDataPtr, VisualComm *visualCommPtr);
        void post_cyclobot_diagnosis(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr);
        void post_ecosystem_data(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, EcosystemData *ecosystemDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr);
        void get_cyclobot_config_update(VisualComm *visualCommPtr);
        void get_cyclobot_config_rollback(VisualComm *visualCommPtr);
};