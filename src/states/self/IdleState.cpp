#include "Arduino.h"
#include "../../../include/states/self/IdleState.h"
#include "../../../include/Context.h"
// used by context.changeState
void IdleState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("[IdleState::enter] cyclobot pointer is null in IdleState"));
        Serial.flush();
        return; // ou transição para um estado de erro seguro
    }
    
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *********[IdleState::enter]*********  ************************* "));
    // TODO: clear memory
};

void IdleState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *********[IdleState::exit]**********  ************************* "));
};

// error
void IdleState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "handle_error", 0, "wrong state");
};

// self
void IdleState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "run_health_check", 0, "wrong state");
};

// comm
void IdleState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "report_signature_request", 0, "wrong state");
};

void IdleState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "session_new", 0, "wrong state");
};

void IdleState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "report_config", 0, "wrong state");
};

void IdleState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "report_health_check", 0, "wrong state");
};

// update
void IdleState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "update_config", 0, "wrong state");
};

void IdleState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "update_simulation_code", 0, "wrong state");
};

// comm
void IdleState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "session_stop", 0, "wrong state");
};

// sim
void IdleState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "run_simulation", 0, "wrong state");
};

// comm
void IdleState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "IdleState", "report_simulation_data", 0, "wrong state");
};

// self
void IdleState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[IdleState::take_a_nap] zzz..."));
    // reset parameters
    cyclobot->paramPtr->wifiParametersPtr->scanCount = 0;
    
    // print empty line
    cyclobot->commPtr->visualCommPtr->print_line(F("..."));
    cyclobot->commPtr->visualCommPtr->print_line(F(""));
    cyclobot->commPtr->visualCommPtr->print_line(F("..."));
    cyclobot->commPtr->visualCommPtr->print_line(F(""));
    // sleep
    delay(cyclobot->paramPtr->deviceParametersPtr->sleepLength);
    cyclobot->commPtr->visualCommPtr->print_line(F("[IdleState::take_a_nap] -- done --"));
};

// constructor
IdleState::IdleState() {
    return;
};