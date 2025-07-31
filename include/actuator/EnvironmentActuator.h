#pragma once

class EnvironmentActuator {
    public:
        void water_system_on();
        void water_system_off();
        
        void light_system_on();
        void light_system_off();
        
        void fan_system_on();
        void fan_system_off();
        
        void heat_system_on();
        void heat_system_off();

        void trim_system_on();
        void trim_system_off();
};