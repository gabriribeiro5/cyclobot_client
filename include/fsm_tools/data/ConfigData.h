#pragma once
#include <ArduinoJson.h>

#include <RTCLib.h>
#include <avr/pgmspace.h>


/*
Pragma pack usage:
    #pragma pack(n): Define o limite de empacotamento para n bytes.
                    Membros são alinhados no menor valor entre n e o tamanho do membro.
    #pragma pack(push, n): Empilha o alinhamento atual e define um novo.
    #pragma pack(pop): Restaura o alinhamento anterior.
    #pragma pack(): Restaura o alinhamento padrão do compilador.
*/

class ConfigData {
public:
    ConfigData();
    // Create SETUP structs — use fixed-size arrays so data can be stored/read directly in EEPROM
    static const size_t CONFIG_NAME_LEN = 24;
    static const size_t CONFIG_DESC_LEN = 48;

    // JSON serialization buffer (transient JSON documents allocated on-demand in ClientComm, SelfDiagnosisData, etc.)
    static const size_t CONFIG_JSON_CAPACITY = 124;
    char config_Char[CONFIG_JSON_CAPACITY];  // char array to hold serialized JSON (allocated at construction)

    struct Config_Bool {
        char name[CONFIG_NAME_LEN];
        bool value;
        char description[CONFIG_DESC_LEN]; // data description (for final user - not admin or server)
        bool is_pin_value;                 // default = false
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        DateTime last_update;
    };
    struct Config_Int {
        char name[CONFIG_NAME_LEN];
        int value;
        char description[CONFIG_DESC_LEN]; // data description (for final user - not admin or server)
        bool is_pin_value;                 // default = false
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        DateTime last_update;
    };
    struct Config_Uint8_t {
        char name[CONFIG_NAME_LEN];
        uint8_t value;
        char description[CONFIG_DESC_LEN]; // data description (for final user - not admin or server)
        bool is_pin_value;                 // default = false
        bool user_can_see;                 // default = true
        bool updated_by;                   // default = 0 (server communication); 1 = (user communication)
        DateTime last_update;
    };

    // No in-memory linked list: records are read/written directly to EEPROM

    // EEPROM-backed record definitions
    static const uint16_t CONFIG_EEPROM_MAGIC = 0xC0DE;
    static const uint16_t CONFIG_EEPROM_VERSION = 1;
    static const uint16_t CONFIG_EEPROM_START = 0;
    static const size_t CONFIG_MAX_BOOL_ENTRIES = 10; // tweak as needed based on EEPROM size
    static const size_t CONFIG_MAX_INT_ENTRIES = 10;
    static const size_t CONFIG_MAX_UINT8_ENTRIES = 10;

    #pragma pack(push, 1)
    struct EEPROM_Config_Bool {
        char name[CONFIG_NAME_LEN];
        char description[CONFIG_DESC_LEN];
        uint8_t value;
        uint8_t is_pin_value;
        uint8_t user_can_see;
        uint8_t updated_by;
        uint32_t last_update_unix;
    };
    struct EEPROM_Config_Int {
        char name[CONFIG_NAME_LEN];
        char description[CONFIG_DESC_LEN];
        int32_t value;
        uint8_t is_pin_value;
        uint8_t user_can_see;
        uint8_t updated_by;
        uint32_t last_update_unix;
    };
    struct EEPROM_Config_Uint8 {
        char name[CONFIG_NAME_LEN];
        char description[CONFIG_DESC_LEN];
        uint8_t value;
        uint8_t is_pin_value;
        uint8_t user_can_see;
        uint8_t updated_by;
        uint32_t last_update_unix;
    };
    #pragma pack(pop)

    // EEPROM-backed accessors (operate directly on EEPROM records)
    // Returns a copy of the record. If not found, returned Config_Bool will have name[0] == '\0'.
    Config_Bool config_bool(char *name);
    Config_Int config_int(char *name);
    Config_Uint8_t config_uint8_t(char *name);

    // Low-level EEPROM helpers (by index) - BOOL
    bool read_bool_at_index(int index, Config_Bool &out);
    bool write_bool_at_index(int index, const Config_Bool &in);
    int find_bool_index(const char *name);
    int find_free_bool_index();
    bool add_bool(const Config_Bool &in);   // add or update
    bool remove_bool(const char *name);
    bool clear_bool_eeprom();

    // Low-level EEPROM helpers (by index) - INT
    bool read_int_at_index(int index, Config_Int &out);
    bool write_int_at_index(int index, const Config_Int &in);
    int find_int_index(const char *name);
    int find_free_int_index();
    bool add_int(const Config_Int &in);
    bool remove_int(const char *name);

    // Low-level EEPROM helpers (by index) - UINT8
    bool read_uint8_at_index(int index, Config_Uint8_t &out);
    bool write_uint8_at_index(int index, const Config_Uint8_t &in);
    int find_uint8_index(const char *name);
    int find_free_uint8_index();
    bool add_uint8(const Config_Uint8_t &in);
    bool remove_uint8(const char *name);

    // Helpers to update individual bool entries (will persist to EEPROM)
    bool set_config_bool_value(char *name, bool value);
    bool update_config_bool(char *name, const Config_Bool &updated);

    // Helpers for int entries
    bool set_config_int_value(char *name, int value);
    bool update_config_int(char *name, const Config_Int &updated);

    // Helpers for uint8 entries
    bool set_config_uint8_value(char *name, uint8_t value);
    bool update_config_uint8(char *name, const Config_Uint8_t &updated);
    
    void add_pin(char* type, char *name, bool value, char *description, bool updated_by, DateTime last_update);
    void add_parameter(char* type, char *name, bool value, char *description, bool user_can_see, bool updated_by, DateTime last_update);

};