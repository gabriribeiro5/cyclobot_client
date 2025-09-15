#pragma once
#include <Arduino.h>

class VisualComm {
    public:
        // Serial Terminal
        template<typename T>
        void print_line(T printable);
        
        template<typename T>
        void print(T printable);
        
        void print_terminal_logo();
        
        void print_free_memory(char *currentMethodPtr);

        // Led Screen
        void show_sentence(char sentence);

        // Uno Board
        void single_led(int duration);
};

template<typename T>
void VisualComm::print_line(T p) {
    Serial.println(p);
    Serial.flush();
}

template<typename T>
void VisualComm::print(T p) {
    Serial.print(p);
    Serial.flush();
}