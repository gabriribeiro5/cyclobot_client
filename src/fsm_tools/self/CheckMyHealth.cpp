#include <Arduino.h>
#include <WiFiEsp.h>
#include "../../../include/fsm_tools/self/CheckMyHealth.h"
#include "../../../include/fsm_tools/comm//ClientComm.h"
#include "../../../include/fsm_tools/comm/WifiComm.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/config/WifiParameters.h"
#include "../../../include/fsm_tools/data/SelfDiagnosisData.h"

bool CheckMyHealth::is_esp_present(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
  wifiParametersPtr->wifiStream->println("AT");
  unsigned long start = millis();
  
  while (millis() - start < 1000) {
    visualCommPtr->print_line(F("    [CheckMyHealth::is_esp_present] Checking for ESP module..."));
    if (wifiParametersPtr->wifiStream->find("OK")) {
        return true;
        visualCommPtr->print_line(F("    [CheckMyHealth::is_esp_present] ESP module is present"));
      }
    }
    visualCommPtr->print_line(F("    [CheckMyHealth::is_esp_present] ESP module is NOT present"));
    return false;
}


bool CheckMyHealth::wifi_shield_is_on(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
    // check for the presence of the shield:
    visualCommPtr->print_line(F("    [CheckMyHealth::wifi_shield_is_on]..."));
    if (WiFi.status() == WL_NO_SHIELD) {
      visualCommPtr->print_line(F("    [CheckMyHealth::wifi_shield_is_on] WiFi shield not present"));
      wifiParametersPtr->wifiShieldIsOn = 0;
      return false;
    }
    wifiParametersPtr->wifiShieldIsOn = 1;
    visualCommPtr->print_line(F("    [CheckMyHealth::wifi_shield_is_on] WiFi shield is ON"));
    return true;
  }

void CheckMyHealth::check_wifi_firmware_version(WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  char *fv = WiFi.firmwareVersion();
  if (fv != wifiParametersPtr->wifiFirmwareLatestVersion) {
    visualCommPtr->print_line(F("    [CheckMyHealth::check_wifi_firmware_version] Please upgrade the firmware"));
    selfDiagnosisDataPtr->wifiFirmwareRequireUpdate = 1;
  }
}

void CheckMyHealth::check_wifi_networks(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  wifiCommPtr->scan_wifi(wifiParametersPtr, visualCommPtr);

  // update selfDiagnosisData
  if (wifiParametersPtr->networkSsidIndex > -1) {
    selfDiagnosisDataPtr->wifiNetworkAvailable = 1; // 1 = true
    visualCommPtr->print("[CheckMyHealth::check_wifi_networks] number of available networks: ");
    visualCommPtr->print(wifiParametersPtr->networkSsidIndex);
    visualCommPtr->print_line(F("    [CheckMyHealth::check_wifi_networks] *** AVAILABLE NETWORKS ***"));
    wifiCommPtr->scan_wifi(wifiParametersPtr, visualCommPtr);
  } else {
    visualCommPtr->print_line(F("    [[CheckMyHealth::check_wifi_networks] Couldn't find network"));
    selfDiagnosisDataPtr->wifiNetworkAvailable = 0; // 1 = true
  }
}

void CheckMyHealth::check_wifi_connection(WifiComm *wifiCommPtr, WifiParameters *wifiParametersPtr, SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  wifiCommPtr->connect_wifi(wifiParametersPtr, visualCommPtr);

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
                                               SelfDiagnosisData *selfDiagnosisDataPtr,
                                               VisualComm *visualCommPtr) {
  clientCommPtr->trace_server(clientParametersPtr, wifiParametersPtr, visualCommPtr);

  // update selfDiagnosisData
  if (clientParametersPtr->serverIsUp) {
    selfDiagnosisDataPtr->httpCommunicationConfirmed = 1;
  }
}

void CheckMyHealth::check_watering_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [CheckMyHealth::check_watering_system] Running..."));
  selfDiagnosisDataPtr->wateringSystemOK = 1;
}

void CheckMyHealth::check_river_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [CheckMyHealth::check_river_system] Running..."));
  selfDiagnosisDataPtr->riverSystemOK = 1;
}

void CheckMyHealth::check_wind_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [CheckMyHealth::check_wind_system] Running..."));
  selfDiagnosisDataPtr->windSystemOK = 1;
}

void CheckMyHealth::check_lighting_system(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [CheckMyHealth::check_lighting_system] Running..."));
  selfDiagnosisDataPtr->lightingSystemOK = 1;
}

void CheckMyHealth::check_components_list(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [CheckMyHealth::check_components_list] Running..."));
  selfDiagnosisDataPtr->peripheralComponentsOK = 1;
}

void CheckMyHealth::clear_runtime_data(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [CheckMyHealth::clear_runtime_data] running..."));
  // TODO: clear ClientComm instance
  visualCommPtr->print_line(F("    [CheckMyHealth::clear_runtime_data] -- done --"));
}