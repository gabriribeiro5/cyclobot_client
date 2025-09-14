#include <Arduino.h>
#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "../include/core_states/BaseState.h"
#include "../include/core_states/self/IdleState.h"
#include "../include/core_states/comm/HTTPClientState.h"
#include "../include/Context.h"

// Set state classes
BaseState *communicationStatePtr = new HTTPClientState();
BaseState *idleStatePtr = new IdleState();

// Create state machine
FiniteStateMachine fsm_context(idleStatePtr);

// Extra serial port for wifi
SoftwareSerial esp8266(fsm_context.paramPtr->peripheralMappingPtr->wifiEspRX,
                       fsm_context.paramPtr->peripheralMappingPtr->wifiEspTX); // software-based serial port to communicate with wifi module
                       
void setup() {
    Serial.begin(9600); // Enable communication over the USB serial port console 9600 Bps

    fsm_context.printFreeMemory("[main::setup]");

    Serial.println(F("[main::setup] starting clock (rtc)"));
    Serial.flush();
    fsm_context.rtc.begin();
    fsm_context.now = fsm_context.rtc.now();
    
    Serial.print(F("[main::setup] date: "));
    Serial.flush();
    Serial.print(fsm_context.now.day());
    Serial.flush();
    Serial.print(F("/"));
    Serial.flush();
    Serial.print(fsm_context.now.month());
    Serial.flush();
    Serial.print(F("/"));
    Serial.flush();
    Serial.println(fsm_context.now.year());
    Serial.flush();
    
    Serial.print(F("[main::setup] time: "));
    Serial.flush();
    Serial.print(fsm_context.now.hour());
    Serial.flush();
    Serial.print(F(":"));
    Serial.flush();
    Serial.print(fsm_context.now.minute());
    Serial.flush();
    Serial.print(F(":"));
    Serial.flush();
    Serial.println(fsm_context.now.second());
    Serial.flush();
    
    // Serial.println(F("[main::setup] initializing WiFi module"));
    // WiFi.init(&esp8266);
};

void loop() {
    Serial.print(F(" ************************  ************[main::loop"));
    Serial.flush();
    Serial.print(fsm_context.stateFlow);
    Serial.flush();
    Serial.println(F("]************  ************************ "));
    Serial.flush();
    fsm_context.printFreeMemory("[main::loop]");
    switch (fsm_context.stateFlow) {
        case 0:
        // this block is commented
        break;
        case 1:
        fsm_context.change_state(communicationStatePtr);
        fsm_context.report_signature_request();
        fsm_context.session_new();
        fsm_context.report_config();                 // !! [HTTPClientState::report_conf�
        fsm_context.report_health_check();           // !! [HTTPClientState::report_health_check]�
        break;
        case 2:
        // this block is commented
        break;
        default: // Reset
        fsm_context.stateFlow = -1; // Reset
        break;
    }
    fsm_context.stateFlow++;
};