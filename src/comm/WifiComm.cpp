// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class
#include "Arduino.h"
#include <WiFiEsp.h>
#include "../../include/comm/WifiComm.h"
#include "../../include/config/WifiParameters.h"
#include "../../include/Context.h"

void WifiComm::print_wifi_status() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("[WifiComm::print_wifi_status] WiFi not connected."));
    return;
  }
  
  // print the SSID of the network you're attached to:
  Serial.print("[WifiComm::print_wifi_status] SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("[WifiComm::print_wifi_status] IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("[WifiComm::print_wifi_status] Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(F(" dBm"));
}

void WifiComm::print_encryption_type(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
  case ENC_TYPE_NONE:
    Serial.println(F("[WifiComm::print_encryption_type] None"));
    break;
  case ENC_TYPE_WEP:
    Serial.println(F("[WifiComm::print_encryption_type] WEP"));
    break;
  // case ENC_TYPE_TKIP:
  //   Serial.println(F("[WifiComm::print_encryption_type] WPA"));
  //   break;
  // case ENC_TYPE_CCMP:
  //   Serial.println(F("[WifiComm::print_encryption_type] WPA2"));
  //   break;
  // case ENC_TYPE_AUTO:
  //   Serial.println(F("[WifiComm::print_encryption_type] Auto"));
  //   break;
  default:
    Serial.println(F("[WifiComm::print_encryption_type] Unknown"));
    break;
  }
}

void WifiComm::print_available_networks(WifiParameters *wifiParametersPtr) {
  for (int i = 0; i < wifiParametersPtr->networkSsidIndex; i++) {
    Serial.print("[WifiComm::print_available_networks] (");
    Serial.print(i);
    Serial.print(") ");
    Serial.println(WiFi.SSID(i));
    Serial.print("[WifiComm::print_available_networks] ");
    Serial.print("\tSignal: ");
    Serial.println(WiFi.RSSI(i));
    Serial.print("[WifiComm::print_available_networks] dBm\tEncryption: ");
    print_encryption_type(WiFi.encryptionType(i));
  }
}

void WifiComm::scan_wifi(WifiParameters *wifiParametersPtr) {
  Serial.println(F("[WifiComm::scan_wifi] Running..."));
  // Print WiFi MAC address:
  // printMacAddress();

  // scan for nearby networks:
  Serial.println(F("[WifiComm::scan_wifi] ** Scan Networks **"));
  while (wifiParametersPtr->scanCount < wifiParametersPtr->wifiMaxScanAttempt) {
    wifiParametersPtr->networkSsidIndex = WiFi.scanNetworks();
    if (wifiParametersPtr->networkSsidIndex == -1) {
        Serial.print("[WifiComm::scan_wifi] failed attempt -> ");
        Serial.print(wifiParametersPtr->scanCount);
        delay(wifiParametersPtr->waitTimePerScanAttempt);
        wifiParametersPtr->scanCount++;
    } else {
      break;
    }
  }

  print_available_networks(wifiParametersPtr);
}

void WifiComm::connect_wifi(WifiParameters *wifiParametersPtr) {
  Serial.println(F("[WifiComm::connect_wifi] Running..."));
  Serial.flush(); // Wait until all outgoing serial data has been transmitted
  
  // Initialize the Ethernet client library
  // with the IP address and port of the server
  // that you want to connect to (port 80 is default for HTTP):
  while (wifiParametersPtr->wifiStatus != WL_IDLE_STATUS) {
    Serial.println(F("[WifiComm::connect_wifi] Attempting to connect to SSID: "));
    Serial.flush(); // Wait until all outgoing serial data has been transmitted
    Serial.println(wifiParametersPtr->wifiSsid);
    
    // WPA/WPA2 connection
    wifiParametersPtr->connAttemptCount++;
    wifiParametersPtr->wifiStatus = WiFi.begin(wifiParametersPtr->wifiSsid, wifiParametersPtr->wifiSecret);

    // wait connection
    delay(wifiParametersPtr->waitTimePerConnectionAttempt);

    if (wifiParametersPtr->connAttemptCount >= wifiParametersPtr->maxConnectoinAttempt) {
      break;
    }
  }
}

void WifiComm::disconnect_wifi() {
  Serial.println(F("[WifiComm::disconnect_wifi] Running..."));
  WiFi.disconnect();
  Serial.println(F("[WifiComm::disconnect_wifi] done"));
}