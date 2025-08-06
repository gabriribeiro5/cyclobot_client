#pragma once
#include "core_states\BaseState.h"
#include "shared\SharedInstances.h"
#include "util\TimeSync.h"

class SharedInstances;

// CycloBot Finite State Machine
class FiniteStateMachine {
    public:
        SharedInstances *toolsPtr;
        
        int currentTime;    // Track in which step we are
        int stateFlow = 0; // Flow stablished at the Client module and updated by States to comply client rules
    
        FiniteStateMachine(BaseState *initialStatePtr); // Constructor
        void change_state(BaseState *newStatePtr);
        void update_current_time();
        
        // error
        void handle_error();
        
        // self
        void run_health_check();

        // comm
        void report_signature_request();
        void session_new();
        void report_config();
        void report_health_check();
        
        // update
        void update_simulation_code();
        void update_config();
        
        // comm
        void session_stop();

        // sim
        void run_simulation();
        
        // comm
        void report_simulation_data();
        
        // self
        void take_a_nap();
        
    private:
        BaseState *currentStatePtr;
};