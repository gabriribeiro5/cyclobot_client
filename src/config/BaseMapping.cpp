#include "../../include/config/BaseMapping.h"

BaseMapping::BaseMapping()
: wifiEspRX(0),
  wifiEspTX(1)
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}