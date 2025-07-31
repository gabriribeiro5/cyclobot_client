// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class
#include "Arduino.h"
#include <WiFiEsp.h>
#include "../../include/comm/WifiComm.h"
#include "../../include/config/WifiParameters.h"
#include "../../include/Context.h"

void WifiComm::print_wifi_status() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("WiFi not connected."));
    return;
  }
  
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(F(" dBm"));
}

void WifiComm::print_encryption_type(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
  case ENC_TYPE_NONE:
    Serial.println(F("None"));
    break;
  case ENC_TYPE_WEP:
    Serial.println(F("WEP"));
    break;
  // case ENC_TYPE_TKIP:
  //   Serial.println(F("WPA"));
  //   break;
  // case ENC_TYPE_CCMP:
  //   Serial.println(F("WPA2"));
  //   break;
  // case ENC_TYPE_AUTO:
  //   Serial.println(F("Auto"));
  //   break;
  default:
    Serial.println(F("Unknown"));
    break;
  }
}

void WifiComm::print_available_networks(WifiParameters *wifiParametersPtr) {
  for (int i = 0; i < wifiParametersPtr->networkSsidIndex; i++) {
    Serial.print(i);
    Serial.print(") ");
    Serial.print(WiFi.SSID(i));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(i));
    Serial.print(" dBm\tEncryption: ");
    print_encryption_type(WiFi.encryptionType(i));
  }
}

void WifiComm::scan_wifi(WifiParameters *wifiParametersPtr) {
  Serial.println(F("(scan_wifi): Running..."));
  // Print WiFi MAC address:
  // printMacAddress();

  // scan for nearby networks:
  Serial.println(F("(scan_wifi): ** Scan Networks **"));
  while (wifiParametersPtr->scanCount < wifiParametersPtr->wifiMaxScanAttempt) {
    wifiParametersPtr->networkSsidIndex = WiFi.scanNetworks();
    if (wifiParametersPtr->networkSsidIndex == -1) {
        Serial.print("(scan_wifi): failed attempt -> ");
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
  Serial.println(F("(connect_wifi): Running..."));
  
  // Initialize the Ethernet client library
  // with the IP address and port of the server
  // that you want to connect to (port 80 is default for HTTP):
  while (wifiParametersPtr->wifiStatus != WL_IDLE_STATUS) {
    Serial.println(F("(connect_wifi): Attempting to connect to SSID: "));
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
  Serial.println(F("(disconnect_wifi): Running..."));
  WiFi.disconnect();
  Serial.println(F("(disconnect_wifi): done"));
}