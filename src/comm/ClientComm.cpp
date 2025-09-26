// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class
#include "Arduino.h"
#include <ArduinoJson.h>
#include <WiFiEsp.h>
#include "../../include/comm/ClientComm.h"
#include "../../include/comm/VisualComm.h"
#include "../../include/config/ClientParameters.h"
#include "../../include/config/WifiParameters.h"
#include "../../include/config/DeviceParameters.h"
#include "../../include/config/EcosystemParameters.h"
#include "../../include/data/SelfDiagnosisData.h"
#include "../../include/data/ConfigData.h"
#include "../../include/Context.h"

void ClientComm::trace_server(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::trace_server] running..."));

  // if you get a connection, report back via serial:
  if (wifiParametersPtr->client.connect(clientParametersPtr->apiServer, clientParametersPtr->clientPort)) {
    visualCommPtr->print_line(F("[ClientComm::trace_server] connected to server"));

    // Send HTTP trace request
    wifiParametersPtr->client.println("TRACE /api HTTP/1.1");
    wifiParametersPtr->client.println("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: text/plain");
    wifiParametersPtr->client.println();  // Empty server_response_line to end headers
    wifiParametersPtr->client.println(clientParametersPtr->msgTrace);

    visualCommPtr->print_line(F("[ClientComm::trace_server] Request sent"));

    // Get response
    while (wifiParametersPtr->client.connected() && clientParametersPtr->readingLines) {
      while (wifiParametersPtr->client.available() && clientParametersPtr->readingLines) {
        // get response
        clientParametersPtr->server_response_chars = wifiParametersPtr->client.read();
        if (clientParametersPtr->server_response_chars =! "\n") {
          clientParametersPtr->server_response = clientParametersPtr->server_response + clientParametersPtr->server_response_chars;
        }
      }
    }
  }
  else {
    visualCommPtr->print_line(F("[ClientComm::trace_server] ! CLIENT CONNECTION FAILED !"));
    clientParametersPtr->serverIsUp = false;
  }

  // Search trace msg
  for (unsigned int i = 0; i < sizeof(clientParametersPtr->msgTrace); i--) {
    clientParametersPtr->server_response_line = clientParametersPtr->server_response_line + clientParametersPtr->server_response[sizeof(clientParametersPtr->msgTrace) * -1];
  }
  
  if (clientParametersPtr->server_response_line == clientParametersPtr->msgTrace) {
    visualCommPtr->print_line(F("[ClientComm::trace_server] Response approved"));
    clientParametersPtr->serverIsUp = true;
    clientParametersPtr->readingLines = false;
  }
}

void ClientComm::post_signature_request(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::post_signature_request] running..."));
  
  // Construct JSON payload
  clientParametersPtr->signatureRequest_Json["cyclobotId"] = deviceParametersPtr->cyclobotId; // get uuid
  clientParametersPtr->signatureRequest_Json["cyclobotToken"] = deviceParametersPtr->cyclobotToken; // get other uuid
  serializeJson(clientParametersPtr->signatureRequest_Json, clientParametersPtr->signatureRequest_Char);  // convert JSON to Char
  
  visualCommPtr->print_line(F("[ClientComm::post_signature_request] credentials ready..."));
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
    visualCommPtr->print_line(F("[ClientComm::post_signature_request] Request sent"));
  }
  else {
    visualCommPtr->print_line(F("[ClientComm::post_signature_request] ATENTION! Client could'nt connect to server"));
  }
}

const char *ClientComm::get_cyclobot_session_token(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] running..."));

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
    visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] Request sent"));
  } else {
    visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] [ERROR] Client not connected"));
    return "";
  }

  // Wait for server response
  clientParametersPtr->timoutReference = millis();
  while (!wifiParametersPtr->client.available()) {
    if (millis() - clientParametersPtr->timoutReference > clientParametersPtr->responseTimeoutLimit) {
      visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] [ERROR] Timeout waiting for response"));
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
  visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] Raw response:"));
  visualCommPtr->print_line(clientParametersPtr->serverRawResponse);

  // Find start of JSON (skip HTTP headers)
  clientParametersPtr->jsonPart = strchr(clientParametersPtr->serverRawResponse, '{');
  if (clientParametersPtr->jsonPart == NULL) {
    visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] [ERROR] No JSON found in response (char '{' not found)"));
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
    clientParametersPtr->sessionToken = clientParametersPtr->responseJson["sessionToken"].as<char>();
    visualCommPtr->print("[ClientComm::get_cyclobot_session_token] Token received: ");
    visualCommPtr->print_line(clientParametersPtr->sessionToken);
  } else {
    visualCommPtr->print_line(F("[ClientComm::get_cyclobot_session_token] [ERROR] sessionToken not found in JSON"));
    return "";
  }
}

void ClientComm::put_invalid_cyclobot_session_token(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::put_invalid_cyclobot_session_token] running..."));
  // close server connection and clear session token
  visualCommPtr->print_line(F("[ClientComm::put_invalid_cyclobot_session_token] -- done --"));
}

