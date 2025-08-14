#pragma once
#include "../../../../core_states/simulation/strategy/habitat/pet_room/PR_Door.h"
#include "../../../../core_states/simulation/strategy/habitat/pet_room/PR_DoorThermo.h"
#include "../../../../core_states/simulation/strategy/habitat/pet_room/PR_DoorThermoPlayer.h"
#include "../../../../core_states/simulation/strategy/habitat/pet_room/PR_DoorThermoPlayerToy.h"

class PetRoomStrategies {
    public:
        PetRoomStrategies();

        PR_Door *doorPtr;
        PR_DoorThermo *doorThermoPtr;
        PR_DoorThermoPlayer *doorThermoPlayerPtr;
        PR_DoorThermoPlayerToy *doorThermoPlayerToyPtr;
};