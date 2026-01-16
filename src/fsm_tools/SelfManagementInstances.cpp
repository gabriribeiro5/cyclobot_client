#include "../include/fsm_tools/SelfManagementInstances.h"
#include "../include/fsm_tools/self/ErrorHandler.h"
#include "../include/fsm_tools/self/CheckMyHealth.h"
#include "../include/fsm_tools/self/StorageManager.h"

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