void ClientComm::post_cyclobot_config(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, ConfigData *configDataPtr, EcosystemParameters *ecosystemParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::post_cyclobot_config] running..."));

  // *** BUILD JSON STRUCT ***
  // Device config
  configDataPtr->config_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  configDataPtr->config_Json["session_token"] = clientParametersPtr->sessionToken; // uuid
  configDataPtr->config_Json["device_sleep_lenght"] = deviceParametersPtr->sleepLength;
  
  // Wifi config
  configDataPtr->config_Json["wifi_status"] = wifiParametersPtr->wifiStatus;
  configDataPtr->config_Json["wifi_firmware_latest_version"] = wifiParametersPtr->wifiFirmwareLatestVersion;
  configDataPtr->config_Json["network_ssid_index"] = wifiParametersPtr->networkSsidIndex;
  configDataPtr->config_Json["wait_time_per_connection_attempt"] = wifiParametersPtr->waitTimePerConnectionAttempt;
  configDataPtr->config_Json["max_connectoin_attempt"] = wifiParametersPtr->maxConnectionAttempt;
  configDataPtr->config_Json["conn_attempt_count"] = wifiParametersPtr->connAttemptCount;
  configDataPtr->config_Json["wait_time_per_scan_attempt"] = wifiParametersPtr->waitTimePerScanAttempt;
  configDataPtr->config_Json["wifi_max_scan_attempt"] = wifiParametersPtr->wifiMaxScanAttempt;
  configDataPtr->config_Json["scan_count"] = wifiParametersPtr->scanCount;
  
  // Client config
  configDataPtr->config_Json["wait_time_per_connection_attempt"] = clientParametersPtr->waitTimePerConnectionAttempt;
  configDataPtr->config_Json["response_timeout_limit"] = clientParametersPtr->responseTimeoutLimit;

  // Ecosystem config
  configDataPtr->config_Json["soil_moisture_limit"] = ecosystemParametersPtr->soilMoistureLimit;
  configDataPtr->config_Json["current_temperature"] = ecosystemParametersPtr->currentTemperature;
  configDataPtr->config_Json["max_temperature_expected"] = ecosystemParametersPtr->maxTemperatureExpected;
  configDataPtr->config_Json["initial_watering_time_limit"] = ecosystemParametersPtr->initialWateringTimeLimit;
  configDataPtr->config_Json["growth_rate"] = ecosystemParametersPtr->growthRate;
  configDataPtr->config_Json["decrease_rate"] = ecosystemParametersPtr->decreaseRate;
  configDataPtr->config_Json["watering_time_limit"] = ecosystemParametersPtr->wateringTimeLimit;
  configDataPtr->config_Json["climate"] = ecosystemParametersPtr->climate;
  configDataPtr->config_Json["soil_is_wet"] = ecosystemParametersPtr->soilIsWet;
  configDataPtr->config_Json["sun_light_available"] = ecosystemParametersPtr->sunLightAvailable;
  configDataPtr->config_Json["standBy"] = ecosystemParametersPtr->standBy;

  // *** CONVERT JSON TO STRING ***
  serializeJson(configDataPtr->config_Json, configDataPtr->config_Char);

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
    visualCommPtr->print_line(F("[ClientComm::post_cyclobot_config] Config sent"));
  }
  else {
    visualCommPtr->print_line(F("[ClientComm::post_cyclobot_config] ATENTION! Client could'nt connect to server"));
  }
}

void ClientComm::post_cyclobot_diagnosis(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::post_cyclobot_diagnosis] running..."));

  // Build json struct and convert to string
  selfDiagnosisDataPtr->selfDiagnosis_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  selfDiagnosisDataPtr->selfDiagnosis_Json["session_token"] = clientParametersPtr->sessionToken; // uuid
  selfDiagnosisDataPtr->selfDiagnosis_Json["diagnosis_date_time"] = selfDiagnosisDataPtr->diagnosisDateTime; // date and time
  selfDiagnosisDataPtr->selfDiagnosis_Json["wifi_connected"] = selfDiagnosisDataPtr->wifiIsConnected; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["watering_system"] = selfDiagnosisDataPtr->wateringSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["river_system"] = selfDiagnosisDataPtr->riverSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["wind_system"] = selfDiagnosisDataPtr->windSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["lighting_system"] = selfDiagnosisDataPtr->lightingSystemOK; // int
  serializeJson(selfDiagnosisDataPtr->selfDiagnosis_Json, selfDiagnosisDataPtr->selfDiagnosis_Char);  // convert JSON to Char

  // Send HTTP request
  if (wifiParametersPtr->client.connected()) {
    // Client action
    wifiParametersPtr->client.println("POST /api/cyclobot/self_diagnosis HTTP/1.1");
    wifiParametersPtr->client.print("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: application/json");
    wifiParametersPtr->client.print("Content-Length: ");
    wifiParametersPtr->client.println(strlen(selfDiagnosisDataPtr->selfDiagnosis_Char));
    wifiParametersPtr->client.println(); // Empty server_response_line to end headers
    wifiParametersPtr->client.print(selfDiagnosisDataPtr->selfDiagnosis_Char);  // ✅ Send JSON body

    // Method response
    visualCommPtr->print_line(F("[ClientComm::post_cyclobot_diagnosis] Request sent"));
  }
  else {
    visualCommPtr->print_line(F("[ClientComm::post_cyclobot_diagnosis] [ATENTION] Client could'nt connect to server"));
  }
}

void ClientComm::post_cyclobot_environment_state(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::post_cyclobot_environment_state] running..."));
}

void ClientComm::get_cyclobot_config_update(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::get_cyclobot_config_update] running..."));
}

void ClientComm::get_cyclobot_config_rollback(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("[ClientComm::get_cyclobot_config_rollback] running..."));
}