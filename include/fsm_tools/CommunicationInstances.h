#pragma once
#include "comm/WifiComm.h"
#include "comm/ClientComm.h"
#include "comm/ButtonComm.h"
#include "comm/SoundComm.h"
#include "comm/VisualComm.h"
#include "comm/VisualComm.h"

class CommunicationInstances {
    public:
        CommunicationInstances();
        CommunicationInstances(const CommunicationInstances&) = delete;                // forbid copy constructor
        CommunicationInstances& operator=(const CommunicationInstances&) = delete;     // forbid copy assignment
        ~CommunicationInstances();
        
        WifiComm *wifiCommPtr;
        ClientComm *clientCommPtr;
        ButtonComm *buttonCommPtr;
        SoundComm *soundCommPtr;
        VisualComm *visualCommPtr;
};