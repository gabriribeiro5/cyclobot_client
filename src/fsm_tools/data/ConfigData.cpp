#include "../../../include/fsm_tools/data/ConfigData.h"

#include <RTCLib.h>
#include "EEPROM.h"
// Forward declarations for helpers used in constructor
static inline int _int_region_start();
static inline int _uint8_region_start();
static inline int _int_record_addr(int index);
static inline int _uint8_record_addr(int index);

ConfigData::ConfigData()
{
    // Initialize EEPROM headers for each region (magic/version/count)
    int addr = ConfigData::CONFIG_EEPROM_START;
    uint16_t magic = 0;
    EEPROM.get(addr, magic);
    if (magic != CONFIG_EEPROM_MAGIC) {
        uint16_t m = CONFIG_EEPROM_MAGIC;
        uint16_t v = CONFIG_EEPROM_VERSION;
        uint16_t cnt = 0;
        addr = ConfigData::CONFIG_EEPROM_START;
        EEPROM.put(addr, m); addr += sizeof(m);
        EEPROM.put(addr, v); addr += sizeof(v);
        EEPROM.put(addr, cnt);
    }

    // INT region header
    int int_haddr = _int_region_start();
    EEPROM.get(int_haddr, magic);
    if (magic != CONFIG_EEPROM_MAGIC) {
        uint16_t m = CONFIG_EEPROM_MAGIC;
        uint16_t v = CONFIG_EEPROM_VERSION;
        uint16_t cnt = 0;
        EEPROM.put(int_haddr, m); int_haddr += sizeof(m);
        EEPROM.put(int_haddr, v); int_haddr += sizeof(v);
        EEPROM.put(int_haddr, cnt);
    }

    // UINT8 region header
    int u_haddr = _uint8_region_start();
    EEPROM.get(u_haddr, magic);
    if (magic != CONFIG_EEPROM_MAGIC) {
        uint16_t m = CONFIG_EEPROM_MAGIC;
        uint16_t v = CONFIG_EEPROM_VERSION;
        uint16_t cnt = 0;
        EEPROM.put(u_haddr, m); u_haddr += sizeof(m);
        EEPROM.put(u_haddr, v); u_haddr += sizeof(v);
        EEPROM.put(u_haddr, cnt);
    }
};

/************************ SEARCH METHODS ************************/
// Low-level header helpers
static inline int _header_size_bytes() { return sizeof(uint16_t) * 3; }
static inline int _record_addr(int index) { return ConfigData::CONFIG_EEPROM_START + _header_size_bytes() + index * sizeof(ConfigData::EEPROM_Config_Bool); }
// INT / UINT8 region helpers (available early so constructor can use them)
static inline int _int_region_start() {
    return ConfigData::CONFIG_EEPROM_START + _header_size_bytes() + ConfigData::CONFIG_MAX_BOOL_ENTRIES * sizeof(ConfigData::EEPROM_Config_Bool);
}
static inline int _uint8_region_start() {
    return _int_region_start() + _header_size_bytes() + ConfigData::CONFIG_MAX_INT_ENTRIES * sizeof(ConfigData::EEPROM_Config_Int);
}
static inline int _int_record_addr(int index) { return _int_region_start() + _header_size_bytes() + index * sizeof(ConfigData::EEPROM_Config_Int); }
static inline int _uint8_record_addr(int index) { return _uint8_region_start() + _header_size_bytes() + index * sizeof(ConfigData::EEPROM_Config_Uint8); }

bool ConfigData::read_bool_at_index(int index, Config_Bool &out) {
    if (index < 0 || index >= (int)ConfigData::CONFIG_MAX_BOOL_ENTRIES) return false;
    ConfigData::EEPROM_Config_Bool rec;
    int addr = _record_addr(index);
    EEPROM.get(addr, rec);
    if (rec.name[0] == '\0') return false; // empty
    // copy into out
    memset(&out, 0, sizeof(out));
    strncpy(out.name, rec.name, ConfigData::CONFIG_NAME_LEN - 1);
    out.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
    out.value = rec.value != 0;
    strncpy(out.description, rec.description, ConfigData::CONFIG_DESC_LEN - 1);
    out.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
    out.is_pin_value = rec.is_pin_value != 0;
    out.user_can_see = rec.user_can_see != 0;
    out.updated_by = rec.updated_by != 0;
    out.last_update = DateTime(rec.last_update_unix);
    return true;
}

