#include "Arduino.h"
#include "../../../include/core_states/comm/HTTPClientState.h"
#include "../../../include/Context.h"

// used by context.changeState
void HTTPClientState::enter(FiniteStateMachine *cyclobot) {
    if (!cyclobot) {
        Serial.println(F("[HTTPClientState::enter] cyclobot pointer is null in HTTPClientState"));
        return;
    }
    Serial.println(F(" *************************  ******[HTTPClientState::enter]******  ************************* "));
};

void HTTPClientState::exit(FiniteStateMachine *cyclobot) {
    Serial.println(F(" *************************  ******[HTTPClientState::exit]*******  ************************* "));
};

// error
void HTTPClientState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "handle_error", 0, "wrong state");
    
    // start error protocol
    cyclobot->stateFlow = 98;
    return;
};

// self
void HTTPClientState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "run_health_check", 0, "wrong state");
};

// comm
void HTTPClientState::report_signature_request(FiniteStateMachine *cyclobot) {
    Serial.println(F("[HTTPClientState::report_signature_request] running..."));
    if (cyclobot->paramPtr->deviceParametersPtr->firstAwakening) {
        cyclobot->commPtr->clientCommPtr->post_signature_request(cyclobot->paramPtr->clientParametersPtr,
                                                                  cyclobot->paramPtr->wifiParametersPtr,
                                                                  cyclobot->paramPtr->deviceParametersPtr);
        cyclobot->paramPtr->deviceParametersPtr->firstAwakening = false;
        Serial.println(F("[HTTPClientState::report_signature_request] cyclobot approved"));
    } else {
        Serial.println(F("[HTTPClientState::report_signature_request] skipped"));
    }
};

void HTTPClientState::session_new(FiniteStateMachine *cyclobot) {
    Serial.println(F("[HTTPClientState::session_new] running..."));
    cyclobot->printFreeMemory("[HTTPClientState::session_new]");
    cyclobot->commPtr->clientCommPtr->get_cyclobot_session_token(cyclobot->paramPtr->clientParametersPtr,
                                                                  cyclobot->paramPtr->wifiParametersPtr,
                                                                  cyclobot->paramPtr->deviceParametersPtr);
    Serial.println(F("[HTTPClientState::session_new] done"));
};

void HTTPClientState::report_config(FiniteStateMachine *cyclobot) {
    Serial.println(F("[HTTPClientState::report_config] running..."));
    cyclobot->commPtr->clientCommPtr->post_cyclobot_config(cyclobot->paramPtr->clientParametersPtr,
                                                            cyclobot->paramPtr->wifiParametersPtr,
                                                            cyclobot->paramPtr->deviceParametersPtr,
                                                            cyclobot->dataPtr->configDataPtr,
                                                            cyclobot->paramPtr->ecosystemParametersPtr);
    Serial.println(F("[HTTPClientState::report_config] done"));
};

void HTTPClientState::report_health_check(FiniteStateMachine *cyclobot) {
    Serial.println(F("[HTTPClientState::report_health_check] running..."));
    cyclobot->commPtr->clientCommPtr->post_cyclobot_diagnosis(cyclobot->paramPtr->clientParametersPtr,
                                                               cyclobot->paramPtr->wifiParametersPtr,
                                                               cyclobot->paramPtr->deviceParametersPtr,
                                                               cyclobot->dataPtr->selfDiagnosisDataPtr);
    Serial.println(F("[HTTPClientState::report_health_check] done"));
};

// update
void HTTPClientState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "update_config", 0, "wrong state");
};

void HTTPClientState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "update_simulation_code", 0, "wrong state");
};

// comm
void HTTPClientState::session_stop(FiniteStateMachine *cyclobot) {
    // stop session and client
    Serial.println(F("[HTTPClientState::session_stop] running..."));
    cyclobot->commPtr->clientCommPtr->put_invalid_cyclobot_session_token();
    cyclobot->commPtr->wifiCommPtr->disconnect_wifi();
    Serial.println(F("[HTTPClientState::session_stop] done"));
};

// sim
void HTTPClientState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "run_simulation", 0, "wrong state");
};

// comm
void HTTPClientState::report_simulation_data(FiniteStateMachine *cyclobot) {
    // This method must start (and stop) both Client and Session
    Serial.println(F("[HTTPClientState::report_simulation_data] running..."));
    cyclobot->commPtr->wifiCommPtr->connect_wifi(cyclobot->paramPtr->wifiParametersPtr);
    cyclobot->commPtr->clientCommPtr->get_cyclobot_session_token(cyclobot->paramPtr->clientParametersPtr, cyclobot->paramPtr->wifiParametersPtr, cyclobot->paramPtr->deviceParametersPtr);
    cyclobot->commPtr->clientCommPtr->post_cyclobot_environment_state();
    session_stop(cyclobot);
    Serial.println(F("[HTTPClientState::report_simulation_data] done"));
};

// self
void HTTPClientState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "take_a_nap", 0, "wrong state");
};

// constructor
HTTPClientState::HTTPClientState() {
    return;
};