#include "ConfigUpdateState.h"
#include "Arduino.h"

void ConfigUpdateState::enter(FiniteStateMachine* unit) {
    Serial.println("[Start] Entering...");
}

void ConfigUpdateState::execute(FiniteStateMachine* unit) {
    Serial.println("[Start] Running...");
    delay(500);
}

void ConfigUpdateState::exit(FiniteStateMachine* unit) {
    Serial.println("[Start] Exiting...");
}