bool ConfigData::write_bool_at_index(int index, const Config_Bool &in) {
    if (index < 0 || index >= (int)ConfigData::CONFIG_MAX_BOOL_ENTRIES) return false;
    int addr = _record_addr(index);
    // read existing to detect if we are creating a new entry
    ConfigData::EEPROM_Config_Bool oldRec;
    EEPROM.get(addr, oldRec);

    ConfigData::EEPROM_Config_Bool rec;
    memset(&rec, 0, sizeof(rec));
    strncpy(rec.name, in.name, ConfigData::CONFIG_NAME_LEN - 1);
    rec.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
    strncpy(rec.description, in.description, ConfigData::CONFIG_DESC_LEN - 1);
    rec.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
    rec.value = in.value ? 1 : 0;
    rec.is_pin_value = in.is_pin_value ? 1 : 0;
    rec.user_can_see = in.user_can_see ? 1 : 0;
    rec.updated_by = in.updated_by ? 1 : 0;
    rec.last_update_unix = (uint32_t)in.last_update.unixtime();

    EEPROM.put(addr, rec);

    // if we wrote into an empty slot, increment header count
    if (oldRec.name[0] == '\0' && rec.name[0] != '\0') {
        // update count in header
        uint16_t magic = 0, version = 0, count = 0;
        int haddr = ConfigData::CONFIG_EEPROM_START;
        EEPROM.get(haddr, magic); haddr += sizeof(magic);
        EEPROM.get(haddr, version); haddr += sizeof(version);
        EEPROM.get(haddr, count);
        if (count < ConfigData::CONFIG_MAX_BOOL_ENTRIES) {
            count++;
            haddr = ConfigData::CONFIG_EEPROM_START + sizeof(magic) + sizeof(version);
            EEPROM.put(haddr, count);
        }
    }
    return true;
}

int ConfigData::find_bool_index(const char *name) {
    for (int i = 0; i < (int)ConfigData::CONFIG_MAX_BOOL_ENTRIES; i++) {
        ConfigData::EEPROM_Config_Bool rec;
        int addr = _record_addr(i);
        EEPROM.get(addr, rec);
        if (rec.name[0] == '\0') continue;
        if (strcmp(rec.name, name) == 0) return i;
    }
    return -1;
}

int ConfigData::find_free_bool_index() {
    for (int i = 0; i < (int)ConfigData::CONFIG_MAX_BOOL_ENTRIES; i++) {
        ConfigData::EEPROM_Config_Bool rec;
        int addr = _record_addr(i);
        EEPROM.get(addr, rec);
        if (rec.name[0] == '\0') return i;
    }
    return -1;
}

bool ConfigData::add_bool(const Config_Bool &in) {
    int idx = find_bool_index(in.name);
    if (idx >= 0) {
        return write_bool_at_index(idx, in);
    }
    idx = find_free_bool_index();
    if (idx < 0) return false;
    return write_bool_at_index(idx, in);
}

bool ConfigData::remove_bool(const char *name) {
    int idx = find_bool_index(name);
    if (idx < 0) return false;
    // clear record
    ConfigData::EEPROM_Config_Bool rec;
    memset(&rec, 0, sizeof(rec));
    int addr = _record_addr(idx);
    EEPROM.put(addr, rec);
    // decrement header count
    uint16_t magic = 0, version = 0, count = 0;
    int haddr = ConfigData::CONFIG_EEPROM_START;
    EEPROM.get(haddr, magic); haddr += sizeof(magic);
    EEPROM.get(haddr, version); haddr += sizeof(version);
    EEPROM.get(haddr, count);
    if (count > 0) {
        count--;
        haddr = ConfigData::CONFIG_EEPROM_START + sizeof(magic) + sizeof(version);
        EEPROM.put(haddr, count);
    }
    return true;
}

bool ConfigData::clear_bool_eeprom() {
    // wipe magic to indicate empty
    uint16_t zero = 0;
    int addr = ConfigData::CONFIG_EEPROM_START;
    EEPROM.put(addr, zero);
    return true;
}

