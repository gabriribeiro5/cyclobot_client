#pragma once
#include "../../BaseStrategy.h"
#include "../../../../../config/EcosystemParameters.h"
#include "../../../../../config/DeviceParameters.h"
#include "../../../../../sensor/EcosystemScanner.h"
#include "../../../../../fsm_tools/actuator/EcosystemActuator.h"
#include "../../../../../fsm_tools/comm/VisualComm.h"

/* TRADITIONAL GARDEN */
class TG_WaterFanLightNutrientThermo : public BaseStrategy {
    public:
        TG_WaterFanLightNutrientThermo();

        void enter() override;
        void setup(VisualComm *visualCommPtr) override;
        void simulate_ecosystem(EcosystemParameters *ecosystemParamPtr, EcosystemScanner *scannerPtr, EcosystemActuator *actuatorPtr, VisualComm *visualCommPtr) override;
        void exit() override;    
    private:
        uint8_t soilMoistureSensor;
        uint8_t brightnessSensor;
        uint8_t nutrientSensor;
        uint8_t thermoSensor;

        int irrigationSystem;
        int fanSystem;
        int lightSystem;
        int nutrientSystem;
        int thermoSystem;
};