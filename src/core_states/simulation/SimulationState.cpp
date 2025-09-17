#include "Arduino.h"
#include "../../../include/core_states/simulation/SimulationState.h"
#include "../../../include/core_states/simulation/SimStrategy.h"
#include "../../../include/Context.h"

// used by context.changeState
void SimulationState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        cyclobot->commPtr->visualCommPtr->print_line(F("[SimulationState::enter] cyclobot pointer is null in SimulationState"));
        return; // ou transição para um estado de erro seguro
    }
    
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  ******[SimulationState::enter]******  ************************* "));
};

void SimulationState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  ******[SimulationState::exit]*******  ************************* "));
};

// error
void SimulationState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "handle_error", 0, "wrong state");
};

// self
void SimulationState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "run_health_check", 0, "wrong state");
};

// comm
void SimulationState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "report_signature_request", 0, "wrong state");
};

void SimulationState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "session_new", 0, "wrong state");
};

void SimulationState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "report_config", 0, "wrong state");
};

void SimulationState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "report_health_check", 0, "wrong state");
};

// update
void SimulationState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "update_config", 0, "wrong state");
};

void SimulationState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "update_simulation_code", 0, "wrong state");
};

// comm
void SimulationState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "session_stop", 0, "wrong state");
};

// sim
void SimulationState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[SimulationState::run_simulation] running..."));    
    if (simStrategyPtr) {
        delete simStrategyPtr;
    }
    
    simStrategyPtr = new SimStrategy(cyclobot->simulationStrategyPtr);
    
    if (cyclobot->paramPtr->deviceParametersPtr->firstAwakening) {
        cyclobot->commPtr->visualCommPtr->print_line(F("[SimulationState::run_simulation] calling pin setup method"));
        simStrategyPtr->setup(cyclobot->commPtr->visualCommPtr);
        cyclobot->paramPtr->deviceParametersPtr->firstAwakening = false;
    }
    
    cyclobot->paramPtr->ecosystemParametersPtr->eventStart = cyclobot->rtc.now();
    simStrategyPtr->simulate_ecosystem(cyclobot->paramPtr->ecosystemParametersPtr,
                                       cyclobot->scannerPtr,
                                       cyclobot->actuatorPtr,
                                       cyclobot->commPtr->visualCommPtr);
    cyclobot->paramPtr->ecosystemParametersPtr->eventEnd = cyclobot->rtc.now();
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[SimulationState::run_simulation] done"));
};

// comm
void SimulationState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "report_simulation_data", 0, "wrong state");
};

// self
void SimulationState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SimulationState", "take_a_nap", 0, "wrong state");
};

// constructor
SimulationState::SimulationState() {
    simStrategyPtr = nullptr;
};

// destructor
SimulationState::~SimulationState() {
    if (simStrategyPtr) {
        delete simStrategyPtr;
        simStrategyPtr = nullptr;
    }
};