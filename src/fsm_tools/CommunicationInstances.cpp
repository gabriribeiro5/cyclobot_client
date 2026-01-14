#include "../include/fsm_tools/CommunicationInstances.h"
#include "../include/fsm_tools/comm/WifiComm.h"
#include "../include/fsm_tools/comm/ClientComm.h"
#include "../include/fsm_tools/comm/ButtonComm.h"
#include "../include/fsm_tools/comm/SoundComm.h"
#include "../include/fsm_tools/comm/VisualComm.h"

CommunicationInstances::CommunicationInstances() {
    wifiCommPtr = new WifiComm();
    clientCommPtr = new ClientComm();
    buttonCommPtr = new ButtonComm();
    soundCommPtr = new SoundComm();
    visualCommPtr = new VisualComm();
};

CommunicationInstances::~CommunicationInstances() {
    delete wifiCommPtr;
    delete clientCommPtr;
    delete buttonCommPtr;
    delete soundCommPtr;
    delete visualCommPtr;
};