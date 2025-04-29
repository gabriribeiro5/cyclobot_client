#include "FirmwareUpdateState.h"
#include "Arduino.h"

void FirmwareUpdateState::enter(FiniteStateMachine* unit) {
    Serial.println("[Start] Entering...");
}

void FirmwareUpdateState::execute(FiniteStateMachine* unit) {
    Serial.println("[Start] Running...");
    delay(500);
}

void FirmwareUpdateState::exit(FiniteStateMachine* unit) {
    Serial.println("[Start] Exiting...");
}
