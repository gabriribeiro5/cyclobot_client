#include "Arduino.h"
#include "../../../include/core_states/self/IdleState.h"
#include "../../../include/Context.h"
// used by context.changeState
void IdleState::enter(FiniteStateMachine *fsm_context) {
    if (!fsm_context) {
        Serial.println(F("[IdleState::enter] fsm_context pointer is null in IdleState"));
        Serial.flush();
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F(" *************************  *********[IdleState::enter]*********  ************************* "));
    Serial.flush();
    // TODO: clear memory
};

void IdleState::exit(FiniteStateMachine *fsm_context) {
    Serial.println(F(" *************************  *********[IdleState::exit]**********  ************************* "));
    Serial.flush();
};

// comm
void IdleState::report_signature_request(FiniteStateMachine *fsm_context) {
    // fsm_context->selfPtr->errorHandlerPtr->log_error_msg(fsm_context->paramPtr->errorHandlingParametersPtr, "IdleState", "report_signature_request", 0, "wrong state");
    return;
};

void IdleState::session_new(FiniteStateMachine *fsm_context) {
    // fsm_context->selfPtr->errorHandlerPtr->log_error_msg(fsm_context->paramPtr->errorHandlingParametersPtr, "IdleState", "session_new", 0, "wrong state");
    return;
};

void IdleState::report_config(FiniteStateMachine *fsm_context) {
    // fsm_context->selfPtr->errorHandlerPtr->log_error_msg(fsm_context->paramPtr->errorHandlingParametersPtr, "IdleState", "report_config", 0, "wrong state");
    return;
};

void IdleState::report_health_check(FiniteStateMachine *fsm_context) {
    // fsm_context->selfPtr->errorHandlerPtr->log_error_msg(fsm_context->paramPtr->errorHandlingParametersPtr, "IdleState", "report_health_check", 0, "wrong state");
    return;
};

// comm
void IdleState::session_stop(FiniteStateMachine *fsm_context) {
    // fsm_context->selfPtr->errorHandlerPtr->log_error_msg(fsm_context->paramPtr->errorHandlingParametersPtr, "IdleState", "session_stop", 0, "wrong state");
    return;
};

void IdleState::take_a_nap(FiniteStateMachine *fsm_context) {
    Serial.println(F("[IdleState::take_a_nap] running..."));
    Serial.flush();
    // reset parameters
    fsm_context->paramPtr->wifiParametersPtr->scanCount = 0;
    // sleep
    delay(fsm_context->paramPtr->deviceParametersPtr->sleepLength);
    Serial.println(F("[IdleState::take_a_nap] done"));
    Serial.flush();
};

// constructor
IdleState::IdleState() {
    return;
};