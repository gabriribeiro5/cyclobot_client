#pragma once
#include <Definitions.h>

class VisualComm {
    public:
        // Led Screen
        void show_sentence(char sentence);

        // Uno Board
        void single_led(int duration);
}