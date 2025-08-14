#include "../../../../../include/shared/simmulation_strategies/habitat_strategies/pet_room/PetRoomStrategies.h"

PetRoomStrategies::PetRoomStrategies() {
    doorPtr = new PR_Door();
    doorThermoPtr = new PR_DoorThermo();
    doorThermoPlayerPtr = new PR_DoorThermoPlayer();
    doorThermoPlayerToyPtr = new PR_DoorThermoPlayerToy();
};