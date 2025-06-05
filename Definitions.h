// COMPONENTES FÍSICOS 
int sensorUmidadeSolo = A0;                       // Sensor de umidade do solo pino A0 conectado no A0 do Arduino 
int sensorChuva = A1;                             // Sensor de chuva pino A1 conectado no A1 do Arduino 
int sensorTemperatura = A2;                       // Sensor de chuva pino A2 conectado no A2 do Arduino 
int portaRele = 4;                                // porta de controle do relé conectada no D4 do Arduino 

// PARAMETROS DE TESTE
bool testarComponentesFisicos = 1;                // condição para testes de inicialização; 1 = executar testes
char frase = "";                                  // mensagem para o usuário
int inputDoUsuarioPositivo = 0;                   // 0 = negativo; 1 = positivo
bool wifiConectado = 0;                           // condição da conexão wifi; 1 = está conectado
bool chuvaOK = 0;                                 // condição da bomba dagua; 1 = está funcionando
bool rioOK = 0;                                   // condição da bomba dagua; 1 = está funcionando
bool ventoOK = 0;                                 // condição do ventilador; 1 = está funcionando
bool iluminacaoOK = 0;                            // condição do LED; 1 = está funcionando
bool componentesFisicosOK = 0;                    // condição geral dos componentes; 1 = componentes funcionando

// PARAMETROS DE CONTROLE DO ECOSSISTEMA
int valorLimiteUmidade = 500;                     // valor da tensão de comparação do sensor / valor máximo = 1024 
int valorLimiteChuva = 500;                       // valor da tensão de comparação do sensor / valor máximo = 1024  
int temperaturaAtual = 20;                        // valor de tensão de comparação do sensor / valor máximo = Não sei / média esperada 20 graus
int temperaturaMinimaEsperada = 18;               // abaixo de 18 graus já é frio
int temperaturaMaximaEsperada = 22;               // abaixo de 22 graus já é frio
int tempoDeRegaInicial = 2000;                    // em milisegundos
int taxaCrescimento = 0;                          // em milisegundos
int taxaQueda = 0;                                // em milisegundos
int tempoDeRega = 3000;                           // em milisegundos
int clima = 1;                                    // 0 = abaixo de 18 graus; 1 = entre 18 e 22 graus; 2 = mais de 22 graus
bool soloUmido = 1;                               // condição de solo úmido; 1 = solo umido
bool luzDoDia = 1;                                // condição de iluminação; 1 = dia; 0 = noite
bool standBy = 0;                                 // desativa os controladores; 1 = desativar (manutenção || eliminar ruídos)

unsigned long momentoInicioEvento = micros();     // valor em microsegundos
unsigned long momentoFimEvento = micros();        // valor em microsegundos
unsigned long tempoDeBufferMicroS = 1800000000;   // 1800000000 microsegundos = 30 minutos