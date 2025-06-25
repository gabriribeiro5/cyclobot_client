// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class

#include "WifiComm.h"
#include "WifiParameters.h"
#include "Arduino.h"
#include <WiFi.h>

void WifiComm::print_wifi_status() {
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
  Serial.println(" dBm");
}

void WifiComm::print_encryption_type(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
  }
}

void WifiComm::connect_wifi() {
  Serial.println("[GetWifiConnection] Running...");
  
  // Initialize the Ethernet client library
  // with the IP address and port of the server
  // that you want to connect to (port 80 is default for HTTP):
  while (wifiStatus != WL_IDLE_STATUS) {
      Serial.println("[GetWifiConnection] Attempting to connect to SSID: ");
      Serial.println(ssid);

      // WPA/WPA2 connection
      status = WiFi.begin(ssid, pass);

      // wait connection
      delay(waitTimePerConnectionAttempt);
  }
  Serial.println("Connected to wifi");
  print_wifi_status();
  SelfDiagnosisDataPtr->wifiIsConnected = 1;
}

void WifiComm::scan_wifi() {
  Serial.println("[scan_wifi]: Running...");
  // Print WiFi MAC address:
  printMacAddress();

  // scan for nearby networks:
  Serial.println("[scan_wifi]: ** Scan Networks **");
  while (scanCount < wifiMaxScanAttempt) {
    networkSsidNum = WiFi.scanNetworks();
    if (networkSsidNum == -1) {
        Serial.println("[scan_wifi]: Couldn't get a wifi connection");
        delay(waitTimePerScanAttempt);
        scanCount++;
    }
    break;
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(networkSsidNum);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < networkSsidNum; thisNet++) {
      Serial.print(thisNet);
      Serial.print(") ");
      Serial.print(WiFi.SSID(thisNet));
      Serial.print("\tSignal: ");
      Serial.print(WiFi.RSSI(thisNet));
      Serial.print(" dBm");
      Serial.print("\tEncryption: ");
      print_encryption_type(WiFi.encryptionType(thisNet));
  }
}