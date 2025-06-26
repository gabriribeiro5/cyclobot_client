#pragma once
#inculde "WifiComm.h"
#inculde "ClientComm.h"
#inculde "ButtonComm.h"
#inculde "SoundComm.h"
#inculde "VisualComm.h"
#inculde "SelfDiagnosisData.h"
#inculde "ConfigData.h"
#inculde "DeviceParameters.h"
#inculde "EcosystemParameter.h"

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
        EcosystemParameter *ecosystemParameterPtr;

        // -> Data
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
        
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
        EcosystemParameter ecosystemParameter;

        // -> Data
        SelfDiagnosisData selfDiagnosisData;
        ConfigData *configDataPtr;
}