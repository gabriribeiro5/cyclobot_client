#include "../../../include/shared/cyclobot_tools/CommunicationInstances.h"
#include "../../../include/comm/WifiComm.h"
#include "../../../include/comm/ClientComm.h"
#include "../../../include/comm/ButtonComm.h"
#include "../../../include/comm/SoundComm.h"
#include "../../../include/comm/VisualComm.h"

CommunicationInstances::CommunicationInstances() {
    wifiCommPtr = new WifiComm();
    clientCommPtr = new ClientComm();
    buttonCommPtr = new ButtonComm();
    soundCommPtr = new SoundComm();
    visualCommPtr = new VisualComm();
};