#pragma once
#include <RTClib.h>
#include "core_states/BaseState.h"
#include "shared/fsm_context_tools/CommunicationInstances.h"
#include "shared/fsm_context_tools/DataInstances.h"
#include "shared/fsm_context_tools/ParameterInstances.h"
#include "sensor/EcosystemScanner.h"

// CycloBot Finite State Machine
class FiniteStateMachine {
    public:
        // Instance groups
        CommunicationInstances *commPtr;
        ParameterInstances *paramPtr;
        DataInstances *dataPtr;

        // time tracking software
        RTC_DS3231 rtc;

        DateTime now;    // Track in which step we are
        int stateFlow = 0; // Flow stablished at the Client module and updated by States to comply client rules
    
        FiniteStateMachine(BaseState *initialStatePtr); // Constructor
        void printFreeMemory(char *currentMethodPtr);
        void change_state(BaseState *newStatePtr);
        
        // comm
        void report_signature_request();
        void session_new();
        void report_config();
        void report_health_check();
        
        void session_stop();
        
        // self
        void take_a_nap();
        
    private:
        BaseState *currentStatePtr;
};