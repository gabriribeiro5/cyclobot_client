#pragma once

class EnvironmentActuator {
    public:
        void WaterSystemOn();
        void WaterSystemOff();
        
        void LightSystemOn();
        void LightSystemOff();
        
        void FanSystemOn();
        void FanSystemOff();
        
        void HeatSystemOn();
        void HeatSystemOff();

        void TrimSystemOn();
        void TrimSystemOff();
}