#include <Arduino.h>
#include "..\include\Context.h"
#include "..\include\core_states\BaseState.h"
#include "..\include\self\ErrorHandler.h"
#include "..\include\util\TimeSync.h"

FiniteStateMachine::FiniteStateMachine(BaseState *initialStatePtr) {
    currentStatePtr = initialStatePtr;
}

void FiniteStateMachine::change_state(BaseState *newState) {
    // get milliseconds + log start
    currentStatePtr->exit(this);
    currentStatePtr = newState;
    currentStatePtr->enter(this); // complete this line
    // log end + execution time
}

void FiniteStateMachine::handle_error() {
    // get milliseconds + log start
    currentStatePtr->handle_error(this);
    // log end + execution time
}

void FiniteStateMachine::run_health_check() {
    // get milliseconds + log start
    currentStatePtr->run_health_check(this);
    // log end + execution time
}

void FiniteStateMachine::report_signature_request() {
    // get milliseconds + log start
    currentStatePtr->report_signature_request(this);
    // log end + execution time
}

void FiniteStateMachine::session_new() {
    // get milliseconds + log start
    currentStatePtr->session_new(this);
    // log end + execution time
}

void FiniteStateMachine::report_config() {
    // get milliseconds + log start
    currentStatePtr->report_config(this);
    // log end + execution time
}

void FiniteStateMachine::report_health_check() {
    // get milliseconds + log start
    currentStatePtr->report_health_check(this);
    // log end + execution time
}

void FiniteStateMachine::update_config() {
    // get milliseconds + log start
    currentStatePtr->update_config(this);
    // log end + execution time
}

void FiniteStateMachine::update_simmulation_code() {
    // get milliseconds + log start
    currentStatePtr->update_simmulation_code(this);
    // log end + execution time
}

void FiniteStateMachine::session_stop() {
    // get milliseconds + log start
    currentStatePtr->session_stop(this);
    // log end + execution time
}

void FiniteStateMachine::run_simmulation() {
    // get milliseconds + log start
    currentStatePtr->run_simmulation(this);
    // log end + execution time
}

void FiniteStateMachine::report_simmulation_data() {
    // get milliseconds + log start
    currentStatePtr->report_simmulation_data(this);
    // log end + execution time
}

void FiniteStateMachine::take_a_nap() {
    // get milliseconds + log start
    currentStatePtr->take_a_nap(this);
    // log end + execution time
}