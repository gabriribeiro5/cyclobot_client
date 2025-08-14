#pragma once
#include "../../self/ErrorHandler.h"
#include "../../self/CheckMyHealth.h"

class SelfManagementInstances {
    public:
        SelfManagementInstances();
        ~SelfManagementInstances();

        ErrorHandler *errorHandlerPtr;
        CheckMyHealth *checkMyHealthPtr;
};