#pragma once

class SelfDiagnosisParameters {
    public:
        bool testarComponentesFisicos = 1;                // condição para testes de inicialização; 1 = executar testes
        char frase = "";                                  // mensagem para o usuário
        int inputDoUsuarioPositivo = 0;                   // 0 = negativo; 1 = positivo
        bool wifiConectado = 0;                           // condição da conexão wifi; 1 = está conectado
        bool chuvaOK = 0;                                 // condição da bomba dagua; 1 = está funcionando
        bool rioOK = 0;                                   // condição da bomba dagua; 1 = está funcionando
        bool ventoOK = 0;                                 // condição do ventilador; 1 = está funcionando
        bool iluminacaoOK = 0;                            // condição do LED; 1 = está funcionando
        bool componentesFisicosOK = 0;                    // condição geral dos componentes; 1 = componentes funcionando
}