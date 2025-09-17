#pragma once
#include "../config/ErrorHandlingParameters.h"
#include "../comm/VisualComm.h"

class ErrorHandler {
    public:
        void log_error_msg(ErrorHandlingParameters *errorHandlingParametersPtr, VisualComm *visualCommPtr, const char *className, const char *methodName, int errorType, const char *errorMsg);
        void handle_error(ErrorHandlingParameters *errorHandlingParametersPtr, VisualComm *visualCommPtr);
};