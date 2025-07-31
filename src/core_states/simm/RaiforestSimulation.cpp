#include "../../../include/core_states/simm/RainforestSimulation.h"
#include "../../../include/Context.h"
#include "Arduino.h"

void RainforestSimulation::RunSimulation() {
    /*
    INDICES CLIMÁTICOS EM FLORESTAS
    - Temperatura média de 20 graus Célcius
    - Chove de 3 a 6 milímetros por ano
    - Menos chuva no inverno
    - Mais chuva no verão
    */
    Serial.println(F("[RaiforestSimulation] Running..."));
    
}

RainforestSimulation::RainforestSimulation(FiniteStateMachine *cyclobot) {
    Serial.println(F("[RaiforestSimulation] Instantiated..."));
}