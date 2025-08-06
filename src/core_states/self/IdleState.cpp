#include "Arduino.h"
#include "../../../include/core_states/self/IdleState.h"
#include "../../../include/Context.h"
// used by context.changeState
void IdleState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in IdleState"));
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F("(IdleState) Running..."));
    // TODO: clear memory
};

void IdleState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F("(exit) switching off IdleState"));
};

// error
void IdleState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "handle_error", 0, "wrong state");
};

// self
void IdleState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "run_health_check", 0, "wrong state");
};

// comm
void IdleState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "report_signature_request", 0, "wrong state");
};

void IdleState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "session_new", 0, "wrong state");
};

void IdleState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "report_config", 0, "wrong state");
};

void IdleState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "report_health_check", 0, "wrong state");
};

// update
void IdleState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "update_config", 0, "wrong state");
};

void IdleState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "update_simulation_code", 0, "wrong state");
};

// comm
void IdleState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "session_stop", 0, "wrong state");
};

// sim
void IdleState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "run_simulation", 0, "wrong state");
};

// comm
void IdleState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "IdleState", "report_simulation_data", 0, "wrong state");
};

// self
void IdleState::take_a_nap(FiniteStateMachine *cyclobot) {
    Serial.println(F("(take_a_nap) running..."));
    // reset parameters
    cyclobot->toolsPtr->wifiParametersPtr->scanCount = 0;
    // sleep
    delay(cyclobot->toolsPtr->deviceParametersPtr->sleepLength);
    Serial.println(F("(take_a_nap) done"));
};

// constructor
IdleState::IdleState() {
    Serial.println(F("[IdleState] Instantiated"));
};