// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class

#include "Arduino.h"
#include <ArduinoJson.h>
#include <WiFi.h>
#include "ClientComm.h"
#include "ClientParameters.h"
#include "SelfDiagnosisData.h"
#include "SharedInstances.h"

void ClientComm::trace_server() {
  Serial.println("(trace_server): running...");

  // if you get a connection, report back via serial:
  if (client.connect(apiServer, clientPort)) {
    Serial.println("(trace_server): connected to server");

    // Send HTTP trace request
    client.println("TRACE /api HTTP/1.1");
    client.println("Host: " + String(apiServer));
    client.println("Content-Type: text/plain");
    client.println(msgTrace);
    client.println();  // Empty line to end headers

    Serial.println("(trace_server): Request sent");

    // Check response
    while (client.connected() && readingLines) {
      while (client.available() && readingLines) {
        String line = client.readStringUntil('\n');
        if (line == String(msgTrace)) {
          Serial.println("(trace_server): Response approved");
          clientParametersPtr->serverIsUp = true;
          clientParametersPtr->readingLines = false;
        }
      }
    }
  }
  else {
    Serial.println("(trace_server): ! CLIENT CONNECTION FAILED !");
    clientParametersPtr->serverIsUp = false;
  }
}

void ClientComm::post_signature_request() {
  Serial.println("(post_signature_request): running...");
  
  // Construct JSON payload
  signatureRequest_Json["cyclobotId"] = cyclobotId; // get uuid
  signatureRequest_Json["cyclobotToken"] = cyclobotToken; // get other uuid
  serializeJson(signatureRequest_Json, signatureRequest_String);  // convert JSON to String

  // Send HTTP request
  if (client.connected()) {
    // Client action
    client.println("POST /api/cyclobot/signature_request HTTP/1.1");
    client.print("Host: ");
    client.println(host);
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(signatureRequest_String.length());
    client.println();  // Empty line to end headers
    client.print(signatureRequest_String);  // ✅ Send JSON body

    // Method response
    Serial.println("(post_signature_request): Request sent");
  }
  else {
    Serial.println("(post_signature_request): [ATENTION] server NOT responding");
  }
}

String ClientComm::get_cyclobot_session_token() {
  Serial.println("(get_cyclobot_session_token): running...");

  // Construct JSON payload
  loginParameters_Json["cyclobotId"] = cyclobotId;
  loginParameters_Json["cyclobotToken"] = cyclobotToken;

  serializeJson(loginParameters_Json, loginParameters_String);

  if (client.connected()) { 
    // Send HTTP GET request
    client.println("GET /api/cyclobot/login HTTP/1.1");
    client.print("Host: ");
    client.println(host);
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(loginParameters_String.length());
    client.println("Connection: close");
    client.println();  // End of headers
    client.print(loginParameters_String);  // JSON body
    Serial.println("(get_cyclobot_session_token): Request sent");
  } else {
    Serial.println("(get_cyclobot_session_token): [ERROR] Client not connected");
    return "";
  }

  // Wait for server response
  clientParametersPtr->timoutReference = millis();
  while (!client.available()) {
    if (millis() - clientParametersPtr->timoutReference > clientParametersPtr->responseTimeoutLimit) {
      Serial.println("(get_cyclobot_session_token): [ERROR] Timeout waiting for response");
      client.stop();
      return "";
    }
  }

  // Read and store entire response
  clientParametersPtr->serverRawResponse = "";
  while (client.available()) {
    char c = client.read();
    clientParametersPtr->serverRawResponse += c;
  }

  // Debug raw response (optional)
  Serial.println("(get_cyclobot_session_token): Raw response:");
  Serial.println(clientParametersPtr->serverRawResponse);

  // Find start of JSON (skip HTTP headers)
  jsonStart = clientParametersPtr->serverRawResponse.indexOf('{');
  if (jsonStart == -1) {
    Serial.println("(get_cyclobot_session_token): [ERROR] No JSON found in response");
    return "";
  }

  jsonPart = clientParametersPtr->serverRawResponse.substring(jsonStart);

  // Parse JSON
  clientParametersPtr->deserializationError = deserializeJson(responseJson, jsonPart);
  if (clientParametersPtr->deserializationError) {
    Serial.print("(get_cyclobot_session_token): [ERROR] Failed to parse JSON: ");
    Serial.println(clientParametersPtr->deserializationError.c_str());
    return "";
  }

  // Extract token
  if (clientParametersPtr->responseJson.containsKey("sessionToken")) {
    clientParametersPtr->sessionToken = clientParametersPtr->responseJson["sessionToken"].as<String>();
    Serial.println("(get_cyclobot_session_token): Token received: " + clientParametersPtr->sessionToken);
  } else {
    Serial.println("(get_cyclobot_session_token): [ERROR] sessionToken not found in JSON");
    return "";
  }
}

