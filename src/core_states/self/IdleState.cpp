#include "IdleState.h"
#include "StateTransitionException.h"
#include "SelfDiagnosisState.h"
#include "SelfParameters.h"
#include "ClientComm.h"
#include "Arduino.h"

// used by context.changeState
void IdleState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in IdleState");
    }
    
    Serial.println("(IdleState) Running...");
    // TODO: clear memory
};

void IdleState::exit() {
    Serial.println("(exit) switching off IdleState");
};

// error
void IdleState::report_error() {
    throw StateTransitionException("(report_error): wrong state (IdleState)");
};

// self
void IdleState::run_health_check() {
    throw StateTransitionException("(run_health_check): wrong state (IdleState)");
};

// comm
void IdleState::report_signature_request() {
    throw StateTransitionException("(report_signature_request): wrong state (IdleState)");
};

void IdleState::session_new() {
    throw StateTransitionException("(report_signature_request): wrong state (IdleState)");
};

void IdleState::report_config() {
    throw StateTransitionException("(report_config): wrong state (IdleState)");
};

void IdleState::report_health_check() {
    throw StateTransitionException("(report_health_check): wrong state (IdleState)");
};

// update
void IdleState::update_config() {
    throw StateTransitionException("(update_config): wrong state (IdleState)");
};

void IdleState::update_simmulation_code() {
    throw StateTransitionException("(update_firmware): wrong state (IdleState)");
};

// comm
void IdleState::session_stop() {
    throw StateTransitionException("(session_stop): wrong state (IdleState)");
};

// simm
void IdleState::run_simmulation() {
    throw StateTransitionException("(RunSimmulation): wrong state (IdleState)");
};

// comm
void IdleState::report_simmulation_data() {
    throw StateTransitionException("(report_simmulation_data): wrong state (IdleState)");
};

// self
void IdleState::take_a_nap() {
    Serial.println("(take_a_nap) running...");
    WifiParametersPtr->scanCount = 0;
    delay(sleep_lenght)
    Serial.println("(take_a_nap) done");
};

// constructor
void IdleState::IdleState(FiniteStateMachine *cyclobot) {
    Serial.println("[IdleState] Instantiated...");
};