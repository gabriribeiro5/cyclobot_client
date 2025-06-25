#pragma once

// CycloBot Finite State Machine
class CheckMyHealth {
    public:
        bool wifi_shield_is_on();
        void check_wifi_firmware_version();
        void check_client_communication();
}