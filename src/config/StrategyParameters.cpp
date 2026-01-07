#include "../../include/config/StrategyParameters.h"
#include "../include/strategy/BaseStrategy.h"
#include "../include/config/StreamableData.h"

StrategyParameters::StrategyParameters()
: standBy(0),
  eventStart(),
  eventEnd()
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}