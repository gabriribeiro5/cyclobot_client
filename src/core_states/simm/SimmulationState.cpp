#include "SimmulationState.h"
#include "StateTransitionException.h"
#include "Arduino.h"

// used by context.changeState
void SimmulationState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in SimmulationState");
    }
    
    Serial.println("(SimmulationState) Running...");
};

void SimmulationState::exit() {
    Serial.println("(exit) switching off SimmulationState");
};

// error
void SimmulationState::report_error() {
    throw StateTransitionException("(report_error): wrong state (SimmulationState)");
};

// self
void SimmulationState::run_health_check() {
    throw StateTransitionException("(run_health_check): wrong state (SimmulationState)");
};

// comm
void SimmulationState::report_signature_request() {
    throw StateTransitionException("(report_signature_request): wrong state (SimmulationState)");
};

void SimmulationState::session_new() {
    throw StateTransitionException("(report_signature_request): wrong state (SimmulationState)");
};

void SimmulationState::report_config() {
    throw StateTransitionException("(report_config): wrong state (SimmulationState)");
};

void SimmulationState::report_health_check() {
    throw StateTransitionException("(report_health_check): wrong state (SimmulationState)");
};

// update
void SimmulationState::update_config() {
    throw StateTransitionException("(update_config): wrong state (SimmulationState)");
};

void SimmulationState::update_simmulation_code() {
    throw StateTransitionException("(update_firmware): wrong state (SimmulationState)");
};

// comm
void SimmulationState::session_stop() {
    throw StateTransitionException("(session_stop): wrong state (SimmulationState)");
};

// simm
void SimmulationState::run_simmulation() {
    Serial.println("(run_simmulation) running...");
    Serial.println("(run_simmulation) done");
    
    // change state
    BaseState clientState = HTTPClientState();
    cyclobot.changestate(&clientState);
};

// comm
void SimmulationState::report_simmulation_data() {
    throw StateTransitionException("(report_simmulation_data): wrong state (SimmulationState)");
};

// self
void SimmulationState::take_a_nap() {
    throw StateTransitionException("(take_a_nap): wrong state (SimmulationState)");
};

// constructor
void SimmulationState::SimmulationState(FiniteStateMachine *cyclobot) {
    Serial.println("[SimmulationState] Instantiated...");
};