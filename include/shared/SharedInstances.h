#pragma once
#include "..\self\ErrorHandler.h"
#include "..\self\CheckMyHealth.h"
#include "..\comm\WifiComm.h"
#include "..\comm\ClientComm.h"
#include "..\comm\ButtonComm.h"
#include "..\comm\SoundComm.h"
#include "..\comm\VisualComm.h"
#include "..\data\SelfDiagnosisData.h"
#include "..\data\ConfigData.h"
#include "..\config\DeviceParameters.h"
#include "..\config\ErrorHandlingParameters.h"
#include "..\config\WifiParameters.h"
#include "..\config\ClientParameters.h"
#include "..\config\EcosystemParameters.h"
#include "..\config\PeripheralMapping.h"
#include "..\sensor\EnvironmentScan.h"
#include "..\actuator\EnvironmentActuator.h"

class SharedInstances {
    public:
    SharedInstances();
        // -> Board Pins
        PeripheralMapping *peripheralMappingPtr;

        // -> Self
        ErrorHandler *errorHandlerPtr;
        CheckMyHealth *checkMyHealthPtr;
        
        // -> Communication
        WifiComm *wifiCommPtr;
        ClientComm *clientCommPtr;
        ButtonComm *buttonCommPtr;
        SoundComm *soundCommPtr;
        VisualComm *visualCommPtr;

        // -> Sensors
        EnvironmentScan *environmentScanPtr;

        // -> Actuators
        EnvironmentActuator *environmentActuatorPtr;

        // -> Parameters
        DeviceParameters *deviceParametersPtr;
        ErrorHandlingParameters *errorHandlingParametersPtr;
        WifiParameters *wifiParametersPtr;
        ClientParameters *clientParametersPtr;
        EcosystemParameters *ecosystemParametersPtr;

        // -> Data
        SelfDiagnosisData *selfDiagnosisDataPtr;
        ConfigData *configDataPtr;
};