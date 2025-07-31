#include "Arduino.h"
#include "../../../include/core_states/simm/SimmulationState.h"
#include "../../../include/util/StateTransitionException.h"
#include "../../../include/shared/SharedInstances.h"
#include "../../../include/Context.h"

// used by context.changeState
void SimmulationState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in SimmulationState"));
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F("(SimmulationState) Running..."));
};

void SimmulationState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F("(exit) switching off SimmulationState"));
};

// error
void SimmulationState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "handle_error", 0, "wrong state");
};

// self
void SimmulationState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "run_health_check", 0, "wrong state");
};

// comm
void SimmulationState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "report_signature_request", 0, "wrong state");
};

void SimmulationState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "session_new", 0, "wrong state");
};

void SimmulationState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "report_config", 0, "wrong state");
};

void SimmulationState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "report_health_check", 0, "wrong state");
};

// update
void SimmulationState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "update_config", 0, "wrong state");
};

void SimmulationState::update_simmulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "update_simmulation_code", 0, "wrong state");
};

// comm
void SimmulationState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "session_stop", 0, "wrong state");
};

// simm
void SimmulationState::run_simmulation(FiniteStateMachine *cyclobot) {
    Serial.println(F("(run_simmulation) running..."));
    Serial.println(F("(run_simmulation) done"));
};

// comm
void SimmulationState::report_simmulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "report_simmulation_data", 0, "wrong state");
};

// self
void SimmulationState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimmulationState", "take_a_nap", 0, "wrong state");
};

// constructor
SimmulationState::SimmulationState() {
    Serial.println(F("(SimmulationState): Instantiated..."));
};