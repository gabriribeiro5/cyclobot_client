#include "Arduino.h"
#include "../../../include/states/simulation/SimulationState.h"
#include "../../../include/StrategyContext.h"
#include "../../../include/Context.h"

// used by context.changeState
void SimulationState::enter(FiniteStateMachine *cyclobot) {    
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
    cyclobot->commPtr->visualCommPtr->print_line(F("[SimulationState::run_simulation] capturing simulation start time"));
    cyclobot->paramPtr->ecosystemParametersPtr->eventStart = cyclobot->rtc.now();
    
    cyclobot->commPtr->visualCommPtr->print(F("[SimulationState::run_simulation] starting simulation at "));
    cyclobot->commPtr->visualCommPtr->print_line(cyclobot->paramPtr->ecosystemParametersPtr->eventStart.timestamp());
    cyclobot->simStrategyContextPtr->simulate_ecosystem(cyclobot->scannerPtr,
                                            cyclobot->actuatorPtr,
                                            cyclobot->dataPtr->configDataPtr,
                                            cyclobot->simulationStrategyPtr,
                                            cyclobot->commPtr->visualCommPtr,
                                            cyclobot->rtcPtr);
    cyclobot->commPtr->visualCommPtr->print(F("[SimulationState::run_simulation] simulation finished at "));
    cyclobot->paramPtr->ecosystemParametersPtr->eventEnd = cyclobot->rtc.now();
    cyclobot->commPtr->visualCommPtr->print_line(cyclobot->paramPtr->ecosystemParametersPtr->eventEnd.timestamp());
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
};
