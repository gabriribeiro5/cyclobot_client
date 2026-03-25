#include "Arduino.h"
#include "../../../include/states/comm/HTTPClientState.h"
#include "../../../include/Context.h"

// used by context.changeState
void HTTPClientState::enter(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  ******[HTTPClientState::enter]******  ************************* "));
};

void HTTPClientState::exit(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F(" *************************  ******[HTTPClientState::exit]*******  ************************* "));
};

// error
void HTTPClientState::handle_error(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "HTTPClientState", "handle_error", 0, "wrong state");
    // start error protocol
    cyclobot->stateFlow = 98;
    return;
};

// self
void HTTPClientState::run_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "HTTPClientState", "run_health_check", 0, "wrong state");
};

// comm
void HTTPClientState::report_signature_request(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_signature_request] running..."));
    if (cyclobot->paramPtr->deviceParametersPtr->firstAwakening) {
        cyclobot->commPtr->clientCommPtr->post_signature_request(cyclobot->paramPtr->clientParametersPtr,
                                                                 cyclobot->paramPtr->wifiParametersPtr,
                                                                 cyclobot->paramPtr->deviceParametersPtr,
                                                                 cyclobot->commPtr->visualCommPtr);
        cyclobot->paramPtr->deviceParametersPtr->firstAwakening = false;
        cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_signature_request] cyclobot approved"));
    } else {
        cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_signature_request] skipped"));
    }
};

void HTTPClientState::session_new(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::session_new] running..."));
    cyclobot->commPtr->clientCommPtr->get_cyclobot_session_token(cyclobot->paramPtr->clientParametersPtr,
                                                                 cyclobot->paramPtr->wifiParametersPtr,
                                                                 cyclobot->paramPtr->deviceParametersPtr,
                                                                 cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::session_new] -- done --"));
};

void HTTPClientState::report_config(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_config] running..."));
    cyclobot->commPtr->clientCommPtr->post_cyclobot_config(cyclobot->paramPtr->clientParametersPtr,
                                                            cyclobot->paramPtr->wifiParametersPtr,
                                                            cyclobot->paramPtr->deviceParametersPtr,
                                                            cyclobot->dataPtr->configDataPtr,
                                                            cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_config] -- done --"));
};

void HTTPClientState::report_health_check(FiniteStateMachine *cyclobot) {
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_health_check] running..."));
    cyclobot->commPtr->clientCommPtr->post_cyclobot_diagnosis(cyclobot->paramPtr->clientParametersPtr,
                                                               cyclobot->paramPtr->wifiParametersPtr,
                                                               cyclobot->paramPtr->deviceParametersPtr,
                                                               cyclobot->dataPtr->selfDiagnosisDataPtr,
                                                               cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_health_check] -- done --"));
};

// update
void HTTPClientState::update_config(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "HTTPClientState", "update_config", 0, "wrong state");
};

void HTTPClientState::update_simulation_code(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "HTTPClientState", "update_simulation_code", 0, "wrong state");
};

// comm
void HTTPClientState::session_stop(FiniteStateMachine *cyclobot) {
    // stop session and client
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::session_stop] running..."));
    cyclobot->commPtr->clientCommPtr->put_invalid_cyclobot_session_token(cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->wifiCommPtr->disconnect_wifi(cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::session_stop] -- done --"));
};

// sim
void HTTPClientState::run_simulation(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "HTTPClientState", "run_simulation", 0, "wrong state");
};

