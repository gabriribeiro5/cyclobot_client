// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class
#include "Arduino.h"
#include <ArduinoJson.h>
#include <WiFiEsp.h>
#include "../../../include/fsm_tools/comm/ClientComm.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../../include/fsm_tools/config/ClientParameters.h"
#include "../../../include/fsm_tools/config/WifiParameters.h"
#include "../../../../include/fsm_tools/config/DeviceParameters.h"
#include "../../../include/fsm_tools/data/SelfDiagnosisData.h"
#include "../../../include/fsm_tools/data/ConfigData.h"
#include "../../../include/fsm_tools/StrategyDataInstances.h"
#include "../../../include/Context.h"

void ClientComm::trace_server(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::trace_server] running..."));

  // if you get a connection, report back via serial:
  if (wifiParametersPtr->client.connect(clientParametersPtr->apiServer, clientParametersPtr->clientPort)) {
    visualCommPtr->print_line(F("    [ClientComm::trace_server] connected to server"));

    // Send HTTP trace request
    wifiParametersPtr->client.println("TRACE /api HTTP/1.1");
    wifiParametersPtr->client.println("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: text/plain");
    wifiParametersPtr->client.println();  // Empty server_response_line to end headers
    wifiParametersPtr->client.println(clientParametersPtr->msgTrace);

    visualCommPtr->print_line(F("    [ClientComm::trace_server] Request sent"));

    // Get response
    while (wifiParametersPtr->client.connected() && clientParametersPtr->readingLines) {
      while (wifiParametersPtr->client.available() && clientParametersPtr->readingLines) {
        // get response
        clientParametersPtr->server_response_chars = wifiParametersPtr->client.read();
        if (clientParametersPtr->server_response_chars != '\n') {
          clientParametersPtr->server_response = clientParametersPtr->server_response + clientParametersPtr->server_response_chars;
        }
      }
    }
  }
  else {
    visualCommPtr->print_line(F("    [ClientComm::trace_server] ! CLIENT CONNECTION FAILED !"));
    clientParametersPtr->serverIsUp = false;
  }

  // Search trace msg in response
  if (strstr(clientParametersPtr->server_response, clientParametersPtr->msgTrace) != NULL) {
    visualCommPtr->print_line(F("    [ClientComm::trace_server] Response approved"));
    clientParametersPtr->serverIsUp = true;
  } else {
    visualCommPtr->print_line(F("    [ClientComm::trace_server] Response does not match"));
    visualCommPtr->print_line(F("    [ClientComm::trace_server] Response: "));
    clientParametersPtr->serverIsUp = false;
    visualCommPtr->print_line(clientParametersPtr->server_response);
  }
}

void ClientComm::post_signature_request(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::post_signature_request] running..."));
  
  // Construct JSON payload
  clientParametersPtr->signatureRequest_Json["cyclobotId"] = deviceParametersPtr->cyclobotId; // get uuid
  clientParametersPtr->signatureRequest_Json["cyclobotToken"] = deviceParametersPtr->cyclobotToken; // get other uuid
  serializeJson(clientParametersPtr->signatureRequest_Json, clientParametersPtr->signatureRequest_Char);  // convert JSON to Char
  
  visualCommPtr->print_line(F("    [ClientComm::post_signature_request] credentials ready..."));
  // Send HTTP request
  if (wifiParametersPtr->client.connected()) {
    // Client action
    wifiParametersPtr->client.println("POST /api/cyclobot/signature_request HTTP/1.1");
    wifiParametersPtr->client.print("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: application/json");
    wifiParametersPtr->client.print("Content-Length: ");
    wifiParametersPtr->client.println(strlen(clientParametersPtr->signatureRequest_Char));
    wifiParametersPtr->client.println();  // Empty server_response_line to end headers
    wifiParametersPtr->client.print(clientParametersPtr->signatureRequest_Char);  // ✅ Send JSON body

    // Method response
    visualCommPtr->print_line(F("    [ClientComm::post_signature_request] Request sent"));
  }
  else {
    visualCommPtr->print_line(F("    [ClientComm::post_signature_request] ATENTION! Client couldn't connect to server"));
  }
}

