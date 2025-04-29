#pragma once

class Config {
    public:
        unsigned long momentoInicioEvento = micros();     // valor em microsegundos
        unsigned long momentoFimEvento = micros();        // valor em microsegundos
        unsigned long tempoDeBufferMicroS = 1800000000;   // 1800000000 microsegundos = 30 minutos
}