// comm
void HTTPClientState::report_ecosystem_data(FiniteStateMachine *cyclobot) {
    // This method must start (and stop) both Client and Session
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_ecosystem_data] running..."));
    cyclobot->commPtr->wifiCommPtr->connect_wifi(cyclobot->paramPtr->wifiParametersPtr, cyclobot->commPtr->visualCommPtr);
    cyclobot->commPtr->clientCommPtr->get_cyclobot_session_token(cyclobot->paramPtr->clientParametersPtr,
                                                                 cyclobot->paramPtr->wifiParametersPtr,
                                                                 cyclobot->paramPtr->deviceParametersPtr,
                                                                 cyclobot->commPtr->visualCommPtr);
    
    // Stream ecosystem data until stream length time is reached                                                                 
    DateTime now = cyclobot->rtc.now();
    cyclobot->commPtr->visualCommPtr->print(F("[HTTPClientState::report_ecosystem_data] current time: "));
    cyclobot->commPtr->visualCommPtr->print_line(now.timestamp());
    
    DateTime endTime = now + cyclobot->paramPtr->clientParametersPtr->dataStreamLengthInSeconds;
    cyclobot->commPtr->visualCommPtr->print(F("[HTTPClientState::report_ecosystem_data] streaming until: "));
    cyclobot->commPtr->visualCommPtr->print_line(endTime.timestamp());
    
    while (now < endTime) {
        // BOOL
        for (int i = 0; i < cyclobot->dataPtr->ecosystemDataPtr->sensor_bool_list.size(); i++) {
            EcosystemData::Sensor_Bool sensor_bool = cyclobot->dataPtr->ecosystemDataPtr->sensor_bool_list.get(i);
            double frequency_gap = 60.0 / sensor_bool.expected_frequency;
            TimeSpan delta = now - sensor_bool.last_update;
            if (delta.totalseconds() >= frequency_gap) { // time to collect this sensor data
                cyclobot->dataPtr->ecosystemDataPtr->set_bool_measure_now(sensor_bool.name, true, cyclobot->rtcPtr);
                cyclobot->dataPtr->ecosystemDataPtr->set_bool_send_now(sensor_bool.name, true, cyclobot->rtcPtr);
                cyclobot->commPtr->visualCommPtr->print(F("    [HTTPClientState::report_ecosystem_data] BOOL sensor marked to send: "));
                cyclobot->commPtr->visualCommPtr->print_line(sensor_bool.name);
            };
        };

        // INT
        for (int i = 0; i < cyclobot->dataPtr->ecosystemDataPtr->sensor_int_list.size(); i++) {
            EcosystemData::Sensor_Int sensor_int = cyclobot->dataPtr->ecosystemDataPtr->sensor_int_list.get(i);
            double frequency_gap = 60.0 / sensor_int.expected_frequency;
            TimeSpan delta = now - sensor_int.last_update;
            if (delta.totalseconds() >= frequency_gap) { // time to collect this sensor data
                cyclobot->dataPtr->ecosystemDataPtr->set_int_measure_now(sensor_int.name, true, cyclobot->rtcPtr);
                cyclobot->dataPtr->ecosystemDataPtr->set_int_send_now(sensor_int.name, true, cyclobot->rtcPtr);
                cyclobot->commPtr->visualCommPtr->print(F("    [HTTPClientState::report_ecosystem_data] INT sensor marked to send: "));
                cyclobot->commPtr->visualCommPtr->print_line(sensor_int.name);
            };
        };

        cyclobot->simStrategyContextPtr->simulate_ecosystem(cyclobot->scannerPtr,
                                                            cyclobot->actuatorPtr,
                                                            cyclobot->dataPtr,
                                                            cyclobot->simulationStrategyPtr,
                                                            cyclobot->commPtr->visualCommPtr,
                                                            cyclobot->rtcPtr);

        cyclobot->commPtr->clientCommPtr->post_ecosystem_data(cyclobot->paramPtr->clientParametersPtr,
                                                              cyclobot->paramPtr->wifiParametersPtr,
                                                              cyclobot->paramPtr->deviceParametersPtr,
                                                              cyclobot->dataPtr->ecosystemDataPtr,
                                                              cyclobot->commPtr->visualCommPtr,
                                                              cyclobot->rtcPtr
                                                            );

        delay(1000); // avoid flooding the server with requests, adjust as needed
        now = cyclobot->rtc.now();
    }
    
    
    session_stop(cyclobot);
    cyclobot->commPtr->visualCommPtr->print_line(F("[HTTPClientState::report_ecosystem_data] -- done --"));
};

// self
void HTTPClientState::take_a_nap(FiniteStateMachine *cyclobot) {
    cyclobot->selfPtr->errorHandlerPtr->log_error_msg(cyclobot->paramPtr->errorHandlingParametersPtr, cyclobot->commPtr->visualCommPtr, "HTTPClientState", "take_a_nap", 0, "wrong state");
};

// constructor
HTTPClientState::HTTPClientState() {
    return;
};