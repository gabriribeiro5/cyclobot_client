#include <Arduino.h>
#include "../include/Context.h"
#include "../include/strategies/BaseStrategy.h"
#include "../include/states/BaseState.h"
#include "../include/fsm_tools/CommunicationInstances.h"
#include "../include/fsm_tools/DataInstances.h"
#include "../include/fsm_tools/ParameterInstances.h"
#include "../include/fsm_tools/SelfManagementInstances.h"
#include "../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../include/fsm_tools/self/ErrorHandler.h"
#include "../include/fsm_tools/util/TimeSync.h"

extern unsigned int __bss_end;   // Symbol marking the end of the .bss section (static & global variables in RAM).
extern void *__brkval;           // Current end of the heap. NULL (0) if no malloc() has been used yet.

// Static member initialization (allocated once at startup, reused across FSM lifetime)
SelfManagementInstances *FiniteStateMachine::selfPtr = nullptr;
CommunicationInstances *FiniteStateMachine::commPtr = nullptr;
ParameterInstances *FiniteStateMachine::paramPtr = nullptr;
DataInstances *FiniteStateMachine::dataPtr = nullptr;
EcosystemScanner *FiniteStateMachine::scannerPtr = nullptr;
EcosystemActuator *FiniteStateMachine::actuatorPtr = nullptr;
BaseStrategy *FiniteStateMachine::simulationStrategyPtr = nullptr;
StrategyContext *FiniteStateMachine::simStrategyContextPtr = nullptr;

FiniteStateMachine::FiniteStateMachine(BaseState *initialStatePtr, BaseStrategy *simStrategyPtr) {
    currentStatePtr = initialStatePtr;
    FiniteStateMachine::simulationStrategyPtr = simStrategyPtr;

    // time tracking software
    Serial.println("RTC_DS3231 instance created");
    Serial.flush();

    Serial.println("DateTime instance created");
    Serial.flush();
    
    Serial.println("stateFlow variable created");
    Serial.flush();

    // Initialize static long-lived instances only once (on first FSM creation)
    if (scannerPtr == nullptr) {
        scannerPtr = new EcosystemScanner();
        Serial.println("EcosystemScanner instance created");
        Serial.flush();
        actuatorPtr = new EcosystemActuator();
        Serial.println("EcosystemActuator instance created");
        Serial.flush();
        
        paramPtr = new ParameterInstances();
        Serial.println("ParameterInstances instance created");
        Serial.flush();
        selfPtr = new SelfManagementInstances();
        Serial.println("SelfManagementInstances instance created");
        Serial.flush();
        commPtr = new CommunicationInstances();
        Serial.println("CommunicationInstances instance created");
        Serial.flush();
        dataPtr = new DataInstances();
        Serial.println("DataInstances instance created");
        Serial.flush();

        simStrategyContextPtr = new StrategyContext(dataPtr->configDataPtr, FiniteStateMachine::simulationStrategyPtr, commPtr->visualCommPtr, rtcPtr);
        Serial.println("StrategyContext instance created");
        Serial.flush();
    } else {
        Serial.println("Static instances already initialized (reusing from previous FSM)");
        Serial.flush();
    }
}

void FiniteStateMachine::change_state(BaseState *newStatePtr) {
    if (currentStatePtr) {
        currentStatePtr->exit(this);
        delete currentStatePtr;          // free the previous state
    }
    currentStatePtr = newStatePtr;
    if (currentStatePtr) currentStatePtr->enter(this);
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

void FiniteStateMachine::update_simulation_code() {
    // get milliseconds + log start
    currentStatePtr->update_simulation_code(this);
    // log end + execution time
}

void FiniteStateMachine::session_stop() {
    // get milliseconds + log start
    currentStatePtr->session_stop(this);
    // log end + execution time
}

void FiniteStateMachine::run_simulation() {
    // get milliseconds + log start
    currentStatePtr->run_simulation(this);
    // log end + execution time
}

void FiniteStateMachine::report_simulation_data() {
    // get milliseconds + log start
    currentStatePtr->report_simulation_data(this);
    // log end + execution time
}

void FiniteStateMachine::take_a_nap() {
    // get milliseconds + log start
    currentStatePtr->take_a_nap(this);
    // log end + execution time
}

FiniteStateMachine::~FiniteStateMachine() {
    // Only delete the transient current state
    delete currentStatePtr;
    // Static long-lived instances are NOT deleted here; they persist for the FSM lifetime
    // This reduces repeated allocation/deallocation cycles and heap fragmentation
}