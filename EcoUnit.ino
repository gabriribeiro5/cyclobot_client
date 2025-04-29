#include <Arduino.h>
#include "Context.h"
#include "BaseState.h"
#include "StartState.h"
#include "SelfDiagnosisState.h"
#include "CommState.h"
#include "SimmState.h"
#include "SleepState.h"

// Instantiate an state machine
FiniteStateMachine unit = FiniteStateMachine(StartState);

void setup() {
    Serial.begin(9600);
    unit.currentState->enter(&unit);
}

void loop() {
    unit.execute();

    // Simulate lifecycle flow
    delay(1000); // To slow down for Serial prints

    switch (unit.stateFlow) {
        case 0: // run health check
            unit.changeState(&unit.selfDiagnosisState);
            break;
        case 1: // report self diagnostics
            unit.changeState(&unit.commState);
            break;
        case 2: // run simmulation based on config
            unit.changeState(&unit.simmState);
            break;
        case 3: // report sensor data from simm state
            unit.changeState(&unit.commState);
            break;
        case 4: // 
            unit.changeState(&unit.sleepState);
            break;
        case 5:
            // Stay in sleep forever (or restart)
            break;
    }
    unit.stateFlow++;
}
