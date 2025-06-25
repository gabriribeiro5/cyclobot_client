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
  signatureRequest_Json["cyclobot_id"] = cyclobot_id; // get uuid
  signatureRequest_Json["cyclobot_token"] = cyclobot_token; // get other uuid
  serializeJson(signatureRequest_Json, signatureRequest_String);  // convert JSON to String

  // Send HTTP request
  if (client.connected()) {
    // Client action
    client.println("POST /api/cyclobot/signature_request HTTP/1.1");
    client.println("Host: example.com");
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
  loginParameters_Json["cyclobot_id"] = cyclobot_id;          // TODO: Replace with actual ID
  loginParameters_Json["cyclobot_token"] = cyclobot_token;   // TODO: Replace with actual token

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
  unsigned long timout_reference = millis(); // do NOT move this to `.h` file
  while (!client.available()) {
    if (millis() - timout_reference > response_timeout_limit) {
      Serial.println("(get_cyclobot_session_token): [ERROR] Timeout waiting for response");
      client.stop();
      return "";
    }
  }

  // Read and store entire response
  String response = "";
  while (client.available()) {
    char c = client.read();
    response += c;
  }

  // Debug raw response (optional)
  Serial.println("(get_cyclobot_session_token): Raw response:");
  Serial.println(response);

  // Find start of JSON (skip HTTP headers)
  int jsonStart = response.indexOf('{');
  if (jsonStart == -1) {
    Serial.println("(get_cyclobot_session_token): [ERROR] No JSON found in response");
    return "";
  }

  String jsonPart = response.substring(jsonStart);

  // Parse JSON
  StaticJsonDocument<512> responseJson;
  DeserializationError error = deserializeJson(responseJson, jsonPart);
  if (error) {
    Serial.print("(get_cyclobot_session_token): [ERROR] Failed to parse JSON: ");
    Serial.println(error.c_str());
    return "";
  }

  // Extract token
  if (responseJson.containsKey("session_token")) {
    session_token = responseJson["session_token"].as<String>();
    Serial.println("(get_cyclobot_session_token): Token received: " + session_token);
  } else {
    Serial.println("(get_cyclobot_session_token): [ERROR] session_token not found in JSON");
    return "";
  }
}


void ClientComm::post_cyclobot_diagnosis() {
  Serial.println("(post_cyclobot_diagnosis): running...");
  
  // Build json struct and convert to string
  SelfDiagnosisDataPtr->selfDiagnosis_Json["cyclobot_id"] = cyclobot_id; // uuid
  SelfDiagnosisDataPtr->selfDiagnosis_Json["session_token"] = session_token; // uuid
  SelfDiagnosisDataPtr->selfDiagnosis_Json["diagnostic_date_time"] = "diagnostic_date_time"; // date and time
  SelfDiagnosisDataPtr->selfDiagnosis_Json["wifi_connected"] = SelfDiagnosisDataPtr->wifiIsConnected; // int
  SelfDiagnosisDataPtr->selfDiagnosis_Json["watering_system"] = SelfDiagnosisDataPtr->waterSystemOK; // int
  SelfDiagnosisDataPtr->selfDiagnosis_Json["river_system"] = SelfDiagnosisDataPtr->riverSystemOK; // int
  SelfDiagnosisDataPtr->selfDiagnosis_Json["wind_system"] = SelfDiagnosisDataPtr->windSystemOK; // int
  SelfDiagnosisDataPtr->selfDiagnosis_Json["lighting_system"] = SelfDiagnosisDataPtr->lightingSystemOK; // int
  serializeJson(SelfDiagnosisDataPtr->selfDiagnosis_Json, SelfDiagnosisDataPtr->selfDiagnosis_String);  // convert JSON to String

  // Send HTTP request
  if (client.connected()) {
    // Client action
    client.println("POST /api/cyclobot/signature_request HTTP/1.1");
    client.println("Host: example.com");
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

void ClientComm::post_cyclobot_config() {
  Serial.println("(post_cyclobot_config): running...");
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