#include "Arduino.h"
#include "../../../include/core_states/simulation/SimulationState.h"
#include "../../../include/core_states/simulation/SimStrategy.h"
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
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "handle_error", 0, "wrong state");
};

// self
void SimulationState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "run_health_check", 0, "wrong state");
};

// comm
void SimulationState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "report_signature_request", 0, "wrong state");
};

void SimulationState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "session_new", 0, "wrong state");
};

void SimulationState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "report_config", 0, "wrong state");
};

void SimulationState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "report_health_check", 0, "wrong state");
};

// update
void SimulationState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "update_config", 0, "wrong state");
};

void SimulationState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "update_simulation_code", 0, "wrong state");
};

// comm
void SimulationState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "session_stop", 0, "wrong state");
};

// sim
void SimulationState::run_simulation(FiniteStateMachine *cyclobot) {
    Serial.println(F("(run_simulation) running..."));
    
    if (simStrategyPtr) {
        delete simStrategyPtr;
    }
    simStrategyPtr = new SimStrategy(cyclobot->simulationStrategyPtr);
    
    if (cyclobot->paramPtr->deviceParametersPtr->firstAwakening) {
        simStrategyPtr->setup();
        cyclobot->paramPtr->deviceParametersPtr->firstAwakening = false;
    }
    
    cyclobot->paramPtr->ecosystemParametersPtr->eventStart = cyclobot->rtc.now();
    simStrategyPtr->simulate_ecosystem(cyclobot->paramPtr->ecosystemParametersPtr,
                                       cyclobot->scannerPtr,
                                       cyclobot->actuatorPtr);   
    cyclobot->paramPtr->ecosystemParametersPtr->eventEnd = cyclobot->rtc.now();
    
    Serial.println(F("(run_simulation) done"));
};

// comm
void SimulationState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "report_simulation_data", 0, "wrong state");
};

// self
void SimulationState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "SimulationState", "take_a_nap", 0, "wrong state");
};

// constructor
SimulationState::SimulationState() {
    Serial.println(F("(SimulationState): Instantiated..."));
    simStrategyPtr = nullptr;
};

// destructor
SimulationState::~SimulationState() {
    if (simStrategyPtr) {
        delete simStrategyPtr;
        simStrategyPtr = nullptr;
    }
};