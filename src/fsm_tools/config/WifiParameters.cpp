#include "../../../include/fsm_tools/config/WifiParameters.h"
#include "../../../include/fsm_tools/config/BaseMapping.h"
#include <SoftwareSerial.h>

WifiParameters::WifiParameters()
: wifiSsid("ROCK JUNIOR"),
  wifiSecret("13051305RJ"),
  wifiFirmwareLatestVersion("1.1.0"),
  networkKeyIndex(0),

  waitTimePerConnectionAttemptInMillis(5000),
  maxConnectionAttempt(3),

  waitTimePerScanAttempt(3000),
  wifiMaxScanAttempt(2),

  networkSsidIndex(0),
  connAttemptCount(0),
  scanCount(0),
  wifiStatus(WL_IDLE_STATUS),
  wifiShieldIsOn(0),
  wifiStream(nullptr)
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}
WifiParameters::~WifiParameters() {
    // Nothing to delete since there are no dynamic allocations.
}