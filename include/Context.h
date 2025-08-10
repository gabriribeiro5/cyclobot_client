#pragma once
#include "core_states/BaseState.h"
#include "core_states/simulation/strategy/BaseStrategy.h"
#include "shared/cyclobot_tools/CommunicationInstances.h"
#include "shared/cyclobot_tools/DataInstances.h"
#include "shared/cyclobot_tools/ParameterInstances.h"
#include "shared/cyclobot_tools/SelfManagementInstances.h"
#include "sensor/EnvironmentScan.h"
#include "actuator/EnvironmentActuator.h"
#include "util/TimeSync.h"

class CyclobotInstances;

// CycloBot Finite State Machine
class FiniteStateMachine {
    public:
        // Instance groups
        SelfManagementInstances *selfPtr;
        CommunicationInstances *commPtr;
        ParameterInstances *paramPtr;
        DataInstances *dataPtr;
        
        // Single instance
        BaseStrategy *simulationStrategyPtr;
        EnvironmentScan *envScanPtr;
        EnvironmentActuator *envActuatorPtr;

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