const char *ClientComm::get_cyclobot_session_token(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] running..."));

  // Construct JSON payload
  clientParametersPtr->loginParameters_Json["cyclobotId"] = deviceParametersPtr->cyclobotId;
  clientParametersPtr->loginParameters_Json["cyclobotToken"] = deviceParametersPtr->cyclobotToken;

  serializeJson(clientParametersPtr->loginParameters_Json, clientParametersPtr->loginParameters_Char);

  if (wifiParametersPtr->client.connected()) { 
    // Send HTTP GET request
    wifiParametersPtr->client.println("GET /api/cyclobot/login HTTP/1.1");
    wifiParametersPtr->client.print("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: application/json");
    wifiParametersPtr->client.print("Content-Length: ");
    wifiParametersPtr->client.println(strlen(clientParametersPtr->loginParameters_Char));
    wifiParametersPtr->client.println("Connection: close");
    wifiParametersPtr->client.println();  // End of headers
    wifiParametersPtr->client.print(clientParametersPtr->loginParameters_Char);  // JSON body
    visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] Request sent"));
  } else {
    visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] [ERROR] Client not connected"));
    return "";
  }

  // Wait for server response
  clientParametersPtr->timoutReference = millis();
  while (!wifiParametersPtr->client.available()) {
    if (millis() - clientParametersPtr->timoutReference > clientParametersPtr->responseTimeoutLimit) {
      visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] [ERROR] Timeout waiting for response"));
      wifiParametersPtr->client.stop();
      return "";
    }
  }

  // Read and store entire response
  clientParametersPtr->serverRawResponse = "";
  while (wifiParametersPtr->client.available()) {
    clientParametersPtr->serverRawResponse += wifiParametersPtr->client.read();
  }

  // Debug raw response (optional)
  visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] Raw response:"));
  visualCommPtr->print_line(clientParametersPtr->serverRawResponse);

  // Find start of JSON (skip HTTP headers)
  clientParametersPtr->jsonPart = strchr(clientParametersPtr->serverRawResponse, '{');
  if (clientParametersPtr->jsonPart == NULL) {
    visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] [ERROR] No JSON found in response (char '{' not found)"));
    return "";
  }

  // Parse JSON
  clientParametersPtr->deserializationError = deserializeJson(clientParametersPtr->responseJson, clientParametersPtr->jsonPart);
  if (clientParametersPtr->deserializationError) {
    visualCommPtr->print("[ClientComm::get_cyclobot_session_token] [ERROR] Failed to parse JSON: ");
    visualCommPtr->print_line(clientParametersPtr->deserializationError.c_str());
    return "";
  }

  // Extract token
  if (clientParametersPtr->responseJson.containsKey("sessionToken")) {
    clientParametersPtr->sessionToken = clientParametersPtr->responseJson["sessionToken"].as<const char*>();
    visualCommPtr->print("[ClientComm::get_cyclobot_session_token] Token received: ");
    visualCommPtr->print_line(clientParametersPtr->sessionToken);
  } else {
    visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_session_token] [ERROR] sessionToken not found in JSON"));
    return "";
  }
}

void ClientComm::put_invalid_cyclobot_session_token(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::put_invalid_cyclobot_session_token] running..."));
  // close server connection and clear session token
  visualCommPtr->print_line(F("    [ClientComm::put_invalid_cyclobot_session_token] -- done --"));
}

