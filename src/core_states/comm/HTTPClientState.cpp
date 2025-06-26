#include "Arduino.h"
#include "HTTPClientState.h"
#include "StateTransitionException.h"
#include "SimmulationState.h"
#include "SharedInstances.h"
#include "ClientComm.h"

// used by context.changeState
void HTTPClientState::enter() {
    if (!cyclobot) {
        throw StateException("(enter): cyclobot pointer is null in HTTPClientState");
    }
    
    Serial.println("(HTTPClientState) Running...");
};

void HTTPClientState::exit() {
    Serial.println("(exit) switching off HTTPClientState");
};

// error
void HTTPClientState::report_error() {
    throw StateTransitionException("(report_error): wrong state (HTTPClientState)");
};

// self
void HTTPClientState::run_health_check() {
    throw StateTransitionException("(run_health_check): wrong state (HTTPClientState)");
};

// comm
void HTTPClientState::report_signature_request() {
    Serial.println("(report_signature_request): running...");
    if (deviceParametersPtr->firstAwakening) {
        clientCommPtr->post_signature_request();
        deviceParametersPtr->firstAwakening = false;
        Serial.println("(report_signature_request): cyclobot approved");
    } else {
        Serial.println("(report_signature_request): skipped");
    }
};

void HTTPClientState::session_new() {
    Serial.println("(session_new) running...");
    clientCommPtr->get_cyclobot_session_token();
    Serial.println("(session_new) done");
};

void HTTPClientState::report_config() {
    Serial.println("(report_config) running...");
    Serial.println("(report_config) done");
};

void HTTPClientState::report_health_check() {
    Serial.println("(report_health_check) Running...");
    // if there are incoming bytes available
    // from the server, read them and print them:
    while (client.available()) {
        char c = client.read();
        Serial.write(c);
    }

    // if the server's disconnected, stop the client:
    if (!client.connected()) {
        Serial.println();
        Serial.println("disconnecting from server.");
        client.stop();

        // do nothing forevermore:
        while (true);

    // change state
    BaseState codeUpdate = CodeUpdateState();
    cyclobot.changestate(&codeUpdate);
    }
};

// update
void HTTPClientState::update_config() {
    throw StateTransitionException("(update_config): wrong state (HTTPClientState)");
};

void HTTPClientState::update_simmulation_code() {
    throw StateTransitionException("(update_firmware): wrong state (HTTPClientState)");
};

// comm
void HTTPClientState::session_stop() {
    Serial.println("(session_stop) running...");
    Serial.println("(session_stop) done");
};

// simm
void HTTPClientState::run_simmulation() {
    throw StateTransitionException("(RunSimmulation): wrong state (HTTPClientState)");
};

// comm
void HTTPClientState::report_simmulation_data() {
    // This method must start (and stop) both Client and Session
    Serial.println("(report_simmulation_data) running...");
    Serial.println("(report_simmulation_data) done");
};

// self
void HTTPClientState::take_a_nap() {
    throw StateTransitionException("(take_a_nap): wrong state (HTTPClientState)");
};

// constructor
void HTTPClientState::HTTPClientState(FiniteStateMachine *cyclobot) {
    Serial.println("[HTTPClientState] Instantiated...");
};