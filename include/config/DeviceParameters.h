#pragma once
#include <ArduinoUniqueID.h>
#include <SoftwareSerial.h>

class DeviceParameters {
public:
    String cyclobotId;
    String cyclobotToken;
    bool firstAwakening = true;
    int sleepLength = 60000 * 60; // 1h

    DeviceParameters() {
        cyclobotId = getUniqueId();
        cyclobotToken = getUniqueId(); // Simule token com base no ID se necessário
    }

private:
    String getUniqueId() {
        String id = "";
        for (size_t i = 0; i < UniqueIDsize; i++) {
            id += String(UniqueID[i], HEX);
        }
        return id;
    }
};
