#include "CheckMyHealth.h"
#include "ClientComm.h"
#include "WifiComm.h"
#include "SharedInstances.h"
#include <WiFi.h>

bool CheckMyHealth::wifi_shield_is_on() {
    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        SelfDiagnosisDataPtr->wifiShieldIsOn = 0;
        return false;
      }
      SelfDiagnosisDataPtr->wifiShieldIsOn = 1;
      return true;
}

void CheckMyHealth::check_wifi_firmware_version() {
  String fv = WiFi.firmwareVersion();
  if (fv != wifiParametersPtr->wifiFirmwareLatestVersion) {
      Serial.println("(check_wifi_firmware_version): Please upgrade the firmware");
      SelfDiagnosisDataPtr->wifiFirmwareRequireUpdate = 1;
  }
}

void CheckMyHealth::check_wifi_networks() {
  wifiComm = WifiComm();
  wifiCommPtr = &wifiComm;
  wifiCommPtr->scan_wifi();

  // update selfDiagnosisData
  if (wifiParametersPtr->networkSsidIndex > -1) {
    selfDiagnosisDataPtr->wifiNetworkAvailable = 1; // 1 = true
    Serial.print("(check_wifi_networks): number of available networks: ");
    Serial.print(networkSsidIndex);
    Serial.println("(check_wifi_networks): *** AVAILABLE NETWORKS ***");
    WifiCommPtr->print_available_networks();
  } else {
    Serial.println("(check_wifi_networks): Couldn't find network");
    selfDiagnosisDataPtr->wifiNetworkAvailable = 0; // 1 = true
  }
}

void CheckMyHealth::check_wifi_connection() {
  wifiCommPtr = &wifiComm;
  wifiCommPtr->connect_wifi();

  // update selfDiagnosisData
  if (wifiStatus == WL_IDLE_STATUS) {
      selfDiagnosisDataPtr->wifiIsConnected = 0;
  }
  if (wifiStatus == WL_CONNECTED) {
      selfDiagnosisDataPtr->wifiIsConnected = 1;
  }
}

void CheckMyHealth::check_client_communication() {
  clientComm = ClientComm();
  clientCommPtr = &clientComm;
  clientCommPtr->trace_server();

  // update selfDiagnosisData
  if (clientParametersPtr->serverIsUp) {
    selfDiagnosisDataPtr->httpCommunicationConfirmed = 1;
  }
}

void CheckMyHealth::clear_runtime_data() {
  Serial.println("(clear_runtime_data): running...");
  // TODO: clear ClientComm instance
}