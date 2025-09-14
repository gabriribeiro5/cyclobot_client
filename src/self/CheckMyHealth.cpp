#include <Arduino.h>
#include <WiFiEsp.h>
#include "../../include/self/CheckMyHealth.h"
#include "../../include/comm/ClientComm.h"
#include "../../include/comm/WifiComm.h"
#include "../../include/config/WifiParameters.h"
#include "../../include/data/SelfDiagnosisData.h"

bool CheckMyHealth::wifi_shield_is_on(WifiParameters *wifiParametersPtr) {
    // check for the presence of the shield:
    Serial.println(F("[CheckMyHealth::wifi_shield_is_on]..."));
    if (WiFi.status() == WL_NO_SHIELD) {
      Serial.println(F("[CheckMyHealth::wifi_shield_is_on] WiFi shield not present"));
      wifiParametersPtr->wifiShieldIsOn = 0;
      return false;
    }
    wifiParametersPtr->wifiShieldIsOn = 1;
    Serial.println(F("[CheckMyHealth::wifi_shield_is_on] WiFi shield is ON"));
    return true;
  }
  
  void CheckMyHealth::check_wifi_firmware_version(WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr) {
    char *fv = WiFi.firmwareVersion();
    if (fv != wifiParametersPtr->wifiFirmwareLatestVersion) {
      Serial.println(F("[CheckMyHealth::check_wifi_firmware_version] Please upgrade the firmware"));
      selfDiagnosisDataPtr->wifiFirmwareRequireUpdate = 1;
    }
  }

void CheckMyHealth::check_wifi_networks(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr) {
  wifiCommPtr->scan_wifi(wifiParametersPtr);

  // update selfDiagnosisData
  if (wifiParametersPtr->networkSsidIndex > -1) {
    selfDiagnosisDataPtr->wifiNetworkAvailable = 1; // 1 = true
    Serial.print("[CheckMyHealth::check_wifi_networks] number of available networks: ");
    Serial.print(wifiParametersPtr->networkSsidIndex);
    Serial.println(F("[CheckMyHealth::check_wifi_networks] *** AVAILABLE NETWORKS ***"));
    wifiCommPtr->scan_wifi(wifiParametersPtr);
  } else {
    Serial.println(F("[[CheckMyHealth::check_wifi_networks] Couldn't find network"));
    selfDiagnosisDataPtr->wifiNetworkAvailable = 0; // 1 = true
  }
}

void CheckMyHealth::check_wifi_connection(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr) {
  wifiCommPtr->connect_wifi(wifiParametersPtr);

  // update selfDiagnosisData
  if (wifiParametersPtr->wifiStatus == WL_IDLE_STATUS) {
      selfDiagnosisDataPtr->wifiIsConnected = 0;
  }
  if (wifiParametersPtr->wifiStatus == WL_CONNECTED) {
      selfDiagnosisDataPtr->wifiIsConnected = 1;
  }
}

void CheckMyHealth::check_client_communication(ClientComm *clientCommPtr,
                                               WifiParameters *wifiParametersPtr,
                                               ClientParameters *clientParametersPtr,
                                               SelfDiagnosisData *selfDiagnosisDataPtr) {
  clientCommPtr->trace_server(clientParametersPtr, wifiParametersPtr);

  // update selfDiagnosisData
  if (clientParametersPtr->serverIsUp) {
    selfDiagnosisDataPtr->httpCommunicationConfirmed = 1;
  }
}

void CheckMyHealth::check_watering_system(SelfDiagnosisData *selfDiagnosisDataPtr) {
  Serial.println(F("[CheckMyHealth::check_watering_system] Running..."));
  Serial.flush();
  selfDiagnosisDataPtr->wateringSystemOK = 1;
}

void CheckMyHealth::check_river_system(SelfDiagnosisData *selfDiagnosisDataPtr) {
  Serial.println(F("[CheckMyHealth::check_river_system] Running..."));
  Serial.flush();
  selfDiagnosisDataPtr->riverSystemOK = 1;
}

void CheckMyHealth::check_wind_system(SelfDiagnosisData *selfDiagnosisDataPtr) {
  Serial.println(F("[CheckMyHealth::check_wind_system] Running..."));
  Serial.flush();
  selfDiagnosisDataPtr->windSystemOK = 1;
}

void CheckMyHealth::check_lighting_system(SelfDiagnosisData *selfDiagnosisDataPtr) {
  Serial.println(F("[CheckMyHealth::check_lighting_system] Running..."));
  Serial.flush();
  selfDiagnosisDataPtr->lightingSystemOK = 1;
}

void CheckMyHealth::check_components_list(SelfDiagnosisData *selfDiagnosisDataPtr) {
  Serial.println(F("[CheckMyHealth::check_components_list] Running..."));
  Serial.flush();
  selfDiagnosisDataPtr->peripheralComponentsOK = 1;
}

void CheckMyHealth::clear_runtime_data() {
  Serial.println(F("[CheckMyHealth::clear_runtime_data] running..."));
  // TODO: clear ClientComm instance
}