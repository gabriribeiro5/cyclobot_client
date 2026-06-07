#pragma once
#if defined(__AVR_ATmega4809__) // Arduino WiFi Rev2
  #include <stdint.h>
  #include <string.h>
  #define USE_MEGAAVR_ID
#elif defined(ARDUINO_ARCH_MEGAAVR)
  #define USE_MEGAAVR_ID
#else
  #include <ArduinoUniqueID.h>
#endif
#include <Arduino.h>

class DeviceParameters {
public:
    // Fixed-size char arrays instead of String to avoid heap fragmentation
    // cyclobotId: 20 hex characters (10 bytes converted to hex) + null terminator
    char cyclobotId[32];
    // cyclobotToken: 20 hex characters (device unique ID uppercase) + null terminator  
    const char *cyclobotToken;
    bool firstAwakening;
    unsigned long sleepLength;

    DeviceParameters();

private:
    String getUniqueId() {
        #ifdef USE_MEGAAVR_ID
            // For ATmega4809: read from SIGROW
            const uint16_t sigRowAddr = 0x1100;
            String id = "";
            for (uint8_t i = 0; i < 10; i++) {
                uint8_t b = *((uint8_t *)(sigRowAddr + i));
                if (b < 0x10) id += '0';
                id += String(b, HEX);
            }
            return id;
        #else
            // Use ArduinoUniqueID library
            String id = "";
            for (size_t i = 0; i < UniqueIDsize; i++) {
                if (UniqueID[i] < 0x10) id += '0';
                id += String(UniqueID[i], HEX);
            }
            return id;
        #endif
    }
};