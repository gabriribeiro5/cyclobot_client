#pragma once
#include "Arduino.h"
#include "../ParameterInstances.h"
#include "../data/ConfigData.h"

class VisualComm {
    public:
        static const uint16_t EEPROM_TOTAL_SIZE = 4096;  // ATmega2560 EEPROM size

        // Serial Terminal
        template<typename T>
        void print_line(T printable);
        
        template<typename T>
        void print(T printable);
        
        void print_terminal_logo();
        void print_eeprom_usage(char *currentMethodPtr);
        void print_eeprom_hex_dump(char *currentMethodPtr, uint16_t start_addr, uint16_t length);
        void print_free_memory(char *currentMethodPtr);
        void print_state_machine_parameters(ParameterInstances *paramPtr);
        void print_strategy_parameters(ConfigData *configData);

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