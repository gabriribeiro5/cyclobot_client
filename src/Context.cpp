#include <Arduino.h>
#include "../include/Context.h"
#include "../include/core_states/BaseState.h"
#include "../include/core_states/simulation/strategy/BaseStrategy.h"
#include "../include/shared/cyclobot_tools/CommunicationInstances.h"
#include "../include/shared/cyclobot_tools/DataInstances.h"
#include "../include/shared/cyclobot_tools/ParameterInstances.h"
#include "../include/shared/cyclobot_tools/SelfManagementInstances.h"
#include "../include/sensor/EcosystemScanner.h"
#include "../include/actuator/EcosystemActuator.h"
#include "../include/self/ErrorHandler.h"
#include "../include/util/TimeSync.h"

extern unsigned int __bss_end;   // Symbol marking the end of the .bss section (static & global variables in RAM).
extern void *__brkval;           // Current end of the heap. NULL (0) if no malloc() has been used yet.

FiniteStateMachine::FiniteStateMachine(BaseState *initialStatePtr) {
    currentStatePtr = initialStatePtr;
    // Instance groups
    selfPtr = new SelfManagementInstances();
    commPtr = new CommunicationInstances();
    paramPtr = new ParameterInstances();
    dataPtr = new DataInstances();
    
    // Single instance
    scannerPtr = new EcosystemScanner();
    actuatorPtr = new EcosystemActuator();

    // time tracking software
    RTC_DS3231 rtc;

    DateTime now;      // Track in which step we are
    int stateFlow = 0; // Flow stablished at the Client module and updated by States to comply client rules
}

void FiniteStateMachine::change_state(BaseState *newStatePtr) {
    // get milliseconds + log start
    commPtr->visualCommPtr->print_line(F("[FiniteStateMachine::change_state] changing state..."));
    currentStatePtr->exit(this);
    commPtr->visualCommPtr->print_line(F("[FiniteStateMachine::change_state] exited current state"));
    currentStatePtr = newStatePtr;
    commPtr->visualCommPtr->print_line(F("[FiniteStateMachine::change_state] new state assigned"));
    currentStatePtr->enter(this);
    commPtr->visualCommPtr->print_line(F("[FiniteStateMachine::change_state] entered new state"));
}

void FiniteStateMachine::handle_error() {
    // get milliseconds + log start
    currentStatePtr->handle_error(this);
    // log end + execution time
}

void FiniteStateMachine::run_health_check() {
    // get milliseconds + log start
    commPtr->visualCommPtr->print_line(F("[FiniteStateMachine::run_health_check] running..."));
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