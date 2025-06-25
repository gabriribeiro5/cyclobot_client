#pragma once
#inculde "ClientComm.h"
#inculde "ButtonComm.h"
#inculde "SoundComm.h"
#inculde "VisualComm.h"
#inculde "SelfDiagnosisData.h"
#inculde "DeviceParameters.h"

class SharedInstances {
    public:
        // Communication pointers
        ClientComm *clientCommPtr;
        ButtonComm *buttonCommPtr;
        SoundComm *soundCommPtr;
        VisualComm *visualCommPtr;

        // Parameter pointers
        DeviceParameters *deviceParametersPtr;
        ClientParameters *clientParametersPtr;

        // Data pointers
        SelfDiagnosisData *SelfDiagnosisDataPtr;
}