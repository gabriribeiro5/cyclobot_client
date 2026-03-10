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

BaseStrategy *simStrategyPtr = new PL_FogLightFan;

// Define states (allocated once at startup via static init)
IdleState *idleStatePtr = new IdleState;
SelfDiagnosisState *selfDiagnosisStatePtr = new SelfDiagnosisState;
HTTPClientState *communicationStatePtr = new HTTPClientState;
ConfigUpdateState *configUpdateStatePtr = new ConfigUpdateState;
CodeUpdateState *codeUpdateStatePtr = new CodeUpdateState;
SimulationState *simulationStatePtr = new SimulationState;
ErrorHandlingState *errorHandlingStatePtr = new ErrorHandlingState;

// // Create state machine (FiniteStateMachine is global; its static members initialize on first FSM construction)
FiniteStateMachine *cyclobot = new FiniteStateMachine(idleStatePtr, simStrategyPtr);

void setup() {
    // Enable communication over the USB serial port console 9600 Bps
    Serial.begin(9600);
    delay(3000); // Wait for Serial to initialize
    
    // Print EEPROM usage at startup
    // cyclobot->commPtr->visualCommPtr->print_terminal_logo();
    // cyclobot->commPtr->visualCommPtr->print_parameters(cyclobot->paramPtr);
    cyclobot->commPtr->visualCommPtr->print_eeprom_usage("[main::setup]");
    cyclobot->commPtr->visualCommPtr->print_free_memory("[main::setup]");
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] starting clock (rtc)"));
    if (!cyclobot->rtcPtr->begin()) {
        cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] RTC not found"));
    } else {
        cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] RTC clock started"));
    }
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] setting simulation strategy"));
    cyclobot->simStrategyContextPtr->setup(simStrategyPtr, cyclobot->dataPtr->configDataPtr, cyclobot->commPtr->visualCommPtr, cyclobot->rtcPtr);
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] initializing WiFi module"));
    cyclobot->commPtr->wifiCommPtr->initialize_wifi_module(cyclobot->paramPtr->wifiParametersPtr, cyclobot->commPtr->visualCommPtr);

    cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] scanning for WiFi networks"));
    cyclobot->commPtr->wifiCommPtr->scan_wifi(cyclobot->paramPtr->wifiParametersPtr, cyclobot->commPtr->visualCommPtr);
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] connecting to WiFi network"));
    cyclobot->commPtr->wifiCommPtr->connect_wifi(cyclobot->paramPtr->wifiParametersPtr, cyclobot->commPtr->visualCommPtr);
    
    cyclobot->commPtr->visualCommPtr->print_line(F("[main::setup] done"));
};

void loop() {
    delay(1000); // Wait for Serial to initialize
    cyclobot->commPtr->visualCommPtr->print(F(" ************************  ************[STATE FLOW "));
    cyclobot->commPtr->visualCommPtr->print(cyclobot->stateFlow);
    cyclobot->commPtr->visualCommPtr->print_line(F("]************  ************************ "));
    cyclobot->commPtr->visualCommPtr->print_free_memory("[main::loop]");
    switch (cyclobot->stateFlow) {
        case 0: { // Self
            cyclobot->change_state(selfDiagnosisStatePtr);
            cyclobot->commPtr->visualCommPtr->print_line(F("[SelfDiagnosisState] Calling health check..."));
            cyclobot->run_health_check();
            break;
        }
        case 1: { // Comm
            cyclobot->change_state(communicationStatePtr);
            cyclobot->report_signature_request();
            cyclobot->session_new();
            cyclobot->report_config(); 
            cyclobot->report_health_check();
            break;
        }
        case 2: { // Config update
            cyclobot->change_state(configUpdateStatePtr);
            cyclobot->update_config();
            break;
        }
        case 3: { // Code update
            cyclobot->change_state(codeUpdateStatePtr);
            cyclobot->update_simulation_code();
            break;
        }
        case 4: { // Comm
            cyclobot->change_state(communicationStatePtr);
            cyclobot->session_stop();
            break;
        }
        case 5: { // Simulation
            cyclobot->change_state(simulationStatePtr);
            cyclobot->run_simulation();
            break;
        }
        case 6: { // Comm
            cyclobot->change_state(communicationStatePtr);
            cyclobot->report_simulation_data();
            break;
        }
        case 7: { // Self
            cyclobot->change_state(idleStatePtr);
            cyclobot->take_a_nap();
            cyclobot->stateFlow = -1; // Reset
            break;
        }
        case 99: { // Error
            cyclobot->change_state(errorHandlingStatePtr);
            cyclobot->handle_error();
            cyclobot->stateFlow = -1; // Reset
            break;
        }
        default: { // Reset
            cyclobot->stateFlow = -1; // Reset
            break;
        }
    }
    cyclobot->stateFlow++;
};