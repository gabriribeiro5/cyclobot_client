#pragma once
#include <Arduino.h>
#include <RTClib.h>

class EcosystemParameters {
    public:
        EcosystemParameters();
        ~EcosystemParameters();
        bool soilIsWet;                     // condição de solo úmido; 1 = solo umido
        int soilMoistureLimit;              // valor da tensão de comparação do sensor / valor máximo = 1024 
        int currentTemperature;             // valor de tensão de comparação do sensor / valor máximo = Não sei / média esperada 20 graus
        int minTemperatureExpected;         // abaixo de 18 graus já é frio
        int maxTemperatureExpected;         // abaixo de 22 graus já é frio
        int initialWateringTimeLimit;       // em milisegundos
        int growthRate;                     // em milisegundos
        int decreaseRate;                   // em milisegundos
        int wateringTimeLimit;              // em milisegundos
        int climate;                        // 0 = abaixo de 18 graus; 1 = entre 18 e 22 graus; 2 = mais de 22 graus
        bool sunLightAvailable;             // condição de iluminação; 1 = dia; 0 = noite


        bool standBy;                          // desativa os controladores; 1 = desativar (manutenção || eliminar ruídos)
        unsigned long timeBufferMicroSec;      // 1800000000 microsegundos = 30 minutos

};