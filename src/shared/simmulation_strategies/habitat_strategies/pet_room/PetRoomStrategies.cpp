#include "../../../../../include/shared/simmulation_strategies/habitat_strategies/pet_room/PetRoomStrategies.h"

PetRoomStrategies::PetRoomStrategies() {
    doorPtr = new Door();
    doorThermoPtr = new DoorThermo();
    doorThermoPlayerPtr = new DoorThermoPlayer();
    doorThermoPlayerToyPtr = new DoorThermoPlayerToy();
};