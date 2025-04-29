#include "ErrorHandlingState.h"
#include "Arduino.h"

void ErrorHandlingState::enter(FiniteStateMachine* unit) {
    Serial.println("[Start] Entering...");
}

void ErrorHandlingState::execute(FiniteStateMachine* unit) {
    Serial.println("[Start] Running...");
    delay(500);
}

void ErrorHandlingState::exit(FiniteStateMachine* unit) {
    Serial.println("[Start] Exiting...");
}
