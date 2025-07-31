#include "Arduino.h"
#include "../../../include/core_states/self/SelfDiagnosisState.h"
#include "../../../include/util/StateTransitionException.h"

#include "../../../include/self/CheckMyHealth.h"
#include "../../../include/comm/WifiComm.h"
#include "../../../include/comm/ClientComm.h"
#include "../../../include/Context.h"

// used by context.changeState
void SelfDiagnosisState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in SelfDiagnosisState"));
        return; // ou transição para um estado de erro seguro
    }
    
    Serial.println(F("(SelfDiagnosisState) Running..."));
};

void SelfDiagnosisState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->checkMyHealthPtr->clear_runtime_data();
    Serial.println(F("(exit) switching off SelfDiagnosisState"));
};

// error
void SelfDiagnosisState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "handle_error", 0, "wrong state");
};

// self
void SelfDiagnosisState::run_health_check(FiniteStateMachine *cyclobot) {
    Serial.println(F("(run_health_check) Running..."));
    cyclobot->toolsPtr->selfDiagnosisDataPtr->diagnosisDateTime = ""; // TODO: apply current date and time
    // *** SENSORS ***
    
    // Wifi sensor
    if (cyclobot->toolsPtr->checkMyHealthPtr->wifi_shield_is_on(cyclobot->toolsPtr->wifiParametersPtr)) { // check for the presence of the shield
        cyclobot->toolsPtr->checkMyHealthPtr->check_wifi_firmware_version(cyclobot->toolsPtr->wifiParametersPtr, cyclobot->toolsPtr->selfDiagnosisDataPtr);
        cyclobot->toolsPtr->checkMyHealthPtr->check_wifi_connection(cyclobot->toolsPtr->wifiCommPtr, cyclobot->toolsPtr->wifiParametersPtr, cyclobot->toolsPtr->selfDiagnosisDataPtr);
        cyclobot->toolsPtr->checkMyHealthPtr->check_client_communication(cyclobot->toolsPtr->clientCommPtr,
                                                                         cyclobot->toolsPtr->wifiParametersPtr,
                                                                         cyclobot->toolsPtr->clientParametersPtr,
                                                                         cyclobot->toolsPtr->selfDiagnosisDataPtr);
        cyclobot->toolsPtr->checkMyHealthPtr->clear_runtime_data();
    }

    // *** ACTUATORS ***
    cyclobot->toolsPtr->checkMyHealthPtr->check_watering_system(cyclobot->toolsPtr->selfDiagnosisDataPtr);
    cyclobot->toolsPtr->checkMyHealthPtr->check_river_system(cyclobot->toolsPtr->selfDiagnosisDataPtr);
    cyclobot->toolsPtr->checkMyHealthPtr->check_wind_system(cyclobot->toolsPtr->selfDiagnosisDataPtr);
    cyclobot->toolsPtr->checkMyHealthPtr->check_lighting_system(cyclobot->toolsPtr->selfDiagnosisDataPtr);
    cyclobot->toolsPtr->checkMyHealthPtr->check_components_list(cyclobot->toolsPtr->selfDiagnosisDataPtr);
};

// comm
void SelfDiagnosisState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "report_signature_request", 0, "wrong state");
};

void SelfDiagnosisState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "session_new", 0, "wrong state");
};

void SelfDiagnosisState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "report_config", 0, "wrong state");
};

void SelfDiagnosisState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "report_health_check", 0, "wrong state");
};

// update
void SelfDiagnosisState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "update_config", 0, "wrong state");
};

void SelfDiagnosisState::update_simmulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "update_simmulation_code", 0, "wrong state");
};

// comm
void SelfDiagnosisState::session_stop(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "session_stop", 0, "wrong state");
};

// simm
void SelfDiagnosisState::run_simmulation(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "run_simmulation", 0, "wrong state");
};

// comm
void SelfDiagnosisState::report_simmulation_data(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "report_simmulation_data", 0, "wrong state");
};

// self
void SelfDiagnosisState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "SelfDiagnosisState", "take_a_nap", 0, "wrong state");
};

// constructor
SelfDiagnosisState::SelfDiagnosisState() {
    Serial.println(F("[SelfDiagnosisState] Instantiated..."));
};