bool ConfigData::set_config_bool_value(char *name, bool value) {
    int idx = find_bool_index(name);
    if (idx < 0) return false;
    Config_Bool cb;
    if (!read_bool_at_index(idx, cb)) return false;
    cb.value = value;
    return write_bool_at_index(idx, cb);
}

// ----------------- INT region helpers -----------------

bool ConfigData::read_int_at_index(int index, Config_Int &out) {
    if (index < 0 || index >= (int)ConfigData::CONFIG_MAX_INT_ENTRIES) return false;
    ConfigData::EEPROM_Config_Int rec;
    int addr = _int_record_addr(index);
    EEPROM.get(addr, rec);
    if (rec.name[0] == '\0') return false; // empty
    memset(&out, 0, sizeof(out));
    strncpy(out.name, rec.name, ConfigData::CONFIG_NAME_LEN - 1);
    out.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
    out.value = (int)rec.value;
    strncpy(out.description, rec.description, ConfigData::CONFIG_DESC_LEN - 1);
    out.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
    out.is_pin_value = rec.is_pin_value != 0;
    out.user_can_see = rec.user_can_see != 0;
    out.updated_by = rec.updated_by != 0;
    out.last_update = DateTime(rec.last_update_unix);
    return true;
}

bool ConfigData::write_int_at_index(int index, const Config_Int &in) {
    if (index < 0 || index >= (int)ConfigData::CONFIG_MAX_INT_ENTRIES) return false;
    int addr = _int_record_addr(index);
    ConfigData::EEPROM_Config_Int oldRec;
    EEPROM.get(addr, oldRec);

    ConfigData::EEPROM_Config_Int rec;
    memset(&rec, 0, sizeof(rec));
    strncpy(rec.name, in.name, ConfigData::CONFIG_NAME_LEN - 1);
    rec.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
    strncpy(rec.description, in.description, ConfigData::CONFIG_DESC_LEN - 1);
    rec.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
    rec.value = (int32_t)in.value;
    rec.is_pin_value = in.is_pin_value ? 1 : 0;
    rec.user_can_see = in.user_can_see ? 1 : 0;
    rec.updated_by = in.updated_by ? 1 : 0;
    rec.last_update_unix = (uint32_t)in.last_update.unixtime();

    EEPROM.put(addr, rec);

    if (oldRec.name[0] == '\0' && rec.name[0] != '\0') {
        uint16_t magic = 0, version = 0, count = 0;
        int haddr = _int_region_start();
        EEPROM.get(haddr, magic); haddr += sizeof(magic);
        EEPROM.get(haddr, version); haddr += sizeof(version);
        EEPROM.get(haddr, count);
        if (count < ConfigData::CONFIG_MAX_INT_ENTRIES) {
            count++;
            haddr = _int_region_start() + sizeof(magic) + sizeof(version);
            EEPROM.put(haddr, count);
        }
    }
    return true;
}

int ConfigData::find_int_index(const char *name) {
    for (int i = 0; i < (int)ConfigData::CONFIG_MAX_INT_ENTRIES; i++) {
        ConfigData::EEPROM_Config_Int rec;
        int addr = _int_record_addr(i);
        EEPROM.get(addr, rec);
        if (rec.name[0] == '\0') continue;
        if (strcmp(rec.name, name) == 0) return i;
    }
    return -1;
}

int ConfigData::find_free_int_index() {
    for (int i = 0; i < (int)ConfigData::CONFIG_MAX_INT_ENTRIES; i++) {
        ConfigData::EEPROM_Config_Int rec;
        int addr = _int_record_addr(i);
        EEPROM.get(addr, rec);
        if (rec.name[0] == '\0') return i;
    }
    return -1;
}

bool ConfigData::add_int(const Config_Int &in) {
    int idx = find_int_index(in.name);
    if (idx >= 0) return write_int_at_index(idx, in);
    idx = find_free_int_index();
    if (idx < 0) return false;
    return write_int_at_index(idx, in);
}

