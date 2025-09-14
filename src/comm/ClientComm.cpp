// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class
#include "Arduino.h"
#include <ArduinoJson.h>
#include <WiFiEsp.h>
#include "../../include/comm/ClientComm.h"
#include "../../include/config/ClientParameters.h"
#include "../../include/config/WifiParameters.h"
#include "../../include/config/DeviceParameters.h"
#include "../../include/config/EcosystemParameters.h"
#include "../../include/data/SelfDiagnosisData.h"
#include "../../include/data/ConfigData.h"
#include "../../include/Context.h"

void ClientComm::trace_server(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr) {
  Serial.println(F("[ClientComm::trace_server] running..."));
  Serial.flush();

  // if you get a connection, report back via serial:
  if (wifiParametersPtr->client.connect(clientParametersPtr->apiServer, clientParametersPtr->clientPort)) {
    Serial.println(F("[ClientComm::trace_server] connected to server"));
    Serial.flush();

    // Send HTTP trace request
    wifiParametersPtr->client.println("TRACE /api HTTP/1.1");
    wifiParametersPtr->client.println("Host: ");
    wifiParametersPtr->client.println(clientParametersPtr->apiServer);
    wifiParametersPtr->client.println("Content-Type: text/plain");
    wifiParametersPtr->client.println();  // Empty server_response_line to end headers
    wifiParametersPtr->client.println(clientParametersPtr->msgTrace);

    Serial.println(F("[ClientComm::trace_server] Request sent"));
    Serial.flush();

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
    Serial.println(F("[ClientComm::trace_server] ! CLIENT CONNECTION FAILED !"));
    Serial.flush();
    clientParametersPtr->serverIsUp = false;
  }
  
  // Search trace msg
  for (int i = 0; i < sizeof(clientParametersPtr->msgTrace); i--) {
    clientParametersPtr->server_response_line = clientParametersPtr->server_response_line + clientParametersPtr->server_response[sizeof(clientParametersPtr->msgTrace) * -1];
  }
  
  if (clientParametersPtr->server_response_line == clientParametersPtr->msgTrace) {
    Serial.println(F("[ClientComm::trace_server] Response approved"));
    Serial.flush();
    clientParametersPtr->serverIsUp = true;
    clientParametersPtr->readingLines = false;
  }
}

void ClientComm::post_signature_request(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr) {
  Serial.println(F("[ClientComm::post_signature_request] running..."));
  Serial.flush();
  
  // Construct JSON payload
  clientParametersPtr->signatureRequest_Json["cyclobotId"] = deviceParametersPtr->cyclobotId; // get uuid
  clientParametersPtr->signatureRequest_Json["cyclobotToken"] = deviceParametersPtr->cyclobotToken; // get other uuid
  serializeJson(clientParametersPtr->signatureRequest_Json, clientParametersPtr->signatureRequest_Char);  // convert JSON to Char
  Serial.println(F("[ClientComm::post_signature_request] credential ready"));
  Serial.flush();
  if (true) {
    Serial.println(F("[ClientComm::post_signature_request] credential ready"));
    Serial.flush();    
  }
  
  // Send HTTP request
  // if (wifiParametersPtr->client.connected()) {
  //   Serial.println(F("[ClientComm::post_signature_request] sending request"));
  //   Serial.flush();
  //   // Client action
  //   wifiParametersPtr->client.println("POST /api/cyclobot/signature_request HTTP/1.1");
  //   wifiParametersPtr->client.print("Host: ");
  //   wifiParametersPtr->client.println(clientParametersPtr->apiServer);
  //   wifiParametersPtr->client.println("Content-Type: application/json");
  //   wifiParametersPtr->client.print("Content-Length: ");
  //   wifiParametersPtr->client.println(strlen(clientParametersPtr->signatureRequest_Char));
  //   wifiParametersPtr->client.println();  // Empty server_response_line to end headers
  //   wifiParametersPtr->client.print(clientParametersPtr->signatureRequest_Char);  // ✅ Send JSON body
    
  //   Serial.println(F("[ClientComm::post_signature_request] request sent"));
  //   Serial.flush();
  // }
  // else {
  //   Serial.println(F("[ClientComm::post_signature_request] ATENTION! Server NOT responding"));
  //   Serial.flush();
  // }
  Serial.println(F("[ClientComm::post_signature_request] done"));
  Serial.flush();
}

