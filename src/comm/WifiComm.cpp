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
    Serial.flush();
    return;
  }
  
  // print the SSID of the network you're attached to:
  Serial.print("[WifiComm::print_wifi_status] SSID: ");
  Serial.flush();
  Serial.println(WiFi.SSID());
  Serial.flush();

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("[WifiComm::print_wifi_status] IP Address: ");
  Serial.flush();
  Serial.println(ip);
  Serial.flush();

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("[WifiComm::print_wifi_status] Signal strength (RSSI):");
  Serial.flush();
  Serial.print(rssi);
  Serial.flush();
  Serial.println(F(" dBm"));
  Serial.flush();
}

void WifiComm::print_encryption_type(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
  case ENC_TYPE_NONE:
    Serial.println(F("[WifiComm::print_encryption_type] None"));
    Serial.flush();
    break;
  case ENC_TYPE_WEP:
    Serial.println(F("[WifiComm::print_encryption_type] WEP"));
    Serial.flush();
    break;
  // case ENC_TYPE_TKIP:
  //   Serial.println(F("[WifiComm::print_encryption_type] WPA"));
  //   Serial.flush();
  //   break;
  // case ENC_TYPE_CCMP:
  //   Serial.println(F("[WifiComm::print_encryption_type] WPA2"));
  //   Serial.flush();
  //   break;
  // case ENC_TYPE_AUTO:
  //   Serial.println(F("[WifiComm::print_encryption_type] Auto"));
  //   Serial.flush();
  //   break;
  default:
    Serial.println(F("[WifiComm::print_encryption_type] Unknown"));
    Serial.flush();
    break;
  }
}

void WifiComm::print_available_networks(WifiParameters *wifiParametersPtr) {
  for (int i = 0; i < wifiParametersPtr->networkSsidIndex; i++) {
    Serial.print("[WifiComm::print_available_networks] (");
    Serial.flush();
    Serial.print(i);
    Serial.flush();
    Serial.print(") ");
    Serial.flush();
    Serial.println(WiFi.SSID(i));
    Serial.flush();
    Serial.print("[WifiComm::print_available_networks] ");
    Serial.flush();
    Serial.print("\tSignal: ");
    Serial.flush();
    Serial.println(WiFi.RSSI(i));
    Serial.flush();
    Serial.print("[WifiComm::print_available_networks] dBm\tEncryption: ");
    Serial.flush();
    print_encryption_type(WiFi.encryptionType(i));
  }
}

void WifiComm::scan_wifi(WifiParameters *wifiParametersPtr) {
  Serial.println(F("[WifiComm::scan_wifi] Running..."));
  Serial.flush();
  // Print WiFi MAC address:
  // printMacAddress();

  // scan for nearby networks:
  Serial.println(F("[WifiComm::scan_wifi] ** Scan Networks **"));
  Serial.flush();
  while (wifiParametersPtr->scanCount < wifiParametersPtr->wifiMaxScanAttempt) {
    wifiParametersPtr->networkSsidIndex = WiFi.scanNetworks();
    if (wifiParametersPtr->networkSsidIndex == -1) {
        Serial.print("[WifiComm::scan_wifi] failed attempt -> ");
        Serial.flush();
        Serial.print(wifiParametersPtr->scanCount);
        Serial.flush();
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
  Serial.flush();
  
  // Initialize the Ethernet client library
  // with the IP address and port of the server
  // that you want to connect to (port 80 is default for HTTP):
  while (wifiParametersPtr->wifiStatus != WL_IDLE_STATUS) {
    Serial.println(F("[WifiComm::connect_wifi] Attempting to connect to SSID: "));
    Serial.flush();
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
  Serial.flush();
  WiFi.disconnect();
  Serial.println(F("[WifiComm::disconnect_wifi] done"));
  Serial.flush();
}