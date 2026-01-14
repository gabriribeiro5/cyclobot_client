#pragma once
#include "../self/ErrorHandler.h"
#include "../self/CheckMyHealth.h"
#include "../self/StorageManager.h"

class SelfManagementInstances {
    public:
        SelfManagementInstances();
        ~SelfManagementInstances();

        ErrorHandler *errorHandlerPtr;
        CheckMyHealth *checkMyHealthPtr;
        StorageManager *storageManagerPtr;
};