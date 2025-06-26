#include "SelfDiagnosisState.h"
#include "CheckMyHealth.h"
#include "StateTransitionException.h"
#include "WifiComm.h"
#include "ClientComm.h"
#include "Arduino.h"

// used by context.changeState
void SelfDiagnosisState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in SelfDiagnosisState");
    }
    
    Serial.println("(SelfDiagnosisState) Running...");
};

void SelfDiagnosisState::exit() {
    clear_runtime_data();
    Serial.println("(exit) switching off SelfDiagnosisState");
};

// error
void SelfDiagnosisState::report_error() {
    throw StateTransitionException("(report_error): wrong state (SelfDiagnosisState)");
};

// self
void SelfDiagnosisState::run_health_check() {
    Serial.println("(run_health_check) Running...");
    SelfDiagnosisDataPtr->diagnosisDateTime = ""; // TODO: apply current date and time
    // *** SENSORS ***
    
    // Wifi sensor
    if (wifi_shield_is_on()) { // check for the presence of the shield
        check_wifi_firmware_version();
        check_wifi_connection();
        check_client_communication();
        clear_runtime_data();
    }

    // *** ACTUATORS ***
    check_watering_system();
    check_river_system();
    check_wind_system();
    check_lighting_system();
    check_components_list();
};

// comm
void SelfDiagnosisState::report_signature_request() {
    throw StateTransitionException("(report_signature_request): wrong state (SelfDiagnosisState)");
};

void SelfDiagnosisState::session_new() {
    throw StateTransitionException("(report_signature_request): wrong state (SelfDiagnosisState)");
};

void SelfDiagnosisState::report_config() {
    throw StateTransitionException("(report_config): wrong state (SelfDiagnosisState)");
};

void SelfDiagnosisState::report_health_check() {
    throw StateTransitionException("(report_health_check): wrong state (SelfDiagnosisState)");
};

// update
void SelfDiagnosisState::update_config() {
    throw StateTransitionException("(update_config): wrong state (SelfDiagnosisState)");
};

void SelfDiagnosisState::update_simmulation_code() {
    throw StateTransitionException("(update_firmware): wrong state (SelfDiagnosisState)");
};

// comm
void SelfDiagnosisState::session_stop() {
    throw StateTransitionException("(session_stop): wrong state (SelfDiagnosisState)");
};

// simm
void SelfDiagnosisState::run_simmulation() {
    throw StateTransitionException("(RunSimmulation): wrong state (SelfDiagnosisState)");
};

// comm
void SelfDiagnosisState::report_simmulation_data() {
    throw StateTransitionException("(report_simmulation_data): wrong state (SelfDiagnosisState)");
};

// self
void SelfDiagnosisState::take_a_nap() {
    throw StateTransitionException("(take_a_nap): wrong state (SelfDiagnosisState)");
};

// constructor
void SelfDiagnosisState::SelfDiagnosisState(FiniteStateMachine *cyclobot) {
    Serial.println("[SelfDiagnosisState] Instantiated...");
};