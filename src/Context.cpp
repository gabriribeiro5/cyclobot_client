#include <Arduino.h>
#include "..\include\Context.h"
#include "..\include\core_states\BaseState.h"
#include "..\include\self\ErrorHandler.h"
#include "..\include\util\TimeSync.h"

extern unsigned int __bss_end;   // Symbol marking the end of the .bss section (static & global variables in RAM).
extern void *__brkval;           // Current end of the heap. NULL (0) if no malloc() has been used yet.

FiniteStateMachine::FiniteStateMachine(BaseState *initialStatePtr) {
    currentStatePtr = initialStatePtr;
}

void FiniteStateMachine::printFreeMemory(char *currentMethodPtr) {
  int free_memory;
  
  // If the heap hasn't been used (__brkval == 0)
  if ((int)__brkval == 0) {
    // free space = (address of local var / stack pointer) - (end of bss section)
    free_memory = ((int)&free_memory) - ((int)&__bss_end);
  } else {
    // Otherwise, heap is in use
    // free space = (address of local var / stack pointer) - (current end of heap)
    free_memory = ((int)&free_memory) - ((int)__brkval);
  }

  Serial.print(currentMethodPtr);
  Serial.print(" Free Memory: ");
  Serial.print(free_memory);
  Serial.println(" bytes");
}

void FiniteStateMachine::change_state(BaseState *newStatePtr) {
    // get milliseconds + log start
    currentStatePtr->exit(this);
    currentStatePtr = newStatePtr;
    currentStatePtr->enter(this); // complete this line
    // log end + execution time
}

void FiniteStateMachine::handle_error() {
    // get milliseconds + log start
    currentStatePtr->handle_error(this);
    // log end + execution time
}

void FiniteStateMachine::run_health_check() {
    // get milliseconds + log start
    Serial.println(F("[FiniteStateMachine::run_health_check] running..."));
    Serial.flush(); // Wait until all outgoing serial data has been transmitted
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