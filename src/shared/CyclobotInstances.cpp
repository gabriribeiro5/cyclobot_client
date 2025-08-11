#include "..\..\include\shared\CyclobotInstances.h"
#include "..\..\include\self\ErrorHandler.h"
#include "..\..\include\self\CheckMyHealth.h"
#include "..\..\include\comm\WifiComm.h"
#include "..\..\include\comm\ClientComm.h"
#include "..\..\include\comm\ButtonComm.h"
#include "..\..\include\comm\SoundComm.h"
#include "..\..\include\comm\VisualComm.h"
#include "..\..\include\data\SelfDiagnosisData.h"
#include "..\..\include\data\ConfigData.h"
#include "..\..\include\config\DeviceParameters.h"
#include "..\..\include\config\ErrorHandlingParameters.h"
#include "..\..\include\config\WifiParameters.h"
#include "..\..\include\config\ClientParameters.h"
#include "..\..\include\config\EcosystemParameters.h"
#include "..\..\include\config\PeripheralMapping.h"
#include "..\..\include\sensor\EnvironmentScan.h"
#include "..\..\include\actuator\EnvironmentActuator.h"

CyclobotInstances::CyclobotInstances() {
    // -> Self
    checkMyHealthPtr = new CheckMyHealth();
    errorHandlerPtr = new ErrorHandler();
    
    // -> Communication
    wifiCommPtr = new WifiComm();
    clientCommPtr = new ClientComm();
    buttonCommPtr = new ButtonComm();
    soundCommPtr = new SoundComm();
    visualCommPtr = new VisualComm();

    // -> Sensors
    environmentScanPtr = new EcosystemScanner();

    // -> Actuators
    environmentActuatorPtr = new EcosystemActuator();

    // -> Parameters
    deviceParametersPtr = new DeviceParameters();
    errorHandlingParametersPtr = new ErrorHandlingParameters();
    wifiParametersPtr = new WifiParameters();
    clientParametersPtr = new ClientParameters();
    ecosystemParametersPtr = new EcosystemParameters();
    peripheralMappingPtr = new PeripheralMapping();
    
    // -> Data
    selfDiagnosisDataPtr = new SelfDiagnosisData();
    configDataPtr = new ConfigData();
};