const char *ClientComm::get_cyclobot_session_token(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr) {
  Serial.println(F("[ClientComm::get_cyclobot_session_token] running..."));
  Serial.flush();
  
  // Construct JSON payload
  clientParametersPtr->loginParameters_Json["cyclobotId"] = deviceParametersPtr->cyclobotId;
  clientParametersPtr->loginParameters_Json["cyclobotToken"] = deviceParametersPtr->cyclobotToken;
  
  serializeJson(clientParametersPtr->loginParameters_Json, clientParametersPtr->loginParameters_Char);
  Serial.println(F("[ClientComm::get_cyclobot_session_token] credential ready"));
  Serial.flush();
  
  // if (wifiParametersPtr->client.connected()) { 
  //   // Send HTTP GET request
  //   wifiParametersPtr->client.println("GET /api/cyclobot/login HTTP/1.1");
  //   wifiParametersPtr->client.print("Host: ");
  //   wifiParametersPtr->client.println(clientParametersPtr->apiServer);
  //   wifiParametersPtr->client.println("Content-Type: application/json");
  //   wifiParametersPtr->client.print("Content-Length: ");
  //   wifiParametersPtr->client.println(strlen(clientParametersPtr->loginParameters_Char));
  //   wifiParametersPtr->client.println("Connection: close");
  //   wifiParametersPtr->client.println();  // End of headers
  //   wifiParametersPtr->client.print(clientParametersPtr->loginParameters_Char);  // JSON body
  //   Serial.println(F("[ClientComm::get_cyclobot_session_token] Request sent"));
  //   Serial.flush();
  // } else {
  //   Serial.println(F("[ClientComm::get_cyclobot_session_token] [ERROR] Client not connected"));
  //   Serial.flush();
  //   return "";
  // }
  
  // Wait for server response
  // clientParametersPtr->timoutReference = millis();
  // while (!wifiParametersPtr->client.available()) {
  //   if (millis() - clientParametersPtr->timoutReference > clientParametersPtr->responseTimeoutLimit) {
  //     Serial.println(F("[ClientComm::get_cyclobot_session_token] [ERROR] Timeout waiting for response"));
  //     Serial.flush();
  //     wifiParametersPtr->client.stop();
  //     return "";
  //   }
  // }

  // Read and store entire response
  // clientParametersPtr->serverRawResponse = "";
  // while (wifiParametersPtr->client.available()) {
  //   clientParametersPtr->serverRawResponse += wifiParametersPtr->client.read();
  // }

  // Debug raw response (optional)
  Serial.println(F("[ClientComm::get_cyclobot_session_token] Raw response:"));
  Serial.flush();
  Serial.println(clientParametersPtr->serverRawResponse);
  Serial.flush();

  // Find start of JSON (skip HTTP headers)
  clientParametersPtr->jsonPart = strchr(clientParametersPtr->serverRawResponse, '{');
  if (clientParametersPtr->jsonPart == NULL) {
    Serial.println(F("[ClientComm::get_cyclobot_session_token] [ERROR] No JSON found in response (char '{' not found)"));
    Serial.flush();
    return "";
  }

  // Parse JSON
  clientParametersPtr->deserializationError = deserializeJson(clientParametersPtr->responseJson, clientParametersPtr->jsonPart);
  if (clientParametersPtr->deserializationError) {
    Serial.print("[ClientComm::get_cyclobot_session_token] [ERROR] Failed to parse JSON: ");
    Serial.flush();
    Serial.println(clientParametersPtr->deserializationError.c_str());
    Serial.flush();
    return "";
  }

  // Extract token
  if (clientParametersPtr->responseJson.containsKey("sessionToken")) {
    clientParametersPtr->sessionToken = clientParametersPtr->responseJson["sessionToken"].as<char>();
    Serial.print("[ClientComm::get_cyclobot_session_token] Token received: ");
    Serial.flush();
    Serial.println(clientParametersPtr->sessionToken);
    Serial.flush();
  } else {
    Serial.println(F("[ClientComm::get_cyclobot_session_token] [ERROR] sessionToken not found in JSON"));
    Serial.flush();
    return "";
  }
}

