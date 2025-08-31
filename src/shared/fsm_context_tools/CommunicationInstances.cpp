#include "../../../include/shared/fsm_context_tools/CommunicationInstances.h"
#include "../../../include/comm/WifiComm.h"
#include "../../../include/comm/ClientComm.h"

CommunicationInstances::CommunicationInstances() {
    wifiCommPtr = new WifiComm();
    clientCommPtr = new ClientComm();
};

CommunicationInstances::~CommunicationInstances() {
    delete wifiCommPtr;
    delete clientCommPtr;
};