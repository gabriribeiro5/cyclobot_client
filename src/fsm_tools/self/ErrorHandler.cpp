#include "Arduino.h"
#include "../../../include/fsm_tools/self/ErrorHandler.h"
#include "../../../include/fsm_tools/config/ErrorHandlingParameters.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"

void ErrorHandler::log_error_msg(ErrorHandlingParameters *errorHandlingParametersPtr, VisualComm *visualCommPtr, const char *className, const char *methodName, int errorType, const char *errorMsg) {
    errorHandlingParametersPtr->errorClass = className;
    errorHandlingParametersPtr->errorMethod = methodName; // 0 = Wrong state
    errorHandlingParametersPtr->errorType = errorType; // 0 = Wrong state
    errorHandlingParametersPtr->errorMsg = errorMsg;
}

void ErrorHandler::handle_error(ErrorHandlingParameters *errorHandlingParametersPtr, VisualComm *visualCommPtr) {
    return;
}