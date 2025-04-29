#include "SelfDiagnosisState.h"
#include "Arduino.h"

void SelfDiagnosisState::enter(FiniteStateMachine* unit) {
    Serial.println("[Start] Entering...");
}

void SelfDiagnosisState::execute(FiniteStateMachine* unit) {
    Serial.println("[Start] Running...");
    delay(500);
}

void SelfDiagnosisState::exit(FiniteStateMachine* unit) {
    Serial.println("[Start] Exiting...");
}