void ClientComm::post_cyclobot_config(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, ConfigData *configDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::post_cyclobot_config] running..."));

  // Allocate TEMPORARY JSON document
  DynamicJsonDocument config_Json(ConfigData::CONFIG_JSON_CAPACITY);

  // *** BUILD JSON STRUCT ***
  // Device config
  config_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  config_Json["session_token"] = clientParametersPtr->sessionToken; // uuid
  config_Json["device_sleep_lenght"] = deviceParametersPtr->sleepLength;
  
  // Wifi config
  config_Json["wifi_status"] = wifiParametersPtr->wifiStatus;
  config_Json["wifi_firmware_latest_version"] = wifiParametersPtr->wifiFirmwareLatestVersion;
  config_Json["network_ssid_index"] = wifiParametersPtr->networkSsidIndex;
  config_Json["wait_time_per_connection_attempt"] = wifiParametersPtr->waitTimePerConnectionAttemptInMillis;
  config_Json["max_connectoin_attempt"] = wifiParametersPtr->maxConnectionAttempt;
  config_Json["conn_attempt_count"] = wifiParametersPtr->connAttemptCount;
  config_Json["wait_time_per_scan_attempt"] = wifiParametersPtr->waitTimePerScanAttempt;
  config_Json["wifi_max_scan_attempt"] = wifiParametersPtr->wifiMaxScanAttempt;
  config_Json["scan_count"] = wifiParametersPtr->scanCount;
  
  // Client config
  config_Json["wait_time_per_connection_attempt"] = clientParametersPtr->waitTimePerConnectionAttemptInMillis;
  config_Json["response_timeout_limit"] = clientParametersPtr->responseTimeoutLimit;

  // Strategy config
  // config_Json["soil_moisture_limit"] = ecosystemParametersPtr->soilMoistureLimit;
  // config_Json["current_temperature"] = ecosystemParametersPtr->currentTemperature;
  // config_Json["max_temperature_expected"] = ecosystemParametersPtr->maxTemperatureExpected;
  // config_Json["initial_watering_time_limit"] = ecosystemParametersPtr->initialWateringTimeLimit;
  // config_Json["growth_rate"] = ecosystemParametersPtr->growthRate;
  // config_Json["decrease_rate"] = ecosystemParametersPtr->decreaseRate;
  // config_Json["watering_time_limit"] = ecosystemParametersPtr->wateringTimeLimit;
  // config_Json["climate"] = ecosystemParametersPtr->climate;
  // config_Json["soil_is_wet"] = ecosystemParametersPtr->soilIsWet;
  // config_Json["sun_light_available"] = ecosystemParametersPtr->sunLightAvailable;
  // config_Json["standBy"] = ecosystemParametersPtr->standBy;

  // *** CONVERT JSON TO STRING ***
  serializeJson(config_Json, configDataPtr->config_Char);

  // *** JSON OBJECT AUTOMATICALLY FREED (goes out of scope) ***

  // Send HTTP request
  if (wifiParametersPtr->client.connected()) {
    // Client action
    wifiParametersPtr->client.println("POST /api/cyclobot/post_config HTTP/1.1");
    wifiParametersPtr->client.print("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: application/json");
    wifiParametersPtr->client.print("Content-Length: ");
    wifiParametersPtr->client.println(strlen(configDataPtr->config_Char));
    wifiParametersPtr->client.println(); // Empty server_response_line to end headers
    wifiParametersPtr->client.print(configDataPtr->config_Char);  // ✅ Send JSON body

    // Method response
    visualCommPtr->print_line(F("    [ClientComm::post_cyclobot_config] Config sent"));
  }
  else {
    visualCommPtr->print_line(F("    [ClientComm::post_cyclobot_config] ATENTION! Client couldn't connect to server"));
  }
}

