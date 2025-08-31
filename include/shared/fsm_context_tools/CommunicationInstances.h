#pragma once
#include "../../comm/WifiComm.h"
#include "../../comm/ClientComm.h"

class CommunicationInstances {
    public:
        CommunicationInstances();
        ~CommunicationInstances();
        
        WifiComm *wifiCommPtr;
        ClientComm *clientCommPtr;
};