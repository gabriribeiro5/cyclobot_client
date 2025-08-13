#pragma once
#include "../../../../core_states/simulation/strategy/habitat/pet_room/Door.h"
#include "../../../../core_states/simulation/strategy/habitat/pet_room/DoorThermo.h"
#include "../../../../core_states/simulation/strategy/habitat/pet_room/DoorThermoPlayer.h"
#include "../../../../core_states/simulation/strategy/habitat/pet_room/DoorThermoPlayerToy.h"

class PetRoomStrategies {
    public:
        PetRoomStrategies();

        Door *doorPtr;
        DoorThermo *doorThermoPtr;
        DoorThermoPlayer *doorThermoPlayerPtr;
        DoorThermoPlayerToy *doorThermoPlayerToyPtr;
};