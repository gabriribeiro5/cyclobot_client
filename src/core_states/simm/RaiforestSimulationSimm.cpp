#include "RaiforestSimulationSimm.h"
#include "Arduino.h"

void RaiforestSimulationSimm::enter(FiniteStateMachine* unit) {
    Serial.println("[RaiforestSimulationSimm] Entering...");
}

void RaiforestSimulationSimm::execute(FiniteStateMachine* unit) {
    Serial.println("[RaiforestSimulationSimm] Running...");
    delay(500);
}

void RaiforestSimulationSimm::exit(FiniteStateMachine* unit) {
    Serial.println("[RaiforestSimulationSimm] Exiting...");
}
