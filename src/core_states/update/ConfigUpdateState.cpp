#include "Arduino.h"
#include "ConfigUpdateState.h"
#include "StateTransitionException.h"
#include "SharedInstances.h"

// used by context.changeState
void ConfigUpdateState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in ConfigUpdateState");
    }
    
    Serial.println("(ConfigUpdateState) Running...");
};

void ConfigUpdateState::exit() {
    Serial.println("(exit) switching off ConfigUpdateState");
};

// error
void ConfigUpdateState::report_error() {
    throw StateTransitionException("(report_error): wrong state (ConfigUpdateState)");
};

// self
void ConfigUpdateState::run_health_check() {
    throw StateTransitionException("(run_health_check): wrong state (ConfigUpdateState)");
};

// comm
void ConfigUpdateState::report_signature_request() {
    throw StateTransitionException("(report_signature_request): wrong state (ConfigUpdateState)");
};

void ConfigUpdateState::session_new() {
    throw StateTransitionException("(report_signature_request): wrong state (ConfigUpdateState)");
};

void ConfigUpdateState::report_config() {
    throw StateTransitionException("(report_config): wrong state (ConfigUpdateState)");
};

void ConfigUpdateState::report_health_check() {
    throw StateTransitionException("(report_health_check): wrong state (ConfigUpdateState)");
};

// update
void ConfigUpdateState::update_config() {
    Serial.println("(update_config): running...");
    // Ask server if update is required
    // Get new config data
    // Validate data types and size
    // if `new key` exists, update value
    // if `new key` does NOT exist, add `key & value`
    // Keys MUST NOT be excluded in this method
    Serial.println("(update_config): done");
};

void ConfigUpdateState::update_simmulation_code() {
    Serial.println("(update_simmulation_code): running...");
    Serial.println("(update_simmulation_code): done");
};

// comm
void ConfigUpdateState::session_stop() {
    throw StateTransitionException("(session_stop): wrong state (ConfigUpdateState)");
};

// simm
void ConfigUpdateState::run_simmulation() {
    throw StateTransitionException("(RunSimmulation): wrong state (ConfigUpdateState)");
};

// comm
void ConfigUpdateState::report_simmulation_data() {
    throw StateTransitionException("(report_simmulation_data): wrong state (ConfigUpdateState)");
};

// self
void ConfigUpdateState::take_a_nap() {
    throw StateTransitionException("(take_a_nap): wrong state (ConfigUpdateState)");
};

// constructor
void ConfigUpdateState::ConfigUpdateState(FiniteStateMachine *cyclobot) {
    Serial.println("[ConfigUpdateState] Instantiated...");
};