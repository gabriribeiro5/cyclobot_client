#pragma once
#include <SoftwareSerial.h>

class ErrorHandlingParameters {
    public:
        // 0 = Wrong state
        int errorType;
        char *errorClass;
        char *errorMethod;
        char *errorMsg;
};