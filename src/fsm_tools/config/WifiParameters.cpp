#include "../../../include/fsm_tools/config/WifiParameters.h"

WifiParameters::WifiParameters()
: wifiSsid("yourNetwork"),
  wifiSecret("secretPassword"),
  wifiFirmwareLatestVersion("1.1.0"),
  networkKeyIndex(0),

  waitTimePerConnectionAttempt(5000),
  maxConnectionAttempt(1),

  waitTimePerScanAttempt(3000),
  wifiMaxScanAttempt(2),

  networkSsidIndex(0),
  connAttemptCount(0),
  scanCount(0),
  wifiStatus(WL_IDLE_STATUS),
  wifiShieldIsOn(0)
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}
WifiParameters::~WifiParameters() {
    // Nothing to delete since there are no dynamic allocations.
}