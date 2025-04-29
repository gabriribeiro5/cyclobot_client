#include "Context.h"
#include <Arduino.h>

void FiniteStateMachine::changeState(BaseState *newState) {
    // get milliseconds + log start
    currentState->exit(this);
    currentState = newState;
    currentState->enter(this);
    // log end + execution time
}

void FiniteStateMachine::execute() {
    // get milliseconds + log start
    currentState->execute(this);
    // log end + execution time
}