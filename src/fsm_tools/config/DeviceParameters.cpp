#include "../../../include/fsm_tools/config/DeviceParameters.h"
#include <Arduino.h>
#include <ctype.h>

DeviceParameters::DeviceParameters()
{
    // Build unique ID hex string and copy to fixed-size arrays
    String uniqueId = getUniqueId();
    
    // Copy to char arrays using strncpy to avoid overflow
    strncpy(cyclobotId, uniqueId.c_str(), sizeof(cyclobotId) - 1);
    cyclobotId[sizeof(cyclobotId) - 1] = '\0';  // Ensure null termination
    
    strncpy(cyclobotToken, uniqueId.c_str(), sizeof(cyclobotToken) - 1);
    cyclobotToken[sizeof(cyclobotToken) - 1] = '\0';  // Ensure null termination
    
    // Convert to uppercase (manual char-by-char conversion for safety)
    for (size_t i = 0; cyclobotId[i] != '\0'; i++) {
        cyclobotId[i] = toupper(cyclobotId[i]);
    }
    for (size_t i = 0; cyclobotToken[i] != '\0'; i++) {
        cyclobotToken[i] = toupper(cyclobotToken[i]);
    }
    
    firstAwakening = 0;             // 0 = true
    sleepLength = 2000;             // 2 seconds (example)
}