#pragma once
#inculde "WifiComm.h"
#inculde "ClientComm.h"
#inculde "ButtonComm.h"
#inculde "SoundComm.h"
#inculde "VisualComm.h"
#inculde "SelfDiagnosisData.h"
#inculde "DeviceParameters.h"

class SharedInstances {
    public:
        // ********** POINTERS **********
        // -> Communication
        WifiComm *wifiCommPtr;
        ClientComm *clientCommPtr;
        ButtonComm *buttonCommPtr;
        SoundComm *soundCommPtr;
        VisualComm *visualCommPtr;

        // -> Parameters
        DeviceParameters *deviceParametersPtr;
        WifiParameters *wifiParametersPtr;
        ClientParameters *clientParametersPtr;

        // -> Data
        SelfDiagnosisData *selfDiagnosisDataPtr;
        
        // ********** INSTANCES **********
        // -> Communication
        WifiComm wifiComm;
        ClientComm clientComm;
        ButtonComm buttonComm;
        SoundComm soundComm;
        VisualComm visualComm;

        // -> Parameters
        DeviceParameters deviceParameters;
        WifiParameters wifiParameters;
        ClientParameters clientParameters;

        // -> Data
        SelfDiagnosisData selfDiagnosisData;
}