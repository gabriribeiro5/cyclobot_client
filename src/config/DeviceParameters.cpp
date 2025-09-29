#include "../../include/config/DeviceParameters.h"
#include <Arduino.h>

DeviceParameters::DeviceParameters()
{
    cyclobotId = getUniqueId();
    cyclobotToken = getUniqueId();
    cyclobotId.toUpperCase();
    cyclobotToken.toUpperCase();
    firstAwakening = 0;             // 0 = true
    sleepLength = 3600000;          // 1h = 3600000 ms
}