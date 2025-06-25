#pragma once

class SelfDiagnosisData {
    public:
        // bools in c++: 1 = true
        bool testPhysicalComponents = 1;             // condição para testes de inicialização; 1 = executar testes
        int userImput = 0;                           // 0 = negativo; 1 = positivo
        bool wateringSystemOK = 0;                   // condição da bomba dagua; 1 = está funcionando
        bool riverSystemOK = 0;                      // condição da bomba dagua; 1 = está funcionando
        bool windSystemOK = 0;                       // condição do ventilador; 1 = está funcionando
        bool lightningSystemOK = 0;                  // condição do LED; 1 = está funcionando
        bool wifiIsConnected = 0;                    // condição da conexão wifi; 1 = está conectado
        bool wifiFirmwareRequireUpdate = 0;          // condição de versionamento do firmware de wifi; 1 = requer atualização
        bool physicalComponentsOK = 0;               // condição geral dos componentes; 1 = componentes funcionando

        StaticJsonDocument<384> selfDiagnosis_Json;
        String selfDiagnosis_String;
}