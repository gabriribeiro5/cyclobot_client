#pragma once

class Environment {
    public:
        // Rainforest state variables
        int valueMoistureLimit = 500;     // valor da tensão de comparação do sensor / valor máximo = 1024 
        int valueWateringLimit = 500;     // valor da tensão de comparação do sensor / valor máximo = 1024  
        int temperatureCurrent = 20;      // valor de tensão de comparação do sensor / valor máximo = Não sei / média esperada 20 graus
        int temperatureMinExpected = 18;  // abaixo de 18 graus já é frio
        int temperatureMaxExpected = 22;  // abaixo de 22 graus já é frio
        int timeWateringInitial = 2000;   // em milisegundos
        int timeWatering = 3000;          // em milisegundos
        int growthRate = 0;               // em milisegundos
        int decreaseRate = 0;             // em milisegundos
        int climate = 1;                  // 0 = abaixo de 18 graus; 1 = entre 18 e 22 graus; 2 = mais de 22 graus
        bool wetSoil = 1;                 // condição de solo úmido; 1 = solo umido
        bool dayLight = 1;                // condição de iluminação; 1 = dia; 0 = noite
        bool standBy = 0;                 // desativa os controladores; 1 = desativar (manutenção || eliminar ruídos)
};