void ClientComm::put_invalid_cyclobot_session_token() {
  Serial.println("(put_invalid_cyclobot_session_token): running...");
  // close server connection and clear session token
  Serial.println("(put_invalid_cyclobot_session_token): done");
}

void ClientComm::post_cyclobot_config() {
  Serial.println("(post_cyclobot_config): running...");

  // *** BUILD JSON STRUCT ***
  // Device config
  configDataPtr->config_Json["cyclobot_id"] = deviceParametersPtr->cyclobotId; // uuid
  configDataPtr->config_Json["session_token"] = deviceParametersPtr->sessionToken; // uuid
  configDataPtr->config_Json["device_sleep_lenght"] = deviceParametersPtr->sleepLenght;
  
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
  serializeJson(configDataPtr->config_Json, configDataPtr->config_String);

  // Send HTTP request
  if (client.connected()) {
    // Client action
    client.println("POST /api/cyclobot/signature_request HTTP/1.1");
    client.print("Host: ");
    client.println(host);
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(config_String.length());
    client.println(); // Empty line to end headers
    client.print(config_String);  // ✅ Send JSON body

    // Method response
    Serial.println("(post_cyclobot_config): Config sent");
  }
  else {
    Serial.println("(post_cyclobot_config): [ATENTION] server NOT responding");
  }
}

void ClientComm::post_cyclobot_diagnosis() {
  Serial.println("(post_cyclobot_diagnosis): running...");
  
  // Build json struct and convert to string
  selfDiagnosisDataPtr->selfDiagnosis_Json["cyclobot_id"] = cyclobotId; // uuid
  selfDiagnosisDataPtr->selfDiagnosis_Json["session_token"] = sessionToken; // uuid
  selfDiagnosisDataPtr->selfDiagnosis_Json["diagnosis_date_time"] = SelfDiagnosisDataPtr->diagnosisDateTime; // date and time
  selfDiagnosisDataPtr->selfDiagnosis_Json["wifi_connected"] = SelfDiagnosisDataPtr->wifiIsConnected; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["watering_system"] = SelfDiagnosisDataPtr->waterSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["river_system"] = SelfDiagnosisDataPtr->riverSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["wind_system"] = SelfDiagnosisDataPtr->windSystemOK; // int
  selfDiagnosisDataPtr->selfDiagnosis_Json["lighting_system"] = SelfDiagnosisDataPtr->lightingSystemOK; // int
  serializeJson(SelfDiagnosisDataPtr->selfDiagnosis_Json, SelfDiagnosisDataPtr->selfDiagnosis_String);  // convert JSON to String

  // Send HTTP request
  if (client.connected()) {
    // Client action
    client.println("POST /api/cyclobot/signature_request HTTP/1.1");
    client.print("Host: ");
    client.println(host);
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(signatureRequest_String.length());
    client.println(); // Empty line to end headers
    client.print(signatureRequest_String);  // ✅ Send JSON body

    // Method response
    Serial.println("(post_cyclobot_diagnostic): Request sent");
  }
  else {
    Serial.println("(post_cyclobot_diagnostic): [ATENTION] server NOT responding");
  }
}

void ClientComm::post_cyclobot_environment_state() {
  Serial.println("(post_cyclobot_environment_state): running...");
}

void ClientComm::get_cyclobot_config_update() {
  Serial.println("(post_cyclobot_environment_state): running...");
}

void ClientComm::get_cyclobot_config_rollback() {
  Serial.println("(post_cyclobot_environment_state): running...");
}

void ClientComm::ClientComm() {
  WiFiClient client;
}