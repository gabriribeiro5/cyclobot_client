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

class DeviceParameters {
public:
    String cyclobotId;
    String cyclobotToken;
    bool firstAwakening;
    unsigned long sleepLength;

    DeviceParameters() { // Constructor defined in header to allow getUniqueId() usage
        cyclobotId = getUniqueId();    // This method is temporary until we have a proper token generation system
        cyclobotToken = getUniqueId(); // This method is temporary until we have a proper token generation system
        cyclobotId.toUpperCase();
        cyclobotToken.toUpperCase();
        firstAwakening = true;
        sleepLength = 3;               // 1h = 3600000 ms
    }

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