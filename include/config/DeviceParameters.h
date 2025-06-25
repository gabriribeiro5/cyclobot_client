#pragma once

class DeviceParameters {
    public:
        uuid cyclobot_id = new uuid;
        uuid cyclobot_token = new uuid;
        bool firstAwakening = true; // Must be true when the product is handed to customer. Resolved in InitialState.
        bool *firstAwakeningPtr = &firstAwakening; // some methods require pointers
        int sleep_lenght = 60000 * 60; // 1h
}