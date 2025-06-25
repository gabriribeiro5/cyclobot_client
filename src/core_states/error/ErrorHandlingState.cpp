#include "ErrorHandlingState.h"
#include "StateTransitionException.h"
#include "Arduino.h"

// used by context.changeState
void ErrorHandlingState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in ErrorHandlingState");
    }
    
    Serial.println("(ErrorHandlingState) Running...");
};

void ErrorHandlingState::exit() {
    Serial.println("(exit) switching off ErrorHandlingState");
};

// error
void ErrorHandlingState::report_error() {
    Serial.println("(report_error) running...");
    Serial.println("(report_error) done");
};

// self
void ErrorHandlingState::run_health_check() {
    throw StateTransitionException("(run_health_check): wrong state (ErrorHandlingState)");
};

// comm
void ErrorHandlingState::report_signature_request() {
    throw StateTransitionException("(report_signature_request): wrong state (ErrorHandlingState)");
};

void ErrorHandlingState::session_new() {
    throw StateTransitionException("(report_signature_request): wrong state (ErrorHandlingState)");
};

void ErrorHandlingState::report_config() {
    throw StateTransitionException("(report_config): wrong state (ErrorHandlingState)");
};

void ErrorHandlingState::report_health_check() {
    throw StateTransitionException("(report_health_check): wrong state (ErrorHandlingState)");
};

// update
void ErrorHandlingState::update_config() {
    throw StateTransitionException("(update_config): wrong state (ErrorHandlingState)");
};

void ErrorHandlingState::update_simmulation_code() {
    throw StateTransitionException("(update_firmware): wrong state (ErrorHandlingState)");
};

// comm
void ErrorHandlingState::session_stop() {
    throw StateTransitionException("(session_stop): wrong state (ErrorHandlingState)");
};

// simm
void ErrorHandlingState::run_simmulation() {
    throw StateTransitionException("(RunSimmulation): wrong state (ErrorHandlingState)");
};

// comm
void ErrorHandlingState::report_simmulation_data() {
    throw StateTransitionException("(report_simmulation_data): wrong state (ErrorHandlingState)");
};

// self
void ErrorHandlingState::take_a_nap() {
    throw StateTransitionException("(take_a_nap): wrong state (ErrorHandlingState)");
};

// constructor
void ErrorHandlingState::ErrorHandlingState(FiniteStateMachine *cyclobot) {
    Serial.println("[ErrorHandlingState] Instantiated...");
};