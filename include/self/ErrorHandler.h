#pragma once
#include "../config/ErrorHandlingParameters.h"

class ErrorHandler {
    public:
        void log_error_msg(ErrorHandlingParameters *errorHandlingParametersPtr, char* className, char* methodName, int errorType, const char* errorMsg);
        void handle_error(ErrorHandlingParameters *errorHandlingParametersPtr);
};