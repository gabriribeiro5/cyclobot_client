#include "Arduino.h"
#include "../../../include/core_states/error/ErrorHandlingState.h"
#include "../../../include/Context.h"
// used by context.changeState
void ErrorHandlingState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        cyclobot->commPtr->visualCommPtr->print_line(F("[ErrorHandlingState::enter] cyclobot pointer is null in ErrorHandlingState"));
        return; // ou transição para um estado de erro seguro
    }
    
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  ****[ErrorHandlingState::enter]*****  ************************* "));
};

void ErrorHandlingState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *****[ErrorHandlingState::exit]*****  ************************* "));
};

// error
void ErrorHandlingState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[ErrorHandlingState::handle_error] running..."));
    cyclobot->commPtr->visualCommPtr->print_line(F("[ErrorHandlingState::handle_error] done"));
};

// self
void ErrorHandlingState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "run_health_check", 0, "wrong state");
};

// comm
void ErrorHandlingState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "report_signature_request", 0, "wrong state");
};

void ErrorHandlingState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "session_new", 0, "wrong state");
};

void ErrorHandlingState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "report_config", 0, "wrong state");
};

void ErrorHandlingState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "report_health_check", 0, "wrong state");
};

// update
void ErrorHandlingState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "update_config", 0, "wrong state");
};

void ErrorHandlingState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "update_simulation_code", 0, "wrong state");
};

// comm
void ErrorHandlingState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "session_stop", 0, "wrong state");
};

// sim
void ErrorHandlingState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "run_simulation", 0, "wrong state");
};

// comm
void ErrorHandlingState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "report_simulation_data", 0, "wrong state");
};

// self
void ErrorHandlingState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "ErrorHandlingState", "take_a_nap", 0, "wrong state");
};

// constructor
ErrorHandlingState::ErrorHandlingState() {
    return;
};