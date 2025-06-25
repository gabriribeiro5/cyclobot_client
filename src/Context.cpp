#include "Context.h"
#include <Arduino.h>

void FiniteStateMachine::changeState(BaseState *newState) {
    // get milliseconds + log start
    currentState->exit(this);
    currentState = newState;
    currentState->enter(this);
    // log end + execution time
}

void FiniteStateMachine::run_health_check() {
    // get milliseconds + log start
    currentState->run_health_check(this);
    // log end + execution time
}

void FiniteStateMachine::report_signature_request() {
    // get milliseconds + log start
    currentState->report_signature_request(this);
    // log end + execution time
}

void FiniteStateMachine::session_new() {
    // get milliseconds + log start
    currentState->session_new(this);
    // log end + execution time
}

void FiniteStateMachine::report_config() {
    // get milliseconds + log start
    currentState->report_config(this);
    // log end + execution time
}

void FiniteStateMachine::report_health_check() {
    // get milliseconds + log start
    currentState->report_health_check(this);
    // log end + execution time
}

void FiniteStateMachine::update_config() {
    // get milliseconds + log start
    currentState->update_config(this);
    // log end + execution time
}

void FiniteStateMachine::update_simmulation_code() {
    // get milliseconds + log start
    currentState->update_simmulation_code(this);
    // log end + execution time
}

void FiniteStateMachine::session_stop() {
    // get milliseconds + log start
    currentState->session_stop(this);
    // log end + execution time
}

void FiniteStateMachine::run_simmulation() {
    // get milliseconds + log start
    currentState->run_simmulation(this);
    // log end + execution time
}

void FiniteStateMachine::report_simmulation_data() {
    // get milliseconds + log start
    currentState->report_simmulation_data(this);
    // log end + execution time
}

void FiniteStateMachine::take_a_nap() {
    // get milliseconds + log start
    currentState->take_a_nap(this);
    // log end + execution time
}