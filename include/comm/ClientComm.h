#pragma once
#include <WifiParameters.h>
#include <SPI.h>
#include <WiFi.h>

class ClientComm {
    public:
        void trace_server();
        void post_signature_request();
        void get_cyclobot_session_token();
        void post_cyclobot_diagnostic();
        void post_cyclobot_config();
        void post_cyclobot_environment_state();
        void get_cyclobot_config_update();
        void get_cyclobot_config_rollback();

        void ClientComm();
}