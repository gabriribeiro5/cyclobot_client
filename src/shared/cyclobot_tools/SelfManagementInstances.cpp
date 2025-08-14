#include "../../../include/shared/cyclobot_tools/SelfManagementInstances.h"
#include "../../../include/self/ErrorHandler.h"
#include "../../../include/self/CheckMyHealth.h"

SelfManagementInstances::SelfManagementInstances() {
    errorHandlerPtr = new ErrorHandler();
    checkMyHealthPtr = new CheckMyHealth();
};

SelfManagementInstances::~SelfManagementInstances() {
    delete errorHandlerPtr;
    delete checkMyHealthPtr;
};