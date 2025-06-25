#pragma once
#include "BaseState.h"
#include "TimeSync.h"

// CycloBot Finite State Machine
class FiniteStateMachine {
    public:
        BaseState *currentState;
        int currentTime = getCurrentHour(); // Track in which step we are
        int stateFlow = 0; // Flow stablished at the Client module and updated by States to comply client rules
    
        FiniteStateMachine(BaseState *currentState); // Constructor
        void change_state(BaseState *newState);
        void update_current_time();

        // error
        void report_error();

        // self
        void run_health_check();

        // comm
        void report_health_check();

        // update
        void update_simmulation_code();
        void update_config();
        
        // simm
        void run_simmulation();
        
        // comm
        void report_simmulation_data();
        
        // self
        void take_a_nap();
        
    private:
        BaseState *newState;
};