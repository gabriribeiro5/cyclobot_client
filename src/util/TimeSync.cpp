#include "TimeSync.h"
#include <ctime>

// Get current hour in 24-hour format (0-23)
int getCurrentHour() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return localTime->tm_hour;
}