bool ConfigData::remove_int(const char *name) {
    int idx = find_int_index(name);
    if (idx < 0) return false;
    ConfigData::EEPROM_Config_Int rec;
    memset(&rec, 0, sizeof(rec));
    int addr = _int_record_addr(idx);
    EEPROM.put(addr, rec);
    uint16_t magic = 0, version = 0, count = 0;
    int haddr = _int_region_start();
    EEPROM.get(haddr, magic); haddr += sizeof(magic);
    EEPROM.get(haddr, version); haddr += sizeof(version);
    EEPROM.get(haddr, count);
    if (count > 0) {
        count--;
        haddr = _int_region_start() + sizeof(magic) + sizeof(version);
        EEPROM.put(haddr, count);
    }
    return true;
}

bool ConfigData::set_config_int_value(char *name, int value) {
    int idx = find_int_index(name);
    if (idx < 0) return false;
    Config_Int ci;
    if (!read_int_at_index(idx, ci)) return false;
    ci.value = value;
    return write_int_at_index(idx, ci);
}

bool ConfigData::update_config_int(char *name, const Config_Int &updated) {
    int idx = find_int_index(name);
    if (idx < 0) return false;
    return write_int_at_index(idx, updated);
}

// ----------------- UINT8 region helpers -----------------
bool ConfigData::read_uint8_at_index(int index, Config_Uint8_t &out) {
    if (index < 0 || index >= (int)ConfigData::CONFIG_MAX_UINT8_ENTRIES) return false;
    ConfigData::EEPROM_Config_Uint8 rec;
    int addr = _uint8_record_addr(index);
    EEPROM.get(addr, rec);
    if (rec.name[0] == '\0') return false; // empty
    memset(&out, 0, sizeof(out));
    strncpy(out.name, rec.name, ConfigData::CONFIG_NAME_LEN - 1);
    out.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
    out.value = rec.value;
    strncpy(out.description, rec.description, ConfigData::CONFIG_DESC_LEN - 1);
    out.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
    out.is_pin_value = rec.is_pin_value != 0;
    out.user_can_see = rec.user_can_see != 0;
    out.updated_by = rec.updated_by != 0;
    out.last_update = DateTime(rec.last_update_unix);
    return true;
}

bool ConfigData::write_uint8_at_index(int index, const Config_Uint8_t &in) {
    if (index < 0 || index >= (int)ConfigData::CONFIG_MAX_UINT8_ENTRIES) return false;
    int addr = _uint8_record_addr(index);
    ConfigData::EEPROM_Config_Uint8 oldRec;
    EEPROM.get(addr, oldRec);

    ConfigData::EEPROM_Config_Uint8 rec;
    memset(&rec, 0, sizeof(rec));
    strncpy(rec.name, in.name, ConfigData::CONFIG_NAME_LEN - 1);
    rec.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
    strncpy(rec.description, in.description, ConfigData::CONFIG_DESC_LEN - 1);
    rec.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
    rec.value = in.value;
    rec.is_pin_value = in.is_pin_value ? 1 : 0;
    rec.user_can_see = in.user_can_see ? 1 : 0;
    rec.updated_by = in.updated_by ? 1 : 0;
    rec.last_update_unix = (uint32_t)in.last_update.unixtime();

    EEPROM.put(addr, rec);

    if (oldRec.name[0] == '\0' && rec.name[0] != '\0') {
        uint16_t magic = 0, version = 0, count = 0;
        int haddr = _uint8_region_start();
        EEPROM.get(haddr, magic); haddr += sizeof(magic);
        EEPROM.get(haddr, version); haddr += sizeof(version);
        EEPROM.get(haddr, count);
        if (count < ConfigData::CONFIG_MAX_UINT8_ENTRIES) {
            count++;
            haddr = _uint8_region_start() + sizeof(magic) + sizeof(version);
            EEPROM.put(haddr, count);
        }
    }
    return true;
}

int ConfigData::find_uint8_index(const char *name) {
    for (int i = 0; i < (int)ConfigData::CONFIG_MAX_UINT8_ENTRIES; i++) {
        ConfigData::EEPROM_Config_Uint8 rec;
        int addr = _uint8_record_addr(i);
        EEPROM.get(addr, rec);
        if (rec.name[0] == '\0') continue;
        if (strcmp(rec.name, name) == 0) return i;
    }
    return -1;
}

