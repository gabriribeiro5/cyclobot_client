#include "Arduino.h"
#include "SoftwareSerial.h"
#include "WiFiEsp.h"
#include "../include/strategies/BaseStrategy.h"
#include "../include/states/BaseState.h"
#include "../include/states/error/ErrorHandlingState.h"
#include "../include/states/self/IdleState.h"
#include "../include/states/self/SelfDiagnosisState.h"
#include "../include/states/comm/HTTPClientState.h"
#include "../include/states/update/configUpdateState.h"
#include "../include/states/update/CodeUpdateState.h"
#include "../include/states/simulation/SimulationState.h"
#include "../include/strategies/vivarium/paludarium/PL_FogLightFan.h"
#include "../include/fsm_tools/config/BaseMapping.h"
#include "../include/Context.h"

// Define strategy
BaseStrategy *simStrategyPtr = new PL_FogLightFan();
// Create state machine
BaseState *idleStatePtr = new IdleState();
FiniteStateMachine cyclobot(idleStatePtr, simStrategyPtr);
// Extra serial port for wifi
SoftwareSerial esp8266(cyclobot.paramPtr->BaseMappingPtr->wifiEspRX,
                       cyclobot.paramPtr->BaseMappingPtr->wifiEspTX); // software-based serial port to communicate with wifi module
                       
void setup() {
    Serial.begin(9600); // Enable communication over the USB serial port console 9600 Bps
    
    cyclobot.commPtr->visualCommPtr->print_terminal_logo();
    cyclobot.commPtr->visualCommPtr->print_parameters(cyclobot.paramPtr);
    cyclobot.commPtr->visualCommPtr->print_free_memory("[main::setup]");

    cyclobot.commPtr->visualCommPtr->print_line(F(" *************************  *********[IdleState::enter]*********  ************************* "));

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
    cyclobot.simStrategyContextPtr->setup(simStrategyPtr, cyclobot.commPtr->visualCommPtr, cyclobot.rtcPtr);
    
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
            BaseState *communicationStatePtr = new HTTPClientState();
            cyclobot.change_state(communicationStatePtr);
            cyclobot.report_signature_request();
            cyclobot.session_new();
            cyclobot.report_config(); 
            cyclobot.report_health_check();
            break;
        }
        case 2: { // Config update
            BaseState *configUpdateStatePtr = new ConfigUpdateState();
            cyclobot.change_state(configUpdateStatePtr);
            cyclobot.update_config();
            break;
        }
        case 3: { // Code update
            BaseState *codeUpdateStatePtr = new CodeUpdateState();
            cyclobot.change_state(codeUpdateStatePtr);
            cyclobot.update_simulation_code();
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