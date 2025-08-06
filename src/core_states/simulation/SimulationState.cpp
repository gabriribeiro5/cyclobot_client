#include "Arduino.h"
#include "../../../include/core_states/simulation/SimulationState.h"
#include "../../../include/Context.h"

// used by context.changeState
void SimulationState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in SimulationState"));
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F("(SimulationState) Running..."));
};

void SimulationState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F("(exit) switching off SimulationState"));
};

// error
void SimulationState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "handle_error", 0, "wrong state");
};

// self
void SimulationState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "run_health_check", 0, "wrong state");
};

// comm
void SimulationState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "report_signature_request", 0, "wrong state");
};

void SimulationState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "session_new", 0, "wrong state");
};

void SimulationState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "report_config", 0, "wrong state");
};

void SimulationState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "report_health_check", 0, "wrong state");
};

// update
void SimulationState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "update_config", 0, "wrong state");
};

void SimulationState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "update_simulation_code", 0, "wrong state");
};

// comm
void SimulationState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "session_stop", 0, "wrong state");
};

// sim
void SimulationState::run_simulation(FiniteStateMachine *cyclobot) {
    Serial.println(F("(run_simulation) running..."));    
    /* ********* START ACTUATORS (USE TIMEOUTS) ********* */
    // LATCHING RELAY COMMAND OUTPUTS WITH DRIVERS
    // --> Fan system
    cyclobot->toolsPtr->environmentActuatorPtr->fan_system_on(cyclobot->toolsPtr->ecosystemParametersPtr, cyclobot->toolsPtr->peripheralMappingPtr);
    // --> Irrigation system
    cyclobot->toolsPtr->environmentActuatorPtr->irrigation_system_on(cyclobot->toolsPtr->ecosystemParametersPtr, cyclobot->toolsPtr->peripheralMappingPtr);
    
    /* ********* STOP ACTUATORS (USE TIMEOUTS) ********* */
    // --> Fan system
    cyclobot->toolsPtr->environmentActuatorPtr->fan_system_off(cyclobot->toolsPtr->ecosystemParametersPtr, cyclobot->toolsPtr->peripheralMappingPtr);
    // --> Irrigation system
    cyclobot->toolsPtr->environmentActuatorPtr->irrigation_system_off(cyclobot->toolsPtr->ecosystemParametersPtr, cyclobot->toolsPtr->peripheralMappingPtr);
    

    /* ********* REMOTE PROCEDURE CALLS ********* */
    // BLUETOOTH || MKR NB 1500 (LTE Cat-M1 / NB-IoT) || WAN 1310 (LoRa / LoRaWAN)
    // --> Trimming system
    cyclobot->toolsPtr->environmentActuatorPtr->trim_system_on(cyclobot->toolsPtr->ecosystemParametersPtr, cyclobot->toolsPtr->peripheralMappingPtr);

    Serial.println(F("(run_simulation) done"));
};

// comm
void SimulationState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "report_simulation_data", 0, "wrong state");
};

// self
void SimulationState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SimulationState", "take_a_nap", 0, "wrong state");
};

// constructor
SimulationState::SimulationState() {
    Serial.println(F("(SimulationState): Instantiated..."));
};