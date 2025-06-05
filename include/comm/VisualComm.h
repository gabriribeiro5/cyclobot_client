#pragma once
#include <Definitions.h>

class VisualComm {
    public:
        // Led Screen
        void ShowSentence(char sentence);

        // Uno Board
        void SingleLed(int duration);
}