#include "Arduino.h"
#include "../../include/self/ErrorHandler.h"
#include "../../include/config/ErrorHandlingParameters.h"

void ErrorHandler::log_error_msg(ErrorHandlingParameters *errorHandlingParametersPtr, char *className, char *methodName, int errorType, const char* errorMsg) {
    errorHandlingParametersPtr->errorClass = className;
    errorHandlingParametersPtr->errorMethod = methodName; // 0 = Wrong state
    errorHandlingParametersPtr->errorType = errorType; // 0 = Wrong state
    errorHandlingParametersPtr->errorMsg = errorMsg;
}

void ErrorHandler::handle_error(ErrorHandlingParameters *errorHandlingParametersPtr) {
    return;
}