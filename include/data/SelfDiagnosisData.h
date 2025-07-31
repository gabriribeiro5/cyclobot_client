#pragma once
#include <ArduinoJson.h>
#include <SPI.h>

class SelfDiagnosisData {
    public:
        // bools in c++: 1 = true
        bool testPhysicalComponents = 1;             // condição para testes de inicialização; 1 = executar testes
        int userImput = 0;                           // 0 = negativo; 1 = positivo
        bool wifiNetworkAvailable = 0;               // condição de disponibilidade de rede; 1 = existem redes disponíveis
        bool wifiIsConnected = 0;                    // condição da conexão wifi; 1 = está conectado
        bool httpCommunicationConfirmed = 0;         // condição de comunicação com servidor; 1 = está conectado
        bool wifiFirmwareRequireUpdate = 0;          // condição de versionamento do firmware de wifi; 1 = requer atualização
        bool wateringSystemOK = 0;                   // condição da bomba dagua; 1 = está funcionando
        bool riverSystemOK = 0;                      // condição da bomba dagua; 1 = está funcionando
        bool windSystemOK = 0;                       // condição do ventilador; 1 = está funcionando
        bool lightingSystemOK = 0;                  // condição do LED; 1 = está funcionando
        bool peripheralComponentsOK = 0;               // condição geral dos componentes; 1 = componentes funcionando
        char *diagnosisDateTime = "";

        StaticJsonDocument<384> selfDiagnosis_Json;
        char selfDiagnosis_Char[384];
};