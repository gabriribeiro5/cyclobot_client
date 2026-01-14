#include "../include/fsm_tools/SelfManagementInstances.h"
#include "../include/self/ErrorHandler.h"
#include "../include/self/CheckMyHealth.h"
#include "../include/self/StorageManager.h"

SelfManagementInstances::SelfManagementInstances() {
    errorHandlerPtr = new ErrorHandler();
    checkMyHealthPtr = new CheckMyHealth();
    storageManagerPtr = new StorageManager();
};

SelfManagementInstances::~SelfManagementInstances() {
    delete errorHandlerPtr;
    delete checkMyHealthPtr;
    delete storageManagerPtr;
};