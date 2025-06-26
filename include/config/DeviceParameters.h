#pragma once

class DeviceParameters {
    public:
        uuid cyclobotId = new uuid;
        uuid cyclobotToken = new uuid;
        bool firstAwakening = true;       // Must be true when the product is handed to customer. Resolved in InitialState.
        int sleepLenght = 60000 * 60;    // 1h
}