#pragma once
#include "../../comm/WifiComm.h"
#include "../../comm/ClientComm.h"
#include "../../comm/ButtonComm.h"
#include "../../comm/SoundComm.h"
#include "../../comm/VisualComm.h"
#include "../../comm/VisualComm.h"

class CommunicationInstances {
    public:
        CommunicationInstances();
        ~CommunicationInstances();
        
        WifiComm *wifiCommPtr;
        ClientComm *clientCommPtr;
        ButtonComm *buttonCommPtr;
        SoundComm *soundCommPtr;
        VisualComm *visualCommPtr;
        VisualComm *visualCommPtr;
};