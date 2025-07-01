#include "CodeUpdateState.h"
#include "StateTransitionException.h"
#include "HTTPClientState.h"
#include "Arduino.h"

// used by context.changeState
void CodeUpdateState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in CodeUpdateState");
    }
    
    Serial.println("(CodeUpdateState) Running...");
};

void CodeUpdateState::exit() {
    Serial.println("(exit) switching off CodeUpdateState");
};

// error
void CodeUpdateState::report_error() {
    throw StateTransitionException("(report_error): wrong state (CodeUpdateState)");
};

// self
void CodeUpdateState::run_health_check() {
    throw StateTransitionException("(run_health_check): wrong state (CodeUpdateState)");
};

// comm
void CodeUpdateState::report_signature_request() {
    throw StateTransitionException("(report_signature_request): wrong state (CodeUpdateState)");
};

void CodeUpdateState::session_new() {
    throw StateTransitionException("(report_signature_request): wrong state (CodeUpdateState)");
};

void CodeUpdateState::report_config() {
    throw StateTransitionException("(report_config): wrong state (CodeUpdateState)");
};

void CodeUpdateState::report_health_check() {
    throw StateTransitionException("(report_health_check): wrong state (CodeUpdateState)");
};

// update
void CodeUpdateState::update_config() {
    Serial.println("(update_config) running...");
    Serial.println("(update_config) done");
};

void CodeUpdateState::update_simmulation_code() {
    Serial.println("(update_simmulation_code) running...");
    // Ask server if update is required
    // Run paralel code
    // Get code hash
    // Update code
    Serial.println("(update_simmulation_code) done");
};

// comm
void CodeUpdateState::session_stop() {
    throw StateTransitionException("(session_stop): wrong state (CodeUpdateState)");
};

// simm
void CodeUpdateState::run_simmulation() {
    throw StateTransitionException("(RunSimmulation): wrong state (CodeUpdateState)");
};

// comm
void CodeUpdateState::report_simmulation_data() {
    throw StateTransitionException("(report_simmulation_data): wrong state (CodeUpdateState)");
};

// self
void CodeUpdateState::take_a_nap() {
    throw StateTransitionException("(take_a_nap): wrong state (CodeUpdateState)");
};

// constructor
void CodeUpdateState::CodeUpdateState(FiniteStateMachine *cyclobot) {
    Serial.println("[CodeUpdateState] Instantiated...");
};