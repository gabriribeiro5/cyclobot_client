#include "CheckMyHealth.h"
#include "ClientComm.h"
#include "SharedInstances.h"
#include <WiFi.h>

bool CheckMyHealth::wifi_shield_is_on() {
    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        SelfDiagnosisDataPtr->wifiIsConnected = 0;
    }
    SelfDiagnosisDataPtr->wifiIsConnected = 1;
}

void CheckMyHealth::check_wifi_firmware_version() {
  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
      Serial.println("(check_wifi_firmware_version): Please upgrade the firmware");
      SelfDiagnosisDataPtr->wifiFirmwareRequireUpdate = 1;
  }
}

void CheckMyHealth::check_client_communication() {
  ClientComm clientComm = ClientComm();
  clientCommPtr = &clientComm;
  clientCommPtr->trace_server();
}

void CheckMyHealth::clear_runtime_data() {
  Serial.println("(clear_runtime_data): running...");
  // TODO: clear ClientComm instance
}