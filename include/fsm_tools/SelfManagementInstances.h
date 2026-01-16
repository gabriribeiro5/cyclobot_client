#pragma once
#include "../fsm_tools/self/ErrorHandler.h"
#include "../fsm_tools/self/CheckMyHealth.h"
#include "../fsm_tools/self/StorageManager.h"

class SelfManagementInstances {
    public:
        SelfManagementInstances();
        ~SelfManagementInstances();

        ErrorHandler *errorHandlerPtr;
        CheckMyHealth *checkMyHealthPtr;
        StorageManager *storageManagerPtr;
};