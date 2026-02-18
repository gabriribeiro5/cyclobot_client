#include "Arduino.h"
#include "../../../include/states/self/SelfDiagnosisState.h"
#include "../../../include/fsm_tools/self/CheckMyHealth.h"
#include "../../../include/fsm_tools/comm/WifiComm.h"
#include "../../../include/fsm_tools/comm/ClientComm.h"
#include "../../../include/Context.h"

// used by context.changeState
void SelfDiagnosisState::enter(FiniteStateMachine *cyclobot) {    
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *****[SelfDiagnosisState::enter]****  ************************* "));
};

void SelfDiagnosisState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->checkMyHealthPtr->clear_runtime_data(cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  *****[SelfDiagnosisState::exit]*****  ************************* "));
};

// error
void SelfDiagnosisState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "handle_error", 0, "wrong state");
};

// self
void SelfDiagnosisState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[SelfDiagnosisState::run_health_check] Running..."));
    Serial.flush();
    cyclobot->dataPtr->selfDiagnosisDataPtr->diagnosisDateTime = ""; // TODO: apply current date and time
    // *** SENSORS ***
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[SelfDiagnosisState::run_health_check] sensors..."));
    // Wifi sensor
    if (cyclobot->selfPtr->checkMyHealthPtr->is_esp_present(cyclobot->paramPtr->wifiParametersPtr, cyclobot->commPtr->visualCommPtr)) {
        cyclobot->selfPtr->checkMyHealthPtr->check_wifi_firmware_version(cyclobot->paramPtr->wifiParametersPtr,
                                                                            cyclobot->dataPtr->selfDiagnosisDataPtr,
                                                                            cyclobot->commPtr->visualCommPtr);
        cyclobot->selfPtr->checkMyHealthPtr->check_wifi_connection(cyclobot->commPtr->wifiCommPtr,
                                                                    cyclobot->paramPtr->wifiParametersPtr,
                                                                    cyclobot->dataPtr->selfDiagnosisDataPtr,
                                                                    cyclobot->commPtr->visualCommPtr);
        cyclobot->selfPtr->checkMyHealthPtr->check_client_communication(cyclobot->commPtr->clientCommPtr,
                                                                        cyclobot->paramPtr->wifiParametersPtr,
                                                                        cyclobot->paramPtr->clientParametersPtr,
                                                                        cyclobot->dataPtr->selfDiagnosisDataPtr,
                                                                        cyclobot->commPtr->visualCommPtr);
        cyclobot->selfPtr->checkMyHealthPtr->clear_runtime_data(cyclobot->commPtr->visualCommPtr);
    };
    // if (cyclobot->selfPtr->checkMyHealthPtr->wifi_shield_is_on(cyclobot->paramPtr->wifiParametersPtr, cyclobot->commPtr->visualCommPtr)) {
    //     cyclobot->selfPtr->checkMyHealthPtr->check_wifi_firmware_version(cyclobot->paramPtr->wifiParametersPtr,
    //                                                                         cyclobot->dataPtr->selfDiagnosisDataPtr,
    //                                                                         cyclobot->commPtr->visualCommPtr);
    //     cyclobot->selfPtr->checkMyHealthPtr->check_wifi_connection(cyclobot->commPtr->wifiCommPtr,
    //                                                                 cyclobot->paramPtr->wifiParametersPtr,
    //                                                                 cyclobot->dataPtr->selfDiagnosisDataPtr,
    //                                                                 cyclobot->commPtr->visualCommPtr);
    //     cyclobot->selfPtr->checkMyHealthPtr->check_client_communication(cyclobot->commPtr->clientCommPtr,
    //                                                                     cyclobot->paramPtr->wifiParametersPtr,
    //                                                                     cyclobot->paramPtr->clientParametersPtr,
    //                                                                     cyclobot->dataPtr->selfDiagnosisDataPtr,
    //                                                                     cyclobot->commPtr->visualCommPtr);
    //     cyclobot->selfPtr->checkMyHealthPtr->clear_runtime_data(cyclobot->commPtr->visualCommPtr);
    //     }
        
    cyclobot->commPtr->visualCommPtr->print_line(F("[SelfDiagnosisState::run_health_check] actuators..."));
    // *** ACTUATORS ***
    cyclobot->selfPtr->checkMyHealthPtr->check_watering_system(cyclobot->dataPtr->selfDiagnosisDataPtr, cyclobot->commPtr->visualCommPtr);
    cyclobot->selfPtr->checkMyHealthPtr->check_river_system(cyclobot->dataPtr->selfDiagnosisDataPtr, cyclobot->commPtr->visualCommPtr);
    cyclobot->selfPtr->checkMyHealthPtr->check_wind_system(cyclobot->dataPtr->selfDiagnosisDataPtr, cyclobot->commPtr->visualCommPtr);
    cyclobot->selfPtr->checkMyHealthPtr->check_lighting_system(cyclobot->dataPtr->selfDiagnosisDataPtr, cyclobot->commPtr->visualCommPtr);
    cyclobot->selfPtr->checkMyHealthPtr->check_components_list(cyclobot->dataPtr->selfDiagnosisDataPtr, cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->visualCommPtr->print_line(F("[SelfDiagnosisState::run_health_check] done..."));
};

// comm
void SelfDiagnosisState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "report_signature_request", 0, "wrong state");
};

void SelfDiagnosisState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "session_new", 0, "wrong state");
};

void SelfDiagnosisState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "report_config", 0, "wrong state");
};

void SelfDiagnosisState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "report_health_check", 0, "wrong state");
};

// update
void SelfDiagnosisState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "update_config", 0, "wrong state");
};

void SelfDiagnosisState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "update_simulation_code", 0, "wrong state");
};

// comm
void SelfDiagnosisState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "session_stop", 0, "wrong state");
};

// sim
void SelfDiagnosisState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "run_simulation", 0, "wrong state");
};

// comm
void SelfDiagnosisState::report_simulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "report_simulation_data", 0, "wrong state");
};

// self
void SelfDiagnosisState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "SelfDiagnosisState", "take_a_nap", 0, "wrong state");
};

// constructor
SelfDiagnosisState::SelfDiagnosisState() {
    return;
};