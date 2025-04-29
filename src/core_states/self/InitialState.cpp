#include "InitialState.h"
#include "Arduino.h"

void InitialState::enter(FiniteStateMachine* unit) {
    Serial.println("[Start] Entering...");
}

void InitialState::execute(FiniteStateMachine* unit) {
    Serial.println("[Start] Running...");
    delay(500);
}

void InitialState::exit(FiniteStateMachine* unit) {
    Serial.println("[Start] Exiting...");
}
