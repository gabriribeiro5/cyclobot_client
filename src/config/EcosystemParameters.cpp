#include "../../include/config/EcosystemParameters.h"

EcosystemParameters::EcosystemParameters()
: soilIsWet(0),
  soilMoistureLimit(500),
  currentTemperature(20),
  minTemperatureExpected(18),
  maxTemperatureExpected(22),
  initialWateringTimeLimit(2000),
  growthRate(0),
  decreaseRate(0),
  wateringTimeLimit(3000),
  climate(1),
  sunLightAvailable(1),
  standBy(0),
  timeBufferMicroSec(1800000000)
{
    // The upward initialization handles constants and non-constants.
    // No need to assign variables again in the body!
}