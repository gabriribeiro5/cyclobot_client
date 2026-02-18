#pragma once
#include <RTClib.h>
#include "states/BaseState.h"
#include "strategies/BaseStrategy.h"
#include "fsm_tools/CommunicationInstances.h"
#include "fsm_tools/DataInstances.h"
#include "fsm_tools/ParameterInstances.h"
#include "fsm_tools/SelfManagementInstances.h"
#include "fsm_tools/sensor/EcosystemScanner.h"
#include "fsm_tools/actuator/EcosystemActuator.h"
#include "fsm_tools/util/TimeSync.h"

// CycloBot Finite State Machine
class FiniteStateMachine {
    public:
        // time tracking software
        RTC_DS3231 rtc;
        RTC_DS3231 *rtcPtr = &rtc;

        DateTime now;                                   // Track in which step we are
        int stateFlow = 0;                              // Flow stablished at the Client module and updated by States to comply client rules

        // Static long-lived instance groups (allocated once at static initialization)
        static SelfManagementInstances *selfPtr;
        static CommunicationInstances *commPtr;
        static ParameterInstances *paramPtr;
        static DataInstances *dataPtr;
        
        // Static single instances
        static EcosystemScanner *scannerPtr;
        static EcosystemActuator *actuatorPtr;
        static BaseStrategy *simulationStrategyPtr;
        static StrategyContext *simStrategyContextPtr;

        FiniteStateMachine(BaseState *initialStatePtr, BaseStrategy *simStrategyPtr);   // Constructor
        // FiniteStateMachine(const FiniteStateMachine&) = delete;                      // forbid copy constructor
        // FiniteStateMachine& operator=(const FiniteStateMachine&) = delete;           // forbid copy assignment

        void change_state(BaseState *newStatePtr);

        // // error
        // void handle_error();
        
        // // self
        // void run_health_check();

        // // comm
        // void report_signature_request();
        // void session_new();
        // void report_config();
        // void report_health_check();
        
        // // update
        // void update_simulation_code();
        // void update_config();
        
        // // comm
        // void session_stop();

        // // sim
        // void run_simulation();
        
        // // comm
        // void report_simulation_data();
        
        // // self
        // void take_a_nap();

        ~FiniteStateMachine();
        
    private:
        BaseState *currentStatePtr;
};