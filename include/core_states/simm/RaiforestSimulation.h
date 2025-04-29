// REFERÊNCIAS:
//  Apostila Eletrogate - KIT MAKER 
//   Exemplo 13 – Arduino Sensor de umidade do solo e Sensor de chuva - Gustavo Murta

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

void setup() { 
  pinMode(sensorUmidadeSolo, INPUT);              // Sensor de umidade do solo - porta A0 é entrada 
  pinMode(sensorChuva, INPUT);                    // Sensor de chuva - porta A1 é entrada 
  pinMode(portaRele, OUTPUT);                     // Porta de controle do Relé - D4 é saída 
  digitalWrite(portaRele, HIGH);                  // Mantenha relé desligado  
  Serial.begin(9600);                             // Monitor console 9600 Bps 
}

//* CONTROLADORES DE COMPONENTES FÍSICOS *//
// --> MÉTODOS DE CAPTURA DE DADOS
void AtivarSensorDeUmidade(int valorLimiteUmidade = 500) { 
  int valorSensorUmidadeSolo = analogRead(sensorUmidadeSolo);    // leitura do Sensor de umidade do solo 
  Serial.print(" Sensor de umidade do solo = ");                 // imprime mensagem 
  Serial.print(valorSensorUmidadeSolo);                          // valor do sensor de umidade do solo 
  if (valorSensorUmidadeSolo < valorLimiteUmidade)               // se o valor for menor do que o limite 
  { 
    Serial.println("  => O solo esta úmido");                    // imprime a mensagem 
    soloUmido = 1 ;                                              // solo esta úmido  
  } 
  else                                                           // senão 
  { 
    Serial.println("  => O solo esta seco");                     // imprime a mensagem 
    soloUmido = 0 ;                                              // solo não esta úmido  
  } 
} 

void AtivarSensorDeTemperatura(){ 
  int valorSensorTemperatura = analogRead(sensorTemperatura);    // leitura do Sensor de umidade do solo 
  Serial.print(" Sensor de temperatura = ");                     // imprime mensagem 
  Serial.print(valorSensorTemperatura);                          // valor do sensor de umidade do solo 
  if (valorSensorTemperatura < temperaturaMinimaEsperada) {      // se o valor for menor do que o limite 
    Serial.println("  => O clima esta frio");                    // imprime a mensagem 
    clima = 0 ;                                                  // 0 = está frio
  }
  if (valorSensorTemperatura > temperaturaMaximaEsperada) { 
    Serial.println("  => O clima esta quente");                  // imprime a mensagem 
    clima = 2 ;                                                  // 2 = está quente 
  }
  else {
    Serial.println("  => O clima está adequado");                // imprime a mensagem 
    clima = 1 ;                                                  // solo não esta úmido  
  }
}

void VerificarStatusWifi() {
  //
}

void VerificarDiaHora() {
  //
  luzDoDia = 1; // OBRIGATÓRIO PARA QUEBRA DE LOOP DO MODO STANDBY
}

void PerguntarAoUsuario(char frase) {
  // capturar inputDoUsuarioPositivo (resposta para a frase)
}

// --> MÉTODOS DE INTERAÇÃO COM ECOSSISTEMA
void InformarAoUsuario(char frase) {
  // print em todos os canais disponiveis
}

void AtivarChuva(int tempoDeRega = 3000) {                  // ajuste o tempo de acionamento da bomba 
  int tempoEmSegundos = tempoDeRega / 1000;
  digitalWrite(portaRele, HIGH);                                // relé desligado 
  Serial.println(F("Bomba d'água acionada por... "));           // imprime a mensagem 
  Serial.println(tempoEmSegundos + " segundos");             // imprime a mensagem 
  digitalWrite(portaRele, LOW);                                 // relé ligado 
  Serial.println(F("regando... "));                             // imprime a mensagem 
  delay (tempoDeRega);                                          // tempo de acionamento da bomba dágua = 3 segundo(s)
  digitalWrite(portaRele, HIGH);                                // relé desligado 
  Serial.println(F("bomba d'água desligada... "));              // imprime a mensagem 
}

void AtivarRio() {
  //
}

void DesativarRio() {
  //
}

void AtivarVentilacao(bool direcaoDoVento = 0) {
  switch (direcaoDoVento) {
    case 1:
      // pra trás
      break;
    default:
      // pra frente
      break;
  }
}

