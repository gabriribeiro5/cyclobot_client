// REFERÊNCIAS:
//  https://docs.arduino.cc/libraries/wifi/#Wifi%20Class
#include "Arduino.h"
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include "../../include/comm/WifiComm.h"
#include "../../include/comm/VisualComm.h"
#include "../../include/config/WifiParameters.h"
#include "../../include/Context.h"

void WifiComm::print_wifi_status(VisualComm *visualCommPtr) {
  if (WiFi.status() != WL_CONNECTED) {
    visualCommPtr->print_line(F("    [WifiComm::print_wifi_status] WiFi not connected."));
    return;
  }
  
  // print the SSID of the network you're attached to:
  visualCommPtr->print("[WifiComm::print_wifi_status] SSID: ");
  visualCommPtr->print_line(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  visualCommPtr->print("[WifiComm::print_wifi_status] IP Address: ");
  visualCommPtr->print_line(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  visualCommPtr->print("[WifiComm::print_wifi_status] Signal strength (RSSI):");
  visualCommPtr->print(rssi);
  visualCommPtr->print_line(F(" dBm"));
}

void WifiComm::print_encryption_type(int thisType, VisualComm *visualCommPtr) {
  // read the encryption type and print out the name:
  switch (thisType) {
  case ENC_TYPE_NONE:
    visualCommPtr->print_line(F("    [WifiComm::print_encryption_type] None"));
    break;
  case ENC_TYPE_WEP:
    visualCommPtr->print_line(F("    [WifiComm::print_encryption_type] WEP"));
    break;
  // case ENC_TYPE_TKIP:
  //   visualCommPtr->print_line(F("    [WifiComm::print_encryption_type] WPA"));
  //   break;
  // case ENC_TYPE_CCMP:
  //   visualCommPtr->print_line(F("    [WifiComm::print_encryption_type] WPA2"));
  //   break;
  // case ENC_TYPE_AUTO:
  //   visualCommPtr->print_line(F("    [WifiComm::print_encryption_type] Auto"));
  //   break;
  default:
    visualCommPtr->print_line(F("    [WifiComm::print_encryption_type] Unknown"));
    break;
  }
}

void WifiComm::print_available_networks(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
  for (int i = 0; i < wifiParametersPtr->networkSsidIndex; i++) {
    visualCommPtr->print("[WifiComm::print_available_networks] (");
    visualCommPtr->print(i);
    visualCommPtr->print(") ");
    visualCommPtr->print_line(WiFi.SSID(i));
    visualCommPtr->print("[WifiComm::print_available_networks] ");
    visualCommPtr->print("\tSignal: ");
    visualCommPtr->print_line(WiFi.RSSI(i));
    visualCommPtr->print("[WifiComm::print_available_networks] dBm\tEncryption: ");
    print_encryption_type(WiFi.encryptionType(i), visualCommPtr);
  }
}

void WifiComm::scan_wifi(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [WifiComm::scan_wifi] Running..."));
  // Print WiFi MAC address:
  // printMacAddress();

  // scan for nearby networks:
  visualCommPtr->print_line(F("    [WifiComm::scan_wifi] ** Scan Networks **"));
  while (wifiParametersPtr->scanCount < wifiParametersPtr->wifiMaxScanAttempt) {
    wifiParametersPtr->networkSsidIndex = WiFi.scanNetworks();
    if (wifiParametersPtr->networkSsidIndex == -1) {
        visualCommPtr->print("[WifiComm::scan_wifi] failed attempt -> ");
        visualCommPtr->print(wifiParametersPtr->scanCount);
        delay(wifiParametersPtr->waitTimePerScanAttempt);
        wifiParametersPtr->scanCount++;
    } else {
      break;
    }
  }

  print_available_networks(wifiParametersPtr, visualCommPtr);
}

void WifiComm::connect_wifi(WifiParameters *wifiParametersPtr, VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [WifiComm::connect_wifi] Running..."));
  
  // Initialize the Ethernet client library
  // with the IP address and port of the server
  // that you want to connect to (port 80 is default for HTTP):
  while (wifiParametersPtr->wifiStatus != WL_IDLE_STATUS && wifiParametersPtr->connAttemptCount < wifiParametersPtr->maxConnectionAttempt) {
    visualCommPtr->print_line(F("    [WifiComm::connect_wifi] Connecting to SSID: "));
    visualCommPtr->print(F("[WifiComm::connect_wifi] Attempt: "));
    visualCommPtr->print(wifiParametersPtr->connAttemptCount);
    visualCommPtr->print(F(" of "));
    visualCommPtr->print_line(wifiParametersPtr->maxConnectionAttempt);
    visualCommPtr->print_line(wifiParametersPtr->wifiSsid);

    // WPA/WPA2 connection
    wifiParametersPtr->connAttemptCount++;
    wifiParametersPtr->wifiStatus = WiFi.begin(wifiParametersPtr->wifiSsid, wifiParametersPtr->wifiSecret);

    // wait connection
    delay(wifiParametersPtr->waitTimePerConnectionAttempt);
  }
}

void WifiComm::disconnect_wifi(VisualComm *visualCommPtr) {
  visualCommPtr->print_line(F("    [WifiComm::disconnect_wifi] Running..."));
  WiFi.disconnect();
  visualCommPtr->print_line(F("    [WifiComm::disconnect_wifi] -- done --"));
}