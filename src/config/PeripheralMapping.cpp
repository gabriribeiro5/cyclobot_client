#include "../../include/config/WifiMapping.h"

WifiMapping::WifiMapping()
: wifiEspRX(0),
  wifiEspTX(1)
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}