void PiscarIluminacaoSolar(int intensidade = "max") {
  // blink cores + intensidade
}

void PiscarIluminacaoNoturna(int intensidade = "max") {
  // blink cores + intensidade
}

void AtivarIluminacaoSolar() {
  // piriri pororo
}

void AtivarIluminacaoNoturna() {
  // piriri pororo
}

void TestarComponentesFisicos() {
  while (componentesFisicosOK = 0) {
    if (rioOK = 0) {
      AtivarRio();
      delay(3000);
      DesativarRio();
      frase = "Rio OK por 3 segundos?";
      PerguntarAoUsuario(frase);
      // TODO: capturar inputDoUsuarioPositivo
      if (inputDoUsuarioPositivo = 1) {
        rioOK = 1;
        inputDoUsuarioPositivo = 0;
      }
      frase = "Tentaremos novamente em breve";
      InformarAoUsuario(frase);
    }

    if (chuvaOK = 0) {
      AtivarChuva(1500);
      delay(500);
      AtivarChuva(1500);
      delay(500);
      AtivarChuva(1500);
      frase = "Chuva OK?";
      PerguntarAoUsuario(frase);
      // TODO: capturar inputDoUsuarioPositivo
      if (inputDoUsuarioPositivo = 1) {
        chuvaOK = 1;
        inputDoUsuarioPositivo = 0;
      }
      frase = "Tentaremos novamente em breve";
      InformarAoUsuario(frase);
    }

    if (ventoOK = 0) {
      AtivarVentilacao(1500);
      delay(500);
      AtivarVentilacao(1500);
      delay(500);
      AtivarVentilacao(1500);
      frase = "Ventilador OK?";
      PerguntarAoUsuario(frase);
      // TODO: capturar inputDoUsuarioPositivo
      if (inputDoUsuarioPositivo = 1) {
        ventoOK = 1;
        inputDoUsuarioPositivo = 0;
      }
      frase = "Tentaremos novamente em breve";
      InformarAoUsuario(frase);
    }

    if (iluminacaoOK = 0) {
      PiscarIluminacaoSolar();
      delay(500);
      AtivarIluminacaoNoturna();
      delay(500);
      AtivarIluminacaoSolar();
      delay(500);
      AtivarIluminacaoNoturna();
      frase = "Iluminação OK?";
      PerguntarAoUsuario(frase);
      // TODO: capturar inputDoUsuarioPositivo
      if (inputDoUsuarioPositivo = 1) {
        iluminacaoOK = 1;
        inputDoUsuarioPositivo = 0;
      }
      frase = "Tentaremos novamente em breve";
      InformarAoUsuario(frase);
    }

    // essas declaracões devem sumir quando a comunicação com usuario estiver implementada
    rioOK = 1;
    chuvaOK = 1;
    ventoOK = 1;
    iluminacaoOK = 1;
    // essas declaracões devem sumir quando a comunicação com usuario estiver implementada


    if (rioOK == 1 & chuvaOK == 1 & ventoOK == 1 & iluminacaoOK == 1) {
      componentesFisicosOK = 1;
    }
  }
}

//* CONTROLADORES DE EVENTOS DO ECOSSISTEMA *//
// -->> MÉTODOS DE CHUVA

// -->> MÉTODOS DE VENTO

// -->> MÉTODOS DE ILUMINAÇÃO

// -->> MÉTODOS DE GERENCIAMENTO DE TEMPO
void BufferDeTempo() {
  momentoFimEvento = micros();
  while (momentoFimEvento - momentoInicioEvento < tempoDeBufferMicroS) {
    delay(600000);                            // 10 minutos
    momentoFimEvento = micros();
  }
}

