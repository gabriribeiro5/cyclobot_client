
#include "Arduino.h"
#include "../../../include/core_states/update/CodeUpdateState.h"
#include "../../../include/util/StateTransitionException.h"
#include "../../../include/Context.h"

// used by context.changeState
void CodeUpdateState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in CodeUpdateState"));
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F("(CodeUpdateState) Running..."));
};

void CodeUpdateState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F("(exit) switching off CodeUpdateState"));
};

// error
void CodeUpdateState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "handle_error", 0, "wrong state");
};

// self
void CodeUpdateState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "run_health_check", 0, "wrong state");
};

// comm
void CodeUpdateState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "report_signature_request", 0, "wrong state");
};

void CodeUpdateState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "session_new", 0, "wrong state");
};

void CodeUpdateState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "report_config", 0, "wrong state");
};

void CodeUpdateState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "report_health_check", 0, "wrong state");
};

// update
void CodeUpdateState::update_config(FiniteStateMachine *cyclobot) {
    Serial.println(F("(update_config) running..."));
    Serial.println(F("(update_config) done"));
};

void CodeUpdateState::update_simulation_code(FiniteStateMachine *cyclobot) {
    Serial.println(F("(update_simulation_code) running..."));
    // Ask server if update is required
    // Run paralel code
    // Get code hash
    // Update code
    Serial.println(F("(update_simulation_code) done"));
};

// comm
void CodeUpdateState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "session_stop", 0, "wrong state");
};

// sim
void CodeUpdateState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "run_simulation", 0, "wrong state");
};

// comm
void CodeUpdateState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "report_simulation_data", 0, "wrong state");
};

// self
void CodeUpdateState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "CodeUpdateState", "take_a_nap", 0, "wrong state");
};

// constructor
CodeUpdateState::CodeUpdateState() {
    Serial.println(F("[CodeUpdateState] Instantiated..."));
};