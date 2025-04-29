#pragma once
#include "BaseState.h"

// Eco Unit Finite State Machine
class FiniteStateMachine {
    public:
        BaseState *currentState;
        int stateFlow = 0; // Track which step we are on
    
        FiniteStateMachine(BaseState *currentState);
        void changeState(BaseState *newState);
        void execute();
        
    private:
        BaseState* newState
};