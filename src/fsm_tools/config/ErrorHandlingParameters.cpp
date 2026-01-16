#include "../../../include/fsm_tools/config/ErrorHandlingParameters.h"

ErrorHandlingParameters::ErrorHandlingParameters()
: errorType(0),
  errorClass(nullptr),
  errorMethod(nullptr),
  errorMsg(nullptr)
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}