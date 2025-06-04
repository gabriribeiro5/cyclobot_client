#include <Arduino.h>
#include <map>
#include "Context.h"
#include "BaseState.h"
#include "StartState.h"
#include "SelfDiagnosisState.h"
#include "CommState.h"
#include "SimmState.h"
#include "SleepState.h"

// Instantiate an state machine
BaseState state = InitialState();
FiniteStateMachine cyclobot = FiniteStateMachine(&state);

void setup() {
    Serial.begin(9600);
    cyclobot.currentState->enter();
}

void loop() {
    // Simulate 24h cycle
    delay(1000); // To slow down for Serial prints

    switch (cyclobot.clientFlow) {
        case 0: // Health Check
            cyclobot.run_health_check();
            cyclobot.report_health_check();
            break;
        case 1: // Update
            cyclobot.update_firmware();
            cyclobot.update_config();
            break;
        case 2: // Simmulation
            cyclobot.run_simmulation();
            cyclobot.report_simmulation_data();
            break;
        case 3: // Iddle
            cyclobot.take_a_nap();
            break;
        default: // Reset
            cyclobot.clientFlow = -1;
            break;
    }
    cyclobot.clientFlow++;
}
