#include <Arduino.h>
#include "Definitions.h"
#include "InitialState.h"
#include "Context.h"

// Instantiate an state machine
BaseState state = InitialState();
FiniteStateMachine cyclobot = FiniteStateMachine(&state);

void setup() {
    pinMode(sensorUmidadeSolo, INPUT);              // Sensor de umidade do solo - porta A0 é entrada 
    pinMode(sensorChuva, INPUT);                    // Sensor de chuva - porta A1 é entrada 
    pinMode(portaRele, OUTPUT);                     // Porta de controle do Relé - D4 é saída 
    digitalWrite(portaRele, HIGH);                  // Mantenha relé desligado  
    Serial.begin(9600);                             // Monitor console 9600 Bps
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