int ConfigData::find_free_uint8_index() {
    for (int i = 0; i < (int)ConfigData::CONFIG_MAX_UINT8_ENTRIES; i++) {
        ConfigData::EEPROM_Config_Uint8 rec;
        int addr = _uint8_record_addr(i);
        EEPROM.get(addr, rec);
        if (rec.name[0] == '\0') return i;
    }
    return -1;
}

bool ConfigData::add_uint8(const Config_Uint8_t &in) {
    int idx = find_uint8_index(in.name);
    if (idx >= 0) return write_uint8_at_index(idx, in);
    idx = find_free_uint8_index();
    if (idx < 0) return false;
    return write_uint8_at_index(idx, in);
}

bool ConfigData::remove_uint8(const char *name) {
    int idx = find_uint8_index(name);
    if (idx < 0) return false;
    ConfigData::EEPROM_Config_Uint8 rec;
    memset(&rec, 0, sizeof(rec));
    int addr = _uint8_record_addr(idx);
    EEPROM.put(addr, rec);
    uint16_t magic = 0, version = 0, count = 0;
    int haddr = _uint8_region_start();
    EEPROM.get(haddr, magic); haddr += sizeof(magic);
    EEPROM.get(haddr, version); haddr += sizeof(version);
    EEPROM.get(haddr, count);
    if (count > 0) {
        count--;
        haddr = _uint8_region_start() + sizeof(magic) + sizeof(version);
        EEPROM.put(haddr, count);
    }
    return true;
}

bool ConfigData::set_config_uint8_value(char *name, uint8_t value) {
    int idx = find_uint8_index(name);
    if (idx < 0) return false;
    Config_Uint8_t cu;
    if (!read_uint8_at_index(idx, cu)) return false;
    cu.value = value;
    return write_uint8_at_index(idx, cu);
}

bool ConfigData::update_config_uint8(char *name, const Config_Uint8_t &updated) {
    int idx = find_uint8_index(name);
    if (idx < 0) return false;
    return write_uint8_at_index(idx, updated);
}

bool ConfigData::update_config_bool(char *name, const Config_Bool &updated) {
    int idx = find_bool_index(name);
    if (idx < 0) return false;
    return write_bool_at_index(idx, updated);
}

// SETUP
ConfigData::Config_Bool ConfigData::config_bool(char *name)
{
    Config_Bool empty = {"", false, "", false, false, false, DateTime() };
    int idx = find_bool_index(name);
    if (idx < 0) return empty;
    Config_Bool out;
    if (!read_bool_at_index(idx, out)) return empty;
    return out;
}
ConfigData::Config_Int ConfigData::config_int(char *name)
{
    Config_Int empty = {"", 0, "", false, false, false, DateTime() };
    int idx = find_int_index(name);
    if (idx < 0) return empty;
    Config_Int out;
    if (!read_int_at_index(idx, out)) return empty;
    return out;
};
ConfigData::Config_Uint8_t ConfigData::config_uint8_t(char *name)
{
    Config_Uint8_t empty = {"", 0, "", false, false, false, DateTime() };
    int idx = find_uint8_index(name);
    if (idx < 0) return empty;
    Config_Uint8_t out;
    if (!read_uint8_at_index(idx, out)) return empty;
    return out;
};

