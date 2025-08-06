#include "Arduino.h"
#include "../../../include/core_states/comm/HTTPClientState.h"
#include "../../../include/Context.h"
#include "../../../include/shared/SharedInstances.h"
// used by context.changeState
void HTTPClientState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("(enter): cyclobot pointer is null in HTTPClientState"));
        return;
    }    
    Serial.println(F("(HTTPClientState) Running..."));
};

void HTTPClientState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F("(exit) switching off HTTPClientState"));
};

// error
void HTTPClientState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "HTTPClientState", "handle_error", 0, "wrong state");
    
    // start error protocol
    cyclobot->stateFlow = 98;
    return;
};

// self
void HTTPClientState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "HTTPClientState", "run_health_check", 0, "wrong state");
};

// comm
void HTTPClientState::report_signature_request(FiniteStateMachine *cyclobot) {
    Serial.println(F("(report_signature_request): running..."));
    if (cyclobot->toolsPtr->deviceParametersPtr->firstAwakening) {
        cyclobot->toolsPtr->clientCommPtr->post_signature_request(cyclobot->toolsPtr->clientParametersPtr,
                                                                  cyclobot->toolsPtr->wifiParametersPtr,
                                                                  cyclobot->toolsPtr->deviceParametersPtr);
        cyclobot->toolsPtr->deviceParametersPtr->firstAwakening = false;
        Serial.println(F("(report_signature_request): cyclobot approved"));
    } else {
        Serial.println(F("(report_signature_request): skipped"));
    }
};

void HTTPClientState::session_new(FiniteStateMachine *cyclobot) {
    Serial.println(F("(session_new) running..."));
    cyclobot->toolsPtr->clientCommPtr->get_cyclobot_session_token(cyclobot->toolsPtr->clientParametersPtr,
                                                                  cyclobot->toolsPtr->wifiParametersPtr,
                                                                  cyclobot->toolsPtr->deviceParametersPtr);
    Serial.println(F("(session_new) done"));
};

void HTTPClientState::report_config(FiniteStateMachine *cyclobot) {
    Serial.println(F("(report_config) running..."));
    cyclobot->toolsPtr->clientCommPtr->post_cyclobot_config(cyclobot->toolsPtr->clientParametersPtr,
                                                            cyclobot->toolsPtr->wifiParametersPtr,
                                                            cyclobot->toolsPtr->deviceParametersPtr,
                                                            cyclobot->toolsPtr->configDataPtr,
                                                            cyclobot->toolsPtr->ecosystemParametersPtr);
    Serial.println(F("(report_config) done"));
};

void HTTPClientState::report_health_check(FiniteStateMachine *cyclobot) {
    Serial.println(F("(report_health_check) running..."));
    cyclobot->toolsPtr->clientCommPtr->post_cyclobot_diagnosis(cyclobot->toolsPtr->clientParametersPtr,
                                                               cyclobot->toolsPtr->wifiParametersPtr,
                                                               cyclobot->toolsPtr->deviceParametersPtr,
                                                               cyclobot->toolsPtr->selfDiagnosisDataPtr);
    Serial.println(F("(report_health_check) done"));
};

// update
void HTTPClientState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "HTTPClientState", "update_config", 0, "wrong state");
};

void HTTPClientState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "HTTPClientState", "update_simulation_code", 0, "wrong state");
};

// comm
void HTTPClientState::session_stop(FiniteStateMachine *cyclobot) {
    Serial.println(F("(session_stop) running..."));
    cyclobot->toolsPtr->clientCommPtr->put_invalid_cyclobot_session_token();
    cyclobot->toolsPtr->wifiCommPtr->disconnect_wifi();
    Serial.println(F("(session_stop) done"));
};

// sim
void HTTPClientState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "HTTPClientState", "run_simulation", 0, "wrong state");
};

// comm
void HTTPClientState::report_simulation_data(FiniteStateMachine *cyclobot) {
    // This method must start (and stop) both Client and Session
    Serial.println(F("(report_simulation_data) running..."));
    cyclobot->toolsPtr->wifiCommPtr->connect_wifi(cyclobot->toolsPtr->wifiParametersPtr);
    cyclobot->toolsPtr->clientCommPtr->get_cyclobot_session_token(cyclobot->toolsPtr->clientParametersPtr, cyclobot->toolsPtr->wifiParametersPtr, cyclobot->toolsPtr->deviceParametersPtr);
    cyclobot->toolsPtr->clientCommPtr->post_cyclobot_environment_state();
    session_stop(cyclobot);
    Serial.println(F("(report_simulation_data) done"));
};

// self
void HTTPClientState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->toolsPtr->errorHandlerPtr->log_error_msg(cyclobot->toolsPtr->errorHandlingParametersPtr, "HTTPClientState", "take_a_nap", 0, "wrong state");
};

// constructor
HTTPClientState::HTTPClientState() {
    Serial.println(F("[HTTPClientState] Instantiated..."));
};