void ClientComm::put_invalid_cyclobot_session_token() {
  Serial.println(F("[ClientComm::put_invalid_cyclobot_session_token] running..."));
  Serial.flush();
  // close server connection and clear session token
  Serial.println(F("[ClientComm::put_invalid_cyclobot_session_token] done"));
  Serial.flush();
}

void ClientComm::post_cyclobot_config(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, ConfigData *configDataPtr, EcosystemParameters *ecosystemParametersPtr) {
  Serial.println(F("[ClientComm::post_cyclobot_config] running..."));
  Serial.flush();
  
  // *** BUILD JSON STRUCT ***
  // Device config
  configDataPtr->config_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  configDataPtr->config_Json["session_token"] = clientParametersPtr->sessionToken; // uuid
  configDataPtr->config_Json["device_sleep_lenght"] = deviceParametersPtr->sleepLength;
  Serial.println(F("[ClientComm::post_cyclobot_config] json loaded with Device config"));
  Serial.flush();
  
  // Wifi config
  configDataPtr->config_Json["wifi_status"] = wifiParametersPtr->wifiStatus;
  configDataPtr->config_Json["wifi_firmware_latest_version"] = wifiParametersPtr->wifiFirmwareLatestVersion;
  configDataPtr->config_Json["network_ssid_index"] = wifiParametersPtr->networkSsidIndex;
  configDataPtr->config_Json["wait_time_per_connection_attempt"] = wifiParametersPtr->waitTimePerConnectionAttempt;
  configDataPtr->config_Json["max_connectoin_attempt"] = wifiParametersPtr->maxConnectoinAttempt;
  configDataPtr->config_Json["conn_attempt_count"] = wifiParametersPtr->connAttemptCount;
  configDataPtr->config_Json["wait_time_per_scan_attempt"] = wifiParametersPtr->waitTimePerScanAttempt;
  configDataPtr->config_Json["wifi_max_scan_attempt"] = wifiParametersPtr->wifiMaxScanAttempt;
  configDataPtr->config_Json["scan_count"] = wifiParametersPtr->scanCount;
  Serial.println(F("[ClientComm::post_cyclobot_config] json loaded with Wifi config"));
  Serial.flush();
  
  // Client config
  configDataPtr->config_Json["wait_time_per_connection_attempt"] = clientParametersPtr->waitTimePerConnectionAttempt;
  configDataPtr->config_Json["response_timeout_limit"] = clientParametersPtr->responseTimeoutLimit;
  Serial.println(F("[ClientComm::post_cyclobot_config] json loaded with Client config"));
  Serial.flush();
  
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
  Serial.println(F("[ClientComm::post_cyclobot_config] json loaded with Ecosystem config"));
  Serial.flush();
  
  // *** CONVERT JSON TO STRING ***
  serializeJson(configDataPtr->config_Json, configDataPtr->config_Char);
  Serial.println(F("[ClientComm::post_cyclobot_config] json to string done"));
  Serial.flush();
  
  // Send HTTP request
  // if (wifiParametersPtr->client.connected()) {
  //   // Client action
  //   wifiParametersPtr->client.println("POST /api/cyclobot/post_config HTTP/1.1");
  //   wifiParametersPtr->client.print("Host: ");
  //   wifiParametersPtr->client.println(clientParametersPtr->apiServer);
  //   wifiParametersPtr->client.println("Content-Type: application/json");
  //   wifiParametersPtr->client.print("Content-Length: ");
  //   wifiParametersPtr->client.println(strlen(configDataPtr->config_Char));
  //   wifiParametersPtr->client.println(); // Empty server_response_line to end headers
  //   wifiParametersPtr->client.print(configDataPtr->config_Char);  // ✅ Send JSON body

  //   // Method response
  //   Serial.println(F("[ClientComm::post_cyclobot_config] Config sent"));
  //   Serial.flush();
  // }
  // else {
  //   Serial.println(F("[ClientComm::post_cyclobot_config] ATENTION! server NOT responding"));
  //   Serial.flush();
  // }

  Serial.println(F("[ClientComm::post_cyclobot_config] json to string done"));
  Serial.flush();
}

