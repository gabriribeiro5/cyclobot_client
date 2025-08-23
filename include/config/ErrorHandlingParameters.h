#pragma once
#include <SoftwareSerial.h>

class ErrorHandlingParameters {
    public:
        // 0 = Wrong state
        int errorType;
        const char *errorClass;
        const char *errorMethod;
        const char *errorMsg;
};