#pragma once
#include "BaseData.h"

class DiagnosisData : public BaseData {
    public:
        // SELF DIAGNOSIS PARAMETERS
        bool testPhysicalComponenetes = 1;   // condição para testes de inicialização; 1 = executar testes
        char msgToUser = "";                 // mensagem para o usuário
        int userImput = 0;                   // 0 = negativo; 1 = positivo
        bool wifiConected = 0;               // condição da conexão wifi; 1 = está conectado
        bool wateringOK = 0;                 // condição da bomba dagua; 1 = está funcionando
        bool riverOK = 0;                    // condição da bomba dagua; 1 = está funcionando
        bool windOK = 0;                     // condição do ventilador; 1 = está funcionando
        bool lightningOK = 0;                // condição do LED; 1 = está funcionando
        bool physicalComponentsOK = 0;       // condição geral dos componentes; 1 = componentes funcionando
}