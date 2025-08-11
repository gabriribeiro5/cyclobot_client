#pragma once
#include <Arduino.h>

class EcosystemParameters {
    public:
        bool soilIsWet = 1;                              // condição de solo úmido; 1 = solo umido
        int soilMoistureLimit = 500;                     // valor da tensão de comparação do sensor / valor máximo = 1024 
        int currentTemperature = 20;                     // valor de tensão de comparação do sensor / valor máximo = Não sei / média esperada 20 graus
        int minTemperatureExpected = 18;                 // abaixo de 18 graus já é frio
        int maxTemperatureExpected = 22;                 // abaixo de 22 graus já é frio
        int initialWateringTimeLimit = 2000;             // em milisegundos
        int growthRate = 0;                              // em milisegundos
        int decreaseRate = 0;                            // em milisegundos
        int wateringTimeLimit = 3000;                    // em milisegundos
        int climate = 1;                                 // 0 = abaixo de 18 graus; 1 = entre 18 e 22 graus; 2 = mais de 22 graus
        bool sunLightAvailable = 1;                      // condição de iluminação; 1 = dia; 0 = noite
        bool standBy = 0;                                // desativa os controladores; 1 = desativar (manutenção || eliminar ruídos)

        DateTime eventStart;             // valor em microsegundos
        DateTime eventEnd;               // valor em microsegundos
        unsigned long timeBufferMicroSec = 1800000000;   // 1800000000 microsegundos = 30 minutos

        // Define the map
        typedef void (*simulationClass)();
};