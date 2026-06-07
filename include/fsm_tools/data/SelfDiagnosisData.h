#pragma once
#include <ArduinoJson.h>
#include <LinkedList.h>
#include <RTCLib.h>

class SelfDiagnosisData {
public:
    SelfDiagnosisData();
    // bools in c++: 1 = true
    const PROGMEM bool testPhysicalComponents = 1;             // condição para testes de inicialização; 1 = executar testes
    
    int userInput = 0;                           // 0 = negativo; 1 = positivo
    bool wifiNetworkAvailable = 0;               // condição de disponibilidade de rede; 1 = existem redes disponíveis
    bool wifiIsConnected = 0;                    // condição da conexão wifi; 1 = está conectado
    bool httpCommunicationConfirmed = 0;         // condição de comunicação com servidor; 1 = está conectado
    bool wifiFirmwareRequireUpdate = 0;          // condição de versionamento do firmware de wifi; 1 = requer atualização
    bool wateringSystemOK = 0;                   // condição da bomba dagua; 1 = está funcionando
    bool riverSystemOK = 0;                      // condição da bomba dagua; 1 = está funcionando
    bool windSystemOK = 0;                       // condição do ventilador; 1 = está funcionando
    bool lightingSystemOK = 0;                   // condição do LED; 1 = está funcionando
    bool peripheralComponentsOK = 0;             // condição geral dos componentes; 1 = componentes funcionando
    char *diagnosisDateTime = "";

    StaticJsonDocument<384> selfDiagnosis_Json;
    char selfDiagnosis_Char[384];
    
    /**
     * @brief JSON serialization buffer
     * @details Transient JSON documents are allocated on-demand when needed,
     * then freed after use to optimize SRAM usage.
     */
    static const size_t SELFDIAG_JSON_CAPACITY = 384;
    char selfdiag_Char[SELFDIAG_JSON_CAPACITY];  // char array to hold serialized JSON

    struct SelfDiag_Bool {
        char *name;
        bool value;
        char *description;                 // data description (for final user - not admin or server)
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        double expected_frequency;         // used by stream_sensors_data();
        bool measure_now;                  // used by stream_sensors_data();
        bool send_now;                     // used by stream_sensors_data();
        DateTime last_update;
    };
    struct SelfDiag_Int {
        char *name;
        int value;
        char *description;                 // data description (for final user - not admin or server)
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        bool measure_now;                  // used by stream_sensors_data();
        bool send_now;                     // used by stream_sensors_data();
        double expected_frequency;         // used by stream_sensors_data();
        DateTime last_update;
    };
    struct SelfDiag_Char {
        char *name;
        char *value;
        char *description;                 // data description (for final user - not admin or server)
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        bool measure_now;                  // used by stream_sensors_data();
        bool send_now;                     // used by stream_sensors_data();
        double expected_frequency;            // used by stream_sensors_data();
        DateTime last_update;
    };

    // Create linked-lists struct
    // Every list must end with an 's'
    // LinkedList<SelfDiag_Bool> selfdiag_bool_list;
    // LinkedList<SelfDiag_Int> selfdiag_int_list;
    // LinkedList<SelfDiag_Char> selfdiag_char_list;
    
    // Linked-lists SEARCH methods
    SelfDiag_Bool selfdiag_bool(char *name);
    // SelfDiag_Int selfdiag_int(char *name);
    // SelfDiag_Char selfdiag_char(char *name);

    
    void add_parameter(char* type, char *name, char *value, char *description, bool user_can_see, bool updated_by, double expected_frequency, DateTime last_update);
};