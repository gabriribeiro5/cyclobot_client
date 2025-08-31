#include "../../../include/shared/fsm_context_tools/ParameterInstances.h"
#include "../../../include/config/DeviceParameters.h"
#include "../../../include/config/WifiParameters.h"
#include "../../../include/config/ClientParameters.h"
#include "../../../include/config/EcosystemParameters.h"
#include "../../../include/config/PeripheralMapping.h"

ParameterInstances::ParameterInstances() {
    // -> Board Pins
    peripheralMappingPtr = new PeripheralMapping();

    // -> Parameters
    deviceParametersPtr = new DeviceParameters();
    wifiParametersPtr = new WifiParameters();
    clientParametersPtr = new ClientParameters();
    ecosystemParametersPtr = new EcosystemParameters();
};

ParameterInstances::~ParameterInstances() {
    // -> Board Pins
    delete peripheralMappingPtr;

    // -> Parameters
    delete deviceParametersPtr;
    delete wifiParametersPtr;
    delete clientParametersPtr;
    delete ecosystemParametersPtr;
};