/************************ INSERT METHODS ************************/
// SETUP
void ConfigData::add_pin(char* type,
                            char *name,
                            bool value,
                            char *description,
                            bool updated_by,
                            DateTime last_update
                        )
{   
    Serial.println("   [ConfigData::add_pin] if 1 ");
    Serial.flush();
    if (strcmp(type, "bool") == 0) {
        Config_Bool new_bool;
        memset(&new_bool, 0, sizeof(new_bool));
        strncpy(new_bool.name, name, ConfigData::CONFIG_NAME_LEN - 1);
        new_bool.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
        new_bool.value = value;
        strncpy(new_bool.description, description, ConfigData::CONFIG_DESC_LEN - 1);
        new_bool.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
        new_bool.updated_by = updated_by;
        new_bool.is_pin_value = true;
        new_bool.user_can_see = false;
        new_bool.last_update = last_update;
        Serial.println("   [ConfigData::add_pin] Adding pin " + String(name));
        Serial.flush();
        add_bool(new_bool);
    };
    Serial.println("   [ConfigData::add_pin] if 2 ");
    Serial.flush();
    if (strcmp(type, "int") == 0) {
        Config_Int new_int;
        memset(&new_int, 0, sizeof(new_int));
        strncpy(new_int.name, name, ConfigData::CONFIG_NAME_LEN - 1);
        new_int.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
        new_int.value = (int)value;
        strncpy(new_int.description, description, ConfigData::CONFIG_DESC_LEN - 1);
        new_int.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
        new_int.is_pin_value = true;
        new_int.user_can_see = false;
        new_int.updated_by = updated_by;
        new_int.last_update = last_update;
        Serial.println("   [ConfigData::add_pin] Adding pin " + String(name));
        Serial.flush();
        add_int(new_int);
    };
    Serial.println("   [ConfigData::add_pin] if 3 ");
    Serial.flush();
    if (strcmp(type, "uint8_t") == 0) {
        Config_Uint8_t new_uint8_t;
        memset(&new_uint8_t, 0, sizeof(new_uint8_t));
        strncpy(new_uint8_t.name, name, ConfigData::CONFIG_NAME_LEN - 1);
        new_uint8_t.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
        new_uint8_t.value = (uint8_t)value;
        strncpy(new_uint8_t.description, description, ConfigData::CONFIG_DESC_LEN - 1);
        new_uint8_t.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
        new_uint8_t.is_pin_value = true;
        new_uint8_t.user_can_see = false;
        new_uint8_t.updated_by = updated_by;
        new_uint8_t.last_update = last_update;
        Serial.println("   [ConfigData::add_pin] Adding pin " + String(name));
        Serial.flush();
        add_uint8(new_uint8_t);
    };
};

/************************ INSERT METHODS ************************/
// SENSOR
void ConfigData::add_parameter(char* type,
                                char *name,
                                bool value,
                                char *description,
                                bool user_can_see,
                                bool updated_by,
                                DateTime last_update
                            )
{
    if (strcmp(type, "bool") == 0) {
        Config_Bool new_bool;
        memset(&new_bool, 0, sizeof(new_bool));
        strncpy(new_bool.name, name, ConfigData::CONFIG_NAME_LEN - 1);
        new_bool.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
        new_bool.value = value;
        strncpy(new_bool.description, description, ConfigData::CONFIG_DESC_LEN - 1);
        new_bool.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
        new_bool.updated_by = updated_by;
        new_bool.is_pin_value = false;
        new_bool.user_can_see = true;
        new_bool.last_update = last_update;
        add_bool(new_bool);
    };
    if (strcmp(type, "int") == 0) {
        Config_Int new_int;
        memset(&new_int, 0, sizeof(new_int));
        strncpy(new_int.name, name, ConfigData::CONFIG_NAME_LEN - 1);
        new_int.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
        new_int.value = (int)value;
        strncpy(new_int.description, description, ConfigData::CONFIG_DESC_LEN - 1);
        new_int.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
        new_int.is_pin_value = false;
        new_int.user_can_see = true;
        new_int.updated_by = updated_by;
        new_int.last_update = last_update;
        add_int(new_int);
    };
    if (strcmp(type, "uint8_t") == 0) {
        Config_Uint8_t new_uint8_t;
        memset(&new_uint8_t, 0, sizeof(new_uint8_t));
        strncpy(new_uint8_t.name, name, ConfigData::CONFIG_NAME_LEN - 1);
        new_uint8_t.name[ConfigData::CONFIG_NAME_LEN - 1] = '\0';
        new_uint8_t.value = (uint8_t)value;
        strncpy(new_uint8_t.description, description, ConfigData::CONFIG_DESC_LEN - 1);
        new_uint8_t.description[ConfigData::CONFIG_DESC_LEN - 1] = '\0';
        new_uint8_t.is_pin_value = false;
        new_uint8_t.user_can_see = true;
        new_uint8_t.updated_by = updated_by;
        new_uint8_t.last_update = last_update;
        add_uint8(new_uint8_t);
    };
};
