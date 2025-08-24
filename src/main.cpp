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


// Set state classes
BaseState *errorHandlingStatePtr = new ErrorHandlingState();
BaseState *selfDiagnosisStatePtr = new SelfDiagnosisState();
BaseState *communicationStatePtr = new HTTPClientState();
BaseState *configUpdateStatePtr = new ConfigUpdateState();
BaseState *codeUpdateStatePtr = new CodeUpdateState();
BaseState *simulationStatePtr = new SimulationState();
BaseState *idleStatePtr = new IdleState();

// Create state machine
FiniteStateMachine cyclobot(idleStatePtr);

// Extra serial port for wifi
SoftwareSerial esp8266(cyclobot.paramPtr->peripheralMappingPtr->wifiEspRX,
                       cyclobot.paramPtr->peripheralMappingPtr->wifiEspTX); // software-based serial port to communicate with wifi module

void setup() {
    Serial.begin(9600); // Enable communication over the USB serial port console 9600 Bps
    
    // Serial.println(F(" *************************  **                                **  ************************* "));
    // Serial.println(F(" *************************  **     **********************     **  ************************* "));
    // Serial.println(F(" ***********************  **     **************************     **  *********************** "));
    // Serial.println(F(" *********************  **     ******************************    **  ********************** "));
    // Serial.println(F(" *******************  **     **********************************    **  ******************** "));
    // Serial.println(F(" *****************  **     **************************************    **  ****************** "));
    // Serial.println(F(" ***************  **     ******************************************     **  *************** "));
    // Serial.println(F("                 **    **********************************************     **                "));
    // Serial.println(F(" ************** **     **********************************************     ** ************** "));
    // Serial.println(F(" ************** **     **********************************************     ** ************** "));
    // Serial.println(F(" ************** **     ****  C Y C L O B O T   O L U S O G B A  *****     ** ************** "));
    // Serial.println(F(" ************** **     **********************************************     ** ************** "));
    // Serial.println(F(" ************** **     **********************************************     ** ************** "));
    // Serial.println(F("                **     **********************************************     **                "));
    // Serial.println(F(" ***************  **     ******************************************     **  *************** "));
    // Serial.println(F(" *****************  **     **************************************     **  ***************** "));
    // Serial.println(F(" *******************  **     **********************************     **  ******************* "));
    // Serial.println(F(" *********************  **     ******************************     **  ********************* "));
    // Serial.println(F(" ***********************  **     **************************     **  *********************** "));
    // Serial.println(F(" *************************  **     **********************     **  ************************* "));
    // Serial.println(F(" *************************  **                                **  ************************* "));
    

    Serial.println(F("[setup] starting clock (rtc)"));
    cyclobot.rtc.begin();
    cyclobot.now = cyclobot.rtc.now();
    
    Serial.print(F("[setup] date: "));
    Serial.print(cyclobot.now.day());
    Serial.print(F("/"));
    Serial.print(cyclobot.now.month());
    Serial.print(F("/"));
    Serial.println(cyclobot.now.year());
    
    Serial.print(F("[setup] time: "));
    Serial.print(cyclobot.now.hour());
    Serial.print(F(":"));
    Serial.print(cyclobot.now.minute());
    Serial.print(F(":"));
    Serial.println(cyclobot.now.second());
    
    Serial.println(F("[setup] setting simulation strategy"));
    cyclobot.simulationStrategyPtr = new TG_Water();
    
    Serial.println(F("[setup] initializing WiFi module"));
    WiFi.init(&esp8266);
};

void loop() {
    switch (cyclobot.stateFlow) {
        case 0: // Self
            cyclobot.change_state(selfDiagnosisStatePtr);
            cyclobot.run_health_check();
            break;
        case 1: // Comm
            cyclobot.change_state(communicationStatePtr);
            cyclobot.report_signature_request();
            cyclobot.session_new();
            cyclobot.report_config();
            cyclobot.report_health_check();
            break;
            case 2: // Config update
            cyclobot.change_state(configUpdateStatePtr);
            cyclobot.update_config();
            break;
            case 3: // Code update
            cyclobot.change_state(codeUpdateStatePtr);
            cyclobot.update_simulation_code();
            break;
            case 4: // Comm
            cyclobot.change_state(communicationStatePtr);
            cyclobot.session_stop(); // stop session and client
            break;
            case 5: // Simulation
            cyclobot.change_state(simulationStatePtr);
            cyclobot.run_simulation();
            case 6: // Comm
            cyclobot.change_state(communicationStatePtr);
            cyclobot.report_simulation_data();
            break;
        case 7: // Self
            cyclobot.change_state(idleStatePtr);
            cyclobot.take_a_nap();
            cyclobot.stateFlow = -1; // Reset
            break;
        case 99: // Error
            cyclobot.change_state(errorHandlingStatePtr);
            cyclobot.handle_error();
            cyclobot.stateFlow = -1; // Reset
            break;
        default: // Reset
            cyclobot.stateFlow = -1; // Reset
            break;
    }
    cyclobot.stateFlow++;
};