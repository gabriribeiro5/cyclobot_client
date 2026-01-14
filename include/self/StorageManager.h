#pragma once
#include "Arduino.h"
#include "EEPROM.h"
#include "../fsm_tools/comm/VisualComm.h"

class StorageManager {
public:
    StorageManager();
    ~StorageManager();

    void put_data();
    void get_data();
};