void ClientComm::post_cyclobot_diagnosis(ClientParameters *clientParametersPtr, WifiParameters *wifiParametersPtr, DeviceParameters *deviceParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr) {
  Serial.println(F("[ClientComm::post_cyclobot_diagnosis] running..."));
  Serial.flush();
  
  // Build json struct and convert to string
  selfDiagnosisDataPtr->selfDiagnosis_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  selfDiagnosisDataPtr->selfDiagnosis_Json["session_token"] = clientParametersPtr->sessionToken; // uuid
  selfDiagnosisDataPtr->selfDiagnosis_Json["diagnosis_date_time"] = selfDiagnosisDataPtr->diagnosisDateTime; // date and time
  selfDiagnosisDataPtr->selfDiagnosis_Json["wifi_connected"] = selfDiagnosisDataPtr->wifiIsConnected; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["watering_system"] = selfDiagnosisDataPtr->wateringSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["river_system"] = selfDiagnosisDataPtr->riverSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["wind_system"] = selfDiagnosisDataPtr->windSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["lighting_system"] = selfDiagnosisDataPtr->lightingSystemOK; // int
  Serial.println(F("[ClientComm::post_cyclobot_diagnosis] loading report..."));
  Serial.flush();
  // serializeJson(selfDiagnosisDataPtr->selfDiagnosis_Json, selfDiagnosisDataPtr->selfDiagnosis_Char);  // convert JSON to Char
  Serial.println(F("[ClientComm::post_cyclobot_diagnosis] report ready"));
  Serial.flush();
  
  // Send HTTP request
  // if (wifiParametersPtr->client.connected()) {
  //   // Client action
  //   wifiParametersPtr->client.println("POST /api/cyclobot/self_diagnosis HTTP/1.1");
  //   wifiParametersPtr->client.print("Host: ");
  //   wifiParametersPtr->client.println(clientParametersPtr->apiServer);
  //   wifiParametersPtr->client.println("Content-Type: application/json");
  //   wifiParametersPtr->client.print("Content-Length: ");
  //   wifiParametersPtr->client.println(strlen(selfDiagnosisDataPtr->selfDiagnosis_Char));
  //   wifiParametersPtr->client.println(); // Empty server_response_line to end headers
  //   wifiParametersPtr->client.print(selfDiagnosisDataPtr->selfDiagnosis_Char);  // ✅ Send JSON body
    
  //   // Method response
  //   Serial.println(F("[ClientComm::post_cyclobot_diagnosis] Request sent"));
  //   Serial.flush();
  // }
  // else {
  //   Serial.println(F("[ClientComm::post_cyclobot_diagnosis] [ATENTION] server NOT responding"));
  //   Serial.flush();
  // }
  Serial.println(F("[ClientComm::post_cyclobot_diagnosis] -- done --"));
  Serial.flush();
}

void ClientComm::post_cyclobot_environment_state() {
  Serial.println(F("[ClientComm::post_cyclobot_environment_state] running..."));
  Serial.flush();
}

void ClientComm::get_cyclobot_config_update() {
  Serial.println(F("[ClientComm::get_cyclobot_config_update] running..."));
  Serial.flush();
}

void ClientComm::get_cyclobot_config_rollback() {
  Serial.println(F("[ClientComm::get_cyclobot_config_rollback] running..."));
  Serial.flush();
}