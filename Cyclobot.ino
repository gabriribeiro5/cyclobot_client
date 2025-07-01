#include <Arduino.h>
#include "IdleState.h"
#include "SelfDiagnosisState.h"
#include "HTTPClientState.h"
#include "ConfigUpdateState.h"
#include "CodeUpdateState.h"
#include "SimmulationState.h"
#include "IdleState.h"
#include "Context.h"

// Set state classes
BaseState idleState = IdleState();
BaseState selfDiagnosisState = SelfDiagnosisState();
BaseState communicationState = HTTPClientState();
BaseState configUpdateState = ConfigUpdateState();
BaseState codeUpdateState = CodeUpdateState();
BaseState simmulationState = SimmulationState();

// Instantiate an state machine
FiniteStateMachine cyclobot = FiniteStateMachine(&idleState);

void setup() {
    pinMode(sensorUmidadeSolo, INPUT);              // Sensor de umidade do solo - porta A0 é entrada 
    pinMode(sensorChuva, INPUT);                    // Sensor de chuva - porta A1 é entrada 
    pinMode(portaRele, OUTPUT);                     // Porta de controle do Relé - D4 é saída 
    digitalWrite(portaRele, HIGH);                  // Mantenha relé desligado  
    Serial.begin(9600);                             // Monitor console 9600 Bps
    cyclobot.currentState->enter();
}

void loop() {
    switch (cyclobot.stateFlow) {
        case 0: // Self
            cyclobot.change_state(&selfDiagnosisState);
            cyclobot.run_health_check();
            break;
        case 1: // Comm
            cyclobot.change_state(&communicationState);
            cyclobot.report_signature_request();
            cyclobot.session_new();
            cyclobot.report_config();
            cyclobot.report_health_check();
            cyclobot.get_update_status();
            break;
        case 2: // Config update
            cyclobot.change_state(&configUpdateState);
            cyclobot.update_config();
            break;
        case 3: // Code update
            cyclobot.change_state(&codeUpdateState);
            cyclobot.update_simmulation_code();
            break;
        case 4: // Comm
            cyclobot.change_state(&communicationState);
            cyclobot.session_stop(); // stop session and client
            break;
        case 5: // Simmulation
            cyclobot.change_state(&simmulationState);
            cyclobot.run_simmulation();
        case 6: // Comm
            cyclobot.change_state(&communicationState);
            cyclobot.report_simmulation_data();
            break;
        case 7: // Idle
            cyclobot.change_state(&idleState);
            cyclobot.take_a_nap();
            cyclobot.stateFlow = -1; // Reset
            break;
        default: // Reset
            cyclobot.stateFlow = -1;
            break;
    }
    cyclobot.stateFlow++;
}
