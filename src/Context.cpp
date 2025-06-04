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

void FiniteStateMachine::report_self_diagnostics() {
    // get milliseconds + log start
    currentState->report_self_diagnostics(this);
    // log end + execution time
}

void FiniteStateMachine::run_simmulation() {
    // get milliseconds + log start
    currentState->run_simmulation(this);
    // log end + execution time
}

void FiniteStateMachine::report_sensor_data_from_simm_state() {
    // get milliseconds + log start
    currentState->report_sensor_data_from_simm_state(this);
    // log end + execution time
}

void FiniteStateMachine::take_a_nap() {
    // get milliseconds + log start
    currentState->take_a_nap(this);
    // log end + execution time
}