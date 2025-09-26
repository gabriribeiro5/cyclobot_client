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
    
    cyclobot.commPtr->visualCommPtr->print_terminal_logo();
    cyclobot.commPtr->visualCommPtr->print_line(F(" *************************  *********[IdleState::enter]*********  ************************* "));

    cyclobot.commPtr->visualCommPtr->print_free_memory("[main::setup]");
    cyclobot.commPtr->visualCommPtr->print_line("[main::setup] cyclobot id is: " + cyclobot.paramPtr->deviceParametersPtr->cyclobotId);
    cyclobot.commPtr->visualCommPtr->print("[main::setup] sleepLength is: ");
    cyclobot.commPtr->visualCommPtr->print_line(cyclobot.paramPtr->deviceParametersPtr->sleepLength);
    cyclobot.commPtr->visualCommPtr->print("[main::setup] msgTrace is: ");
    cyclobot.commPtr->visualCommPtr->print_line(cyclobot.paramPtr->clientParametersPtr->msgTrace);
    cyclobot.commPtr->visualCommPtr->print("[main::setup] wifiSsid is: ");
    cyclobot.commPtr->visualCommPtr->print_line(cyclobot.paramPtr->wifiParametersPtr->wifiSsid);

    cyclobot.commPtr->visualCommPtr->print_line(F("[main::setup] starting clock (rtc)"));
    if (!cyclobot.rtc.begin()) {
        cyclobot.commPtr->visualCommPtr->print_line(F("[main::setup] RTC not found"));
    }
    // cyclobot.now = cyclobot.rtc.now();
    
    // cyclobot.commPtr->visualCommPtr->print(F("[main::setup] date: "));
    // cyclobot.commPtr->visualCommPtr->print(cyclobot.now.day());
    // cyclobot.commPtr->visualCommPtr->print(F("/"));
    // cyclobot.commPtr->visualCommPtr->print(cyclobot.now.month());
    // cyclobot.commPtr->visualCommPtr->print(F("/"));
    // cyclobot.commPtr->visualCommPtr->print_line(cyclobot.now.year());
    
    // cyclobot.commPtr->visualCommPtr->print(F("[main::setup] time: "));
    // cyclobot.commPtr->visualCommPtr->print(cyclobot.now.hour());
    // cyclobot.commPtr->visualCommPtr->print(F(":"));
    // cyclobot.commPtr->visualCommPtr->print(cyclobot.now.minute());
    // cyclobot.commPtr->visualCommPtr->print(F(":"));
    // cyclobot.commPtr->visualCommPtr->print_line(cyclobot.now.second());
    
    cyclobot.commPtr->visualCommPtr->print_line(F("[main::setup] setting simulation strategy"));
    cyclobot.simulationStrategyPtr = new TG_Water();
    
    // cyclobot.commPtr->visualCommPtr->print_line(F("[main::setup] initializing WiFi module"));
    WiFi.init(&esp8266);
};

void loop() {
    cyclobot.commPtr->visualCommPtr->print(F(" ************************  ************[STATE FLOW "));
    cyclobot.commPtr->visualCommPtr->print(cyclobot.stateFlow);
    cyclobot.commPtr->visualCommPtr->print_line(F("]************  ************************ "));
    cyclobot.commPtr->visualCommPtr->print_free_memory("[main::loop]");
    switch (cyclobot.stateFlow) {
        case 0: { // Self
            BaseState *selfDiagnosisStatePtr = new SelfDiagnosisState();
            cyclobot.change_state(selfDiagnosisStatePtr);
            cyclobot.run_health_check();
            break;
        }
        case 1: { // Comm
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 1] Setting up communication state"));
            BaseState *communicationStatePtr = new HTTPClientState();
            cyclobot.change_state(communicationStatePtr);
            cyclobot.report_signature_request();
            cyclobot.session_new();
            cyclobot.report_config(); 
            cyclobot.report_health_check();
            break;
        }
        case 2: { // Config update
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 2] Creating config update pointer"));
            BaseState *configUpdateStatePtr = new ConfigUpdateState();
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 2] Changing to config update state"));
            cyclobot.change_state(configUpdateStatePtr);
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 2] Starting configuration update"));
            cyclobot.update_config();
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 2] Configuration update completed"));
            delete configUpdateStatePtr;
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 2] Pointer deleted"));
            break;
        }
        case 3: { // Code update
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 3] Preparing for code update"));
            BaseState *codeUpdateStatePtr = new CodeUpdateState();
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 3] Changing to code update state"));
            cyclobot.change_state(codeUpdateStatePtr);
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 3] Starting simulation code update"));
            cyclobot.update_simulation_code();
            cyclobot.commPtr->visualCommPtr->print_line(F("[main::loop 3] Code update completed"));
            delete codeUpdateStatePtr;
            break;
        }
        case 4: { // Comm
            BaseState *communicationStatePtr = new HTTPClientState();
            cyclobot.change_state(communicationStatePtr);
            cyclobot.session_stop();
            break;
        }
        case 5: { // Simulation
            BaseState *simulationStatePtr = new SimulationState();
            cyclobot.change_state(simulationStatePtr);
            cyclobot.run_simulation();
            break;
        }
        case 6: { // Comm
            BaseState *communicationStatePtr = new HTTPClientState();
            cyclobot.change_state(communicationStatePtr);
            cyclobot.report_simulation_data();
            break;
        }
        case 7: { // Self
            BaseState *idleStatePtr = new IdleState();
            cyclobot.change_state(idleStatePtr);
            cyclobot.take_a_nap();
            cyclobot.stateFlow = -1; // Reset
            break;
        }
        case 99: { // Error
            BaseState *errorHandlingStatePtr = new ErrorHandlingState();
            cyclobot.change_state(errorHandlingStatePtr);
            cyclobot.handle_error();
            cyclobot.stateFlow = -1; // Reset
            break;
        }
        default: { // Reset
            cyclobot.stateFlow = -1; // Reset
            break;
        }
    }
    cyclobot.stateFlow++;
};