//* SIMULADOR DE ECOSSISTEMA *//
void SimularFlorestaTropical() {
  /*
   INDICES CLIMÁTICOS EM FLORESTAS
  - Temperatura média de 20 graus Célcius
  - Chove de 3 a 6 milímetros por ano
  - Menos chuva no inverno
  - Mais chuva no verão
  */

  // CAPTURA DE DADOS (SOLO, TEMPERATURA, HORA DO DIA)
  VerificarDiaHora();                                 // api captura dia e hora
  AtivarSensorDeTemperatura ();                       // faz medição do sensor de temperatura
  AtivarSensorDeUmidade (valorLimiteUmidade);         // faz medição do sensor de umidade do solo
  
  // ROTINA DIÁRIA
  switch (standBy) {
    case 1: // desativar controladores
      DesativarRio();

      while (luzDoDia = 0) {                           // noite
        // keep it cool
        VerificarDiaHora();
        delay(1800000);                                // 1800000 = meia hora em milisegundos | maximo = 70 minutos
      }

      if (luzDoDia = 1) {
        delay(1800000);                                // 1800000 = meia hora em milisegundos | maximo = 70 minutos
        standBy = 0;
      }
    default:
      VerificarDiaHora();                              // api captura dia e hora
      AtivarRio();

      // DIA
      if (luzDoDia = 1) {AtivarIluminacaoSolar();}
      while (luzDoDia = 1) {
        // CLIMA
        AtivarSensorDeTemperatura();
        // Ficaremos dentro de um <case> por, pelo menos, 30 minutos
        tempoDeBufferMicroS = 1800000000;                        // 1800000000 microsegundos = 30 minutos
        switch (clima) {
          case 2:                                                // acima de 22 graus celcius
            momentoInicioEvento = micros();
            
            // EVENTOS ASSÍNCRONOS
            // VentoDeVerao();                                      // determina a frequencia de rajadas de vento
            // ChuvaDeVerao();                                      // determina a volumetria de chuva

            BufferDeTempo();
            break;
          case 0:                                                // abaixo de 18 graus celcius
            momentoInicioEvento = micros();
            
            // EVENTOS ASSÍNCRONOS
            // VentoDeInverno();                                    // determina a frequencia de rajadas de vento
            // ChuvaDeInverno();                                    // determina a volumetria de chuva

            BufferDeTempo();
            
            break;
          default:                                               // média esperada de 20 graus celcius
            momentoInicioEvento = micros();
            
            // EVENTOS ASSÍNCRONOS
            // VentoDeNormal();                                      // determina a frequencia de rajadas de vento
            // ChuvaDeNormal();                                      // determina a volumetria de chuva

            BufferDeTempo();
            
            break;
        }
        VerificarDiaHora();                                           // saida do loop DIA
      }

      // NOITE
      if (luzDoDia = 0) {AtivarIluminacaoNoturna();}
      while (luzDoDia = 0) {
        // CLIMA
        AtivarSensorDeTemperatura();
        // Ficaremos dentro de um <case> por, pelo menos, 30 minutos
        tempoDeBufferMicroS = 1800000000;                        // 1800000000 microsegundos = 30 minutos
        switch (clima) {
          case 2:                                                // acima de 22 graus celcius
            momentoInicioEvento = micros();
            
            // EVENTOS ASSÍNCRONOS
            // VentoDeVerao();                                      // determina a frequencia de rajadas de vento
            // ChuvaDeVerao();                                      // determina a volumetria de chuva

            BufferDeTempo();
            break;
          case 0:                                                // abaixo de 18 graus celcius
            momentoInicioEvento = micros();
            
            // EVENTOS ASSÍNCRONOS
            // VentoDeInverno();                                    // determina a frequencia de rajadas de vento
            // ChuvaDeInverno();                                    // determina a volumetria de chuva

            BufferDeTempo();
            
            break;
          default:                                               // média esperada de 20 graus celcius
            momentoInicioEvento = micros();
            
            // EVENTOS ASSÍNCRONOS
            // VentoDeNormal();                                      // determina a frequencia de rajadas de vento
            // ChuvaDeNormal();                                      // determina a volumetria de chuva

            BufferDeTempo();
            
            break;
        }

        VerificarDiaHora();                                           // saida do loop NOITE
          
        momentoFimEvento = micros();
        if (momentoFimEvento < 3600000000 ) { standBy = 1; }            // Fim do dia. Entrar e StandBy entre 00h e 1h
      }
      break;
  }
}


// EXECUÇÃO DA REGRA PRINCIPAL
void loop() 
{
  switch (testarComponentesFisicos) {
    case 1:
      TestarComponentesFisicos();
      if (componentesFisicosOK = 1) { // status OK
        testarComponentesFisicos = 0; // sair do modo de testes
      }
      break;
    default:
      SimularFlorestaTropical();
      break;
  }
}