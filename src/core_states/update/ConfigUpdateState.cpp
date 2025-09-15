
#include "Arduino.h"
#include "../../../include/core_states/update/ConfigUpdateState.h"
#include "../../../include/self/ErrorHandler.h"
#include "../../../include/Context.h"

// used by context.changeState
void ConfigUpdateState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        cyclobot->commPtr->visualCommPtr->print_line(F("(enter): cyclobot pointer is null in ConfigUpdateState"));
        return;
    }
    
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *****[ConfigUpdateState::enter]*****  ************************* "));
};

void ConfigUpdateState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *****[ConfigUpdateState::exit]******  ************************* "));
};

// error
void ConfigUpdateState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "handle_error", 0, "wrong state");
};

// self
void ConfigUpdateState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "run_health_check", 0, "wrong state");
};

// comm
void ConfigUpdateState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "report_signature_request", 0, "wrong state");
};

void ConfigUpdateState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "session_new", 0, "wrong state");
};

void ConfigUpdateState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "report_config", 0, "wrong state");
};

void ConfigUpdateState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "report_health_check", 0, "wrong state");
};

// update
void ConfigUpdateState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("(update_config): running..."));
    // Ask server if update is required
    // Get new config data
    // Validate data types and size
    // if `new key` exists, update value
    // if `new key` does NOT exist, add `key & value`
    // Keys MUST NOT be excluded in this method
    cyclobot->commPtr->visualCommPtr->print_line(F("(update_config): done"));
};

void ConfigUpdateState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("(update_simulation_code): running..."));
    cyclobot->commPtr->visualCommPtr->print_line(F("(update_simulation_code): done"));
};

// comm
void ConfigUpdateState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "session_stop", 0, "wrong state");
};

// sim
void ConfigUpdateState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "run_simulation", 0, "wrong state");
};

// comm
void ConfigUpdateState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "report_simulation_data", 0, "wrong state");
};

// self
void ConfigUpdateState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "ConfigUpdateState", "take_a_nap", 0, "wrong state");
};

// constructor
ConfigUpdateState::ConfigUpdateState() {
    return;
};