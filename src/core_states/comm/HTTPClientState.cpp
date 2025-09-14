#include "Arduino.h"
#include "../../../include/core_states/comm/HTTPClientState.h"
#include "../../../include/Context.h"

// used by context.changeState
void HTTPClientState::enter(FiniteStateMachine *fsm_context) {
    if (!fsm_context) {
        Serial.println(F("[HTTPClientState::enter] fsm_context pointer is null in HTTPClientState"));
        return;
    }
    Serial.println(F(" *************************  ******[HTTPClientState::enter]******  ************************* "));
    Serial.flush();
};

void HTTPClientState::exit(FiniteStateMachine *fsm_context) {
    Serial.println(F(" *************************  ******[HTTPClientState::exit]*******  ************************* "));
    Serial.flush();
};

// comm
void HTTPClientState::report_signature_request(FiniteStateMachine *fsm_context) {
    Serial.println(F("[HTTPClientState::report_signature_request] running..."));
    Serial.flush();
    if (fsm_context->paramPtr->deviceParametersPtr->firstAwakening) {
        fsm_context->commPtr->clientCommPtr->post_signature_request(fsm_context->paramPtr->clientParametersPtr,
                                                                  fsm_context->paramPtr->wifiParametersPtr,
                                                                  fsm_context->paramPtr->deviceParametersPtr);
        fsm_context->paramPtr->deviceParametersPtr->firstAwakening = false;
        Serial.println(F("[HTTPClientState::report_signature_request] fsm_context approved"));
        Serial.flush();
    } else {
        Serial.println(F("[HTTPClientState::report_signature_request] skipped"));
        Serial.flush();
    }
};

void HTTPClientState::session_new(FiniteStateMachine *fsm_context) {
    Serial.println(F("[HTTPClientState::session_new] running..."));
    Serial.flush();
    fsm_context->printFreeMemory("[HTTPClientState::session_new]");
    fsm_context->commPtr->clientCommPtr->get_cyclobot_session_token(fsm_context->paramPtr->clientParametersPtr,
                                                                  fsm_context->paramPtr->wifiParametersPtr,
                                                                  fsm_context->paramPtr->deviceParametersPtr);
    Serial.println(F("[HTTPClientState::session_new] done"));
    Serial.flush();
};

void HTTPClientState::report_config(FiniteStateMachine *fsm_context) {
    Serial.println(F("[HTTPClientState::report_config] running..."));
    Serial.flush();
    fsm_context->commPtr->clientCommPtr->post_cyclobot_config(fsm_context->paramPtr->clientParametersPtr,
                                                            fsm_context->paramPtr->wifiParametersPtr,
                                                            fsm_context->paramPtr->deviceParametersPtr,
                                                            fsm_context->dataPtr->configDataPtr,
                                                            fsm_context->paramPtr->ecosystemParametersPtr);
    Serial.println(F("[HTTPClientState::report_config] done"));
    Serial.flush();
};

void HTTPClientState::report_health_check(FiniteStateMachine *fsm_context) {
    Serial.println(F("[HTTPClientState::report_health_check] running..."));
    Serial.flush();
    fsm_context->commPtr->clientCommPtr->post_cyclobot_diagnosis(fsm_context->paramPtr->clientParametersPtr,
                                                               fsm_context->paramPtr->wifiParametersPtr,
                                                               fsm_context->paramPtr->deviceParametersPtr,
                                                               fsm_context->dataPtr->selfDiagnosisDataPtr);
    Serial.println(F("[HTTPClientState::report_health_check] done"));
    Serial.flush();
};

void HTTPClientState::session_stop(FiniteStateMachine *fsm_context) {
    // stop session and client
    Serial.println(F("[HTTPClientState::session_stop] running..."));
    Serial.flush();
    fsm_context->commPtr->clientCommPtr->put_invalid_cyclobot_session_token();
    fsm_context->commPtr->wifiCommPtr->disconnect_wifi();
    Serial.println(F("[HTTPClientState::session_stop] done"));
    Serial.flush();
};

// self
void HTTPClientState::take_a_nap(FiniteStateMachine *fsm_context) {
    // fsm_context->selfPtr->errorHandlerPtr->log_error_msg(fsm_context->paramPtr->errorHandlingParametersPtr, "HTTPClientState", "take_a_nap", 0, "wrong state");
    return;
};

// constructor
HTTPClientState::HTTPClientState() {
    return;
};