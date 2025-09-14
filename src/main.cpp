#include <Arduino.h>
#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "../include/core_states/BaseState.h"
#include "../include/core_states/error/ErrorHandlingState.h"
#include "../include/core_states/self/IdleState.h"
#include "../include/core_states/self/SelfDiagnosisState.h"
#include "../include/core_states/comm/HTTPClientState.h"
#include "../include/core_states/update/ConfigUpdateState.h"
#include "../include/core_states/update/CodeUpdateState.h"
#include "../include/core_states/simulation/SimulationState.h"
#include "../include/core_states/simulation/strategy/gardening/trad_garden/TG_Water.h"
#include "../include/config/PeripheralMapping.h"
#include "../include/Context.h"

// Create state machine
BaseState *idleStatePtr = new IdleState();
FiniteStateMachine cyclobot(idleStatePtr);

// Extra serial port for wifi
SoftwareSerial esp8266(cyclobot.paramPtr->peripheralMappingPtr->wifiEspRX,
                       cyclobot.paramPtr->peripheralMappingPtr->wifiEspTX); // software-based serial port to communicate with wifi module
                       
void setup() {
    Serial.begin(9600); // Enable communication over the USB serial port console 9600 Bps
    
    Serial.println(F(" *************************  **                                **  ************************* "));
    Serial.println(F(" *************************  **     **********************     **  ************************* "));
    Serial.println(F(" ***********************  **     **************************     **  *********************** "));
    Serial.println(F(" *********************  **     ******************************    **  ********************** "));
    Serial.println(F(" *******************  **     **********************************    **  ******************** "));
    Serial.println(F(" *****************  **     **************************************    **  ****************** "));
    Serial.println(F(" ***************  **     ******************************************     **  *************** "));
    Serial.println(F("                 **    **********************************************     **                "));
    Serial.println(F(" ************** **     **********************************************     ** ************** "));
    Serial.println(F(" ************** **     **********************************************     ** ************** "));
    Serial.println(F(" ************** **     ****  C Y C L O B O T   O L U S O G B A  *****     ** ************** "));
    Serial.println(F(" ************** **     **********************************************     ** ************** "));
    Serial.println(F(" ************** **     **********************************************     ** ************** "));
    Serial.println(F("                **     **********************************************     **                "));
    Serial.println(F(" ***************  **     ******************************************     **  *************** "));
    Serial.println(F(" *****************  **     **************************************     **  ***************** "));
    Serial.println(F(" *******************  **     **********************************     **  ******************* "));
    Serial.println(F(" *********************  **     ******************************     **  ********************* "));
    Serial.println(F(" ***********************  **     **************************     **  *********************** "));
    Serial.println(F(" *************************  **     **********************     **  ************************* "));
    Serial.println(F(" *************************  **                                **  ************************* "));
    Serial.println(F(" *************************  *********[IdleState::enter]*********  ************************* "));
    Serial.flush(); // Wait until all outgoing serial data has been transmitted

    cyclobot.printFreeMemory("[main::setup]");

    Serial.println(F("[main::setup] starting clock (rtc)"));
    cyclobot.rtc.begin();
    cyclobot.now = cyclobot.rtc.now();
    
    Serial.print(F("[main::setup] date: "));
    Serial.print(cyclobot.now.day());
    Serial.print(F("/"));
    Serial.print(cyclobot.now.month());
    Serial.print(F("/"));
    Serial.println(cyclobot.now.year());
    
    Serial.print(F("[main::setup] time: "));
    Serial.print(cyclobot.now.hour());
    Serial.print(F(":"));
    Serial.print(cyclobot.now.minute());
    Serial.print(F(":"));
    Serial.println(cyclobot.now.second());
    
    Serial.println(F("[main::setup] setting simulation strategy"));
    Serial.flush();
    cyclobot.simulationStrategyPtr = new TG_Water();
    
    // Serial.println(F("[main::setup] initializing WiFi module"));
    // WiFi.init(&esp8266);
};

void loop() {
    Serial.print(F(" ************************  ************[main::loop"));
    Serial.print(cyclobot.stateFlow);
    Serial.println(F("************  ************************ "));
    Serial.flush(); // Wait until all outgoing serial data has been transmitted
    cyclobot.printFreeMemory("[main::loop]");
    switch (cyclobot.stateFlow) {
        case 0: // Self
        BaseState *selfDiagnosisStatePtr = new SelfDiagnosisState();
        cyclobot.change_state(selfDiagnosisStatePtr);
        cyclobot.printFreeMemory("[main::loop1]");
        cyclobot.run_health_check();                  // !! [FiniteStateMachine::run_health_check] �
        delete selfDiagnosisStatePtr;
        break;
        case 1: // Comm
        BaseState *communicationStatePtr = new HTTPClientState();
        cyclobot.change_state(communicationStatePtr);
        cyclobot.report_signature_request();
        cyclobot.session_new();                      // !! [HTTPClientState::session_new] Free Memory: 55�
        // cyclobot.report_config();                 // !! [HTTPClientState::report_conf�
        // cyclobot.report_health_check();           // !! [HTTPClientState::report_health_check]�
        break;
        case 2: // Config update
        BaseState *configUpdateStatePtr = new ConfigUpdateState();
        cyclobot.change_state(configUpdateStatePtr);
        cyclobot.update_config();
        delete configUpdateStatePtr;
        break;
        case 3: // Code update
        BaseState *codeUpdateStatePtr = new CodeUpdateState();
        cyclobot.change_state(codeUpdateStatePtr);
        cyclobot.update_simulation_code();
        delete codeUpdateStatePtr;
        break;
        case 4: // Comm
        cyclobot.change_state(communicationStatePtr);
        // cyclobot.session_stop();                  // !! [ClientComm::put_invalid_cyclobo�
        break;
        case 5: // Simulation
        BaseState *simulationStatePtr = new SimulationState();
        cyclobot.change_state(simulationStatePtr);
        // cyclobot.run_simulation();                // !! [SimulationState::enter]******  ***********�
        delete simulationStatePtr;
        break;
        case 6: // Comm
        cyclobot.change_state(communicationStatePtr);
        // cyclobot.report_simulation_data();           // !! [WifiComm::connect_wifi] Ru�
        break;
        case 7: // Self
        cyclobot.change_state(idleStatePtr);
        cyclobot.take_a_nap();
        cyclobot.stateFlow = -1; // Reset
        break;
        case 99: // Error
        BaseState *errorHandlingStatePtr = new ErrorHandlingState();
        cyclobot.change_state(errorHandlingStatePtr);
        cyclobot.handle_error();
        delete errorHandlingStatePtr;
        cyclobot.stateFlow = -1; // Reset
        break;
        default: // Reset
        cyclobot.stateFlow = -1; // Reset
        break;
    }
    cyclobot.stateFlow++;
};