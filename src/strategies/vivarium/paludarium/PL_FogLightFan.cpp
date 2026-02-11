#include <Arduino.h>
#include "../../../../include/strategies/vivarium/paludarium/PL_FogLightFan.h"
#include "../../../../include/fsm_tools/config/EcosystemParameters.h"
#include "../../../../include/fsm_tools/config/DeviceParameters.h"
#include "../../../../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../../../../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../../../../include/fsm_tools/comm/VisualComm.h"

/* PALUDARIUM */
void PL_FogLightFan::enter(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) {
    visualCommPtr->print_line(F("  [PL_FogLightFan::enter] creating configuration parameters..."));
    visualCommPtr->print_free_memory("  [PL_FogLightFan::enter]");
    configDataPtr->add_pin("uint8_t", "soilMoistureSensor", A0,
        "Sensor de umidade do solo pino A0 conectado no A0 do Arduino",
        0, rtc->now()
    );
    configDataPtr->add_pin("uint8_t", "irrigationSystem", A1,
        "Sensor de chuva pino A1 conectado no A1 do Arduino",
        0, rtc->now()
    );
    configDataPtr->add_pin("int", "relePort", 4,
        "Porta de controle do relé conectada no D4 do Arduino",
        0, rtc->now()
    );
    configDataPtr->add_pin("int", "soilIsWet", 0,
        "condição de solo úmido; 1 = solo umido",
        0, rtc->now()
    );
    configDataPtr->add_parameter("bool", "soilIsWet", 0,
                                "condição de solo úmido; 1 = solo umido",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "soilMoistureLimit", 500,
                                "valor da tensão de comparação do sensor / valor máximo = 1024",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "currentTemperature", 20,
                                "valor de tensão de comparação do sensor / valor máximo = Não sei / média esperada 20 graus",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "minTemperatureExpected", 18,
                                "abaixo de 18 graus já é frio",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "maxTemperatureExpected", 22,
                                "abaixo de 22 graus já é frio",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "initialWateringTimeLimit", 2000,
                                "em milisegundos",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "growthRate", 0,
                                "em milisegundos",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "decreaseRate", 0,
                                "em milisegundos",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "wateringTimeLimit", 3000,
                                "em milisegundos",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("int", "climate", 1,
                                "0 = abaixo de 18 graus; 1 = entre 18 e 22 graus; 2 = mais de 22 graus",
                                0, 0, rtc->now());
    configDataPtr->add_parameter("bool", "sunLightAvailable", 1,
                                "condição de iluminação; 1 = dia; 0 = noite",
                                0, 0, rtc->now());
     
    visualCommPtr->print_line(F("  [PL_FogLightFan::enter] creating configuration parameters... done."));
}

/* PALUDARIUM */
void PL_FogLightFan::setup(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) {
    pinMode(configDataPtr->config_uint8_t("soilMoistureSensor").value, INPUT);     // Sensor de umidade do solo - porta A0 é entrada 
    pinMode(configDataPtr->config_uint8_t("irrigationSystem").value, INPUT);       // Sensor de chuva - porta A1 é entrada 
    pinMode(configDataPtr->config_uint8_t("relePort").value, OUTPUT);              // Porta de controle do Relé - D4 é saída 
    digitalWrite(configDataPtr->config_uint8_t("relePort").value, HIGH);           // Mantém relé desligado  
}

/* PALUDARIUM */
void PL_FogLightFan::simulate_ecosystem(EcosystemScanner *scannerPtr,
                                            EcosystemActuator *actuatorPtr,
                                            ConfigData *configDataPtr,
                                            VisualComm *visualCommPtr,
                                            RTC_DS3231 *rtc
                                        )
{
    // // ********* Primary scann *********
    scannerPtr->read_soil_moisture(configDataPtr, visualCommPtr);
    
    // ********* Irrigation strategy *********
    visualCommPtr->print_line(F("  [PL_FogLightFan::simulate_ecosystem] Irrigation strategy..."));
    if (!configDataPtr->config_bool("soilIsWet").value) {
        actuatorPtr->irrigation_system_on(configDataPtr, visualCommPtr);
        while (!configDataPtr->config_bool("soilIsWet").value)
        {
            scannerPtr->read_soil_moisture(configDataPtr, visualCommPtr);
        }
        actuatorPtr->irrigation_system_off(configDataPtr, visualCommPtr);
    }
}

/* PALUDARIUM */
void PL_FogLightFan::exit(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS3231 *rtc) {
    return;
}