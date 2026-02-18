#pragma once
#include "../fsm_tools/self/ErrorHandler.h"
#include "../fsm_tools/self/CheckMyHealth.h"

class SelfManagementInstances {
    public:
        SelfManagementInstances();
        SelfManagementInstances(const SelfManagementInstances&) = delete;                // forbid copy constructor
        SelfManagementInstances& operator=(const SelfManagementInstances&) = delete;     // forbid copy assignment
        ~SelfManagementInstances();

        ErrorHandler *errorHandlerPtr;
        CheckMyHealth *checkMyHealthPtr;
};