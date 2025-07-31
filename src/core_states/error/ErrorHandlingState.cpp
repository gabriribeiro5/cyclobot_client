#include "Arduino.h"
#include "../../../include/core_states/error/ErrorHandlingState.h"
#include "../../../include/Context.h"
// used by context.changeState
void ErrorHandlingState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in ErrorHandlingState"));
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F("(ErrorHandlingState) Running..."));
};

void ErrorHandlingState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F("(exit) switching off ErrorHandlingState"));
};

// error
void ErrorHandlingState::handle_error(FiniteStateMachine *cyclobot) {
    Serial.println(F("(handle_error) running..."));
    Serial.println(F("(handle_error) done"));
};

// self
void ErrorHandlingState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "run_health_check", 0, "wrong state");
};

// comm
void ErrorHandlingState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "report_signature_request", 0, "wrong state");
};

void ErrorHandlingState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "session_new", 0, "wrong state");
};

void ErrorHandlingState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "report_config", 0, "wrong state");
};

void ErrorHandlingState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "report_health_check", 0, "wrong state");
};

// update
void ErrorHandlingState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "update_config", 0, "wrong state");
};

void ErrorHandlingState::update_simmulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "update_simmulation_code", 0, "wrong state");
};

// comm
void ErrorHandlingState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "session_stop", 0, "wrong state");
};

// simm
void ErrorHandlingState::run_simmulation(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "run_simmulation", 0, "wrong state");
};

// comm
void ErrorHandlingState::report_simmulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "report_simmulation_data", 0, "wrong state");
};

// self
void ErrorHandlingState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "ErrorHandlingState", "take_a_nap", 0, "wrong state");
};

// constructor
ErrorHandlingState::ErrorHandlingState() {
    Serial.println(F("[ErrorHandlingState] Instantiated..."));
};