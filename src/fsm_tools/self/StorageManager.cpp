#include "Arduino.h"
#include "EEPROM.h"
#include "../../../include/fsm_tools/self/StorageManager.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"

StorageManager::StorageManager() {};
StorageManager::~StorageManager() {};

void StorageManager::put_data() {
    // Example: Store an integer at address 0
    int address = 0;
    int value = 42;
    EEPROM.put(address, value);
};

void StorageManager::get_data() {
    // Example: Retrieve an integer from address 0
    int address = 0;
    int value;
    EEPROM.get(address, value);
}