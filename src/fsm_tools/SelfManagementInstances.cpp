#include "../include/fsm_tools/SelfManagementInstances.h"
#include "../include/fsm_tools/self/ErrorHandler.h"
#include "../include/fsm_tools/self/CheckMyHealth.h"

SelfManagementInstances::SelfManagementInstances() {
    errorHandlerPtr = new ErrorHandler();
    checkMyHealthPtr = new CheckMyHealth();
};

SelfManagementInstances::~SelfManagementInstances() {
    delete errorHandlerPtr;
    delete checkMyHealthPtr;
};