void ClientComm::post_cyclobot_diagnosis(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::post_cyclobot_diagnosis] running..."));

  // Allocate TEMPORARY JSON document
  DynamicJsonDocument selfDiagnosis_Json(SelfDiagnosisData::SELFDIAG_JSON_CAPACITY);

  // Build json struct and convert to string
  selfDiagnosis_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  selfDiagnosis_Json["session_token"] = clientParametersPtr->sessionToken; // uuid
  selfDiagnosis_Json["diagnosis_date_time"] = selfDiagnosisDataPtr->diagnosisDateTime; // date and time
  selfDiagnosis_Json["wifi_connected"] = selfDiagnosisDataPtr->wifiIsConnected; // int
  selfDiagnosis_Json["watering_system"] = selfDiagnosisDataPtr->wateringSystemOK; // int
  selfDiagnosis_Json["river_system"] = selfDiagnosisDataPtr->riverSystemOK; // int
  selfDiagnosis_Json["wind_system"] = selfDiagnosisDataPtr->windSystemOK; // int
  selfDiagnosis_Json["lighting_system"] = selfDiagnosisDataPtr->lightingSystemOK; // int
  serializeJson(selfDiagnosis_Json, selfDiagnosisDataPtr->selfdiag_Char);  // convert JSON to Char

  // *** JSON OBJECT AUTOMATICALLY FREED (goes out of scope) ***

  // Send HTTP request
  if (wifiParametersPtr->client.connected()) {
    // Client action
    wifiParametersPtr->client.println("POST /api/cyclobot/self_diagnosis HTTP/1.1");
    wifiParametersPtr->client.print("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: application/json");
    wifiParametersPtr->client.print("Content-Length: ");
    wifiParametersPtr->client.println(strlen(selfDiagnosisDataPtr->selfdiag_Char));
    wifiParametersPtr->client.println(); // Empty server_response_line to end headers
    wifiParametersPtr->client.print(selfDiagnosisDataPtr->selfdiag_Char);  // ✅ Send JSON body

    // Method response
    visualCommPtr->print_line(F("    [ClientComm::post_cyclobot_diagnosis] Request sent"));
  }
  else {
    visualCommPtr->print_line(F("    [ClientComm::post_cyclobot_diagnosis] [ATENTION] Client couldn't connect to server"));
  }
}

void ClientComm::post_ecosystem_data(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, EcosystemData *ecosystemDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtcPtr) {
  visualCommPtr->print_line(F("    [ClientComm::post_ecosystem_data] running..."));
  
  // build JSON body with sensor data
  DynamicJsonDocument sensorData_Json(200); // adjust capacity as needed
  sensorData_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  sensorData_Json["session_token"] = clientParametersPtr->sessionToken; // uuid

  // Walk thru sensor lists and get data to send to server
  // BOOL
  for (int i = 0; i < ecosystemDataPtr->sensor_bool_list.size(); i++) {
    EcosystemData::Sensor_Bool sensor_bool = ecosystemDataPtr->sensor_bool_list.get(i);
    if (sensor_bool.send_now) {
      sensorData_Json[sensor_bool.name] = sensor_bool.value;
      ecosystemDataPtr->set_bool_send_now(sensor_bool.name, false, rtcPtr); // reset send_now after including in JSON
    }
  }
  // INT
  for (int i = 0; i < ecosystemDataPtr->sensor_int_list.size(); i++) {
    EcosystemData::Sensor_Int sensor_int = ecosystemDataPtr->sensor_int_list.get(i);
    if (sensor_int.send_now) {
      sensorData_Json[sensor_int.name] = sensor_int.value;
      ecosystemDataPtr->set_int_send_now(sensor_int.name, false, rtcPtr); // reset send_now after including in JSON
    }
  }

  // Convert JSON to Char
  serializeJson(sensorData_Json, ecosystemDataPtr->sensorData_Char);
      
  // Send HTTP request
  if (wifiParametersPtr->client.connected()) {
    // Client action
    wifiParametersPtr->client.println("POST /api/cyclobot/sensor_data HTTP/1.1");
    wifiParametersPtr->client.print("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: application/json");
    
    wifiParametersPtr->client.print("Content-Length: ");
    wifiParametersPtr->client.println(strlen(ecosystemDataPtr->sensorData_Char));
    wifiParametersPtr->client.println();                                 // Empty server_response_line to end headers
    wifiParametersPtr->client.print(ecosystemDataPtr->sensorData_Char);            // ✅ Send JSON body

    // Method response
    visualCommPtr->print_line(F("    [ClientComm::post_ecosystem_data] Request sent"));
  }
  else {
    visualCommPtr->print_line(F("    [ClientComm::post_ecosystem_data] [ATENTION] Client couldn't connect to server"));
  }
}

void ClientComm::get_cyclobot_config_update(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_config_update] running..."));
}

void ClientComm::get_cyclobot_config_rollback(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [ClientComm::get_cyclobot_config_rollback] running..."));
}