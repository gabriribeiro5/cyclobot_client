#include "ClientState.h"
#include "Arduino.h"

void ClientState::enter(FiniteStateMachine* unit) {
    Serial.println("[Start] Entering...");
}

void ClientState::execute(FiniteStateMachine* unit) {
    Serial.println("[Start] Running...");
    delay(500);
}

void ClientState::exit(FiniteStateMachine* unit) {
    Serial.println("[Start] Exiting...");
}
