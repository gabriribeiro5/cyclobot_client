#include <Arduino.h>
#include <math.h>
#include "../../../../include/strategies/vivarium/paludarium/PL_FogLightFan.h"
#include "../../../../include/fsm_tools/data/EcosystemData.h"
#include "../../../../include/fsm_tools/config/DeviceParameters.h"
#include "../../../../include/fsm_tools/sensor/EcosystemScanner.h"
#include "../../../../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../../../../include/fsm_tools/comm/VisualComm.h"

/* PALUDARIUM */
void PL_FogLightFan::create_pin_map(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) {
    // FOG CONTROL (Sensor + Atuator)
    configDataPtr->add_pin("uint8_t", "soilMoistureSensor", A0,
        "Sensor de umidade do solo pino A0 conectado no A0 do Arduino",
        0, rtc->now()
    );
    configDataPtr->add_pin("int", "fogSystem", 4,
        "Porta de controle do USB 5V",
        0, rtc->now()
    );
    
    // LIGHT CONTROL (Sensor + Atuator)
    configDataPtr->add_pin("uint8_t", "sunLightSensor", A1,
        "Sensor de luminosidade pino A1 conectado no A1 do Arduino",
        0, rtc->now()
    );
    configDataPtr->add_pin("int", "lightSystem", 5,
        "Porta de controle do sistema de iluminação conectada no D5 do Arduino",
        0, rtc->now()
    );
    // WS2812 RGB LED data pin
    configDataPtr->add_pin("int", "lightRGB_data", 7,
        "Pino de dados para WS2812 RGB LED conectado no D7 do Arduino",
        0, rtc->now()
    );
    
    // FAN CONTROL (Sensor + Atuator)
    configDataPtr->add_pin("uint8_t", "airHumiditySensor", A2,
        "Sensor de umidade do ar pino A2 conectado no A2 do Arduino",
        0, rtc->now()
    );
    configDataPtr->add_pin("int", "fanSystem", 6,
        "Porta de controle do sistema de ventilador conectada no D6 do Arduino",
        0, rtc->now()
    );
}

void PL_FogLightFan::set_self_diagnosis_parameters(SelfDiagnosisData *selfDiagnosisDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) {
    // selfDiagnosisDataPtr->add_parameter("bool", "fogSystemOK", 1,
    //                             "condição do sistema de nebulização; 1 = funcionando (true); 0 = com defeito (false)",
    //                             0, 0, 0, rtc->now(), rtc);
}

void PL_FogLightFan::board_setup(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) {
    // FOG CONTROL (Sensor + Atuator)
    pinMode(configDataPtr->config_uint8_t("soilMoistureSensor").value, INPUT);     // Sensor de umidade do solo - A0 é entrada
    pinMode(configDataPtr->config_uint8_t("fogSystem").value, OUTPUT);             // Porta de controle do USB 5V - D4 é saída
    
    // LIGHT CONTROL (Sensor + Atuator)
    pinMode(configDataPtr->config_uint8_t("sunLightSensor").value, INPUT);         // Sensor de luminosidade - A1 é entrada
    pinMode(configDataPtr->config_uint8_t("lightSystem").value, OUTPUT);           // Porta de controle do sistema de iluminação - D5 é saída
    // WS2812 RGB LED data pin
    pinMode(configDataPtr->config_int("lightRGB_data").value, OUTPUT);             // Pino de dados WS2812 - D7 é saída

    // FAN CONTROL (Sensor + Atuator)
    pinMode(configDataPtr->config_uint8_t("airHumiditySensor").value, INPUT);     // Sensor de umidade do ar - A2 é entrada
    pinMode(configDataPtr->config_uint8_t("fanSystem").value, OUTPUT);            // Porta de controle do sistema de ventilador - D6 é saída
}

void PL_FogLightFan::create_ecosystem_params(EcosystemData *ecosystemDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) {
    // FOG CONTROL
    ecosystemDataPtr->add_parameter("int", "soilMoistureMinimum", 200,
                                "valor da tensão de comparação do sensor / valor máximo = 1024",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("bool", "soilIsWet", 0,
                                "condição de solo úmido; 1 = solo umido",
                                0, 0, 0, rtc);
    
    ecosystemDataPtr->add_parameter("int", "soilMoistureExpected", 500,
                                "valor da tensão de comparação do sensor / valor máximo = 1024",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("bool", "soilMoistureIsIdeal", 0,
                                "condição de umidade ideal para o solo; 1 = solo ideal; 0 = solo não ideal",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("bool", "soilMoistureIncreasePerSec", 0,
                                "condição de umidade ideal para o solo; 1 = solo ideal; 0 = solo não ideal",
                                0, 0, 0, rtc);
    
    // LIGHT CONTROL
    ecosystemDataPtr->add_parameter("bool", "sunLightMinimum", 1,
                                "condição de iluminação; 1 = dia; 0 = noite",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("bool", "lightsOn", false,
                                "condição de iluminação; 1 = dia (true); 0 = noite (false)",
                                0, 0, 0, rtc);

    // Simulated sunlight intensity in percent (0..100)
    ecosystemDataPtr->add_parameter("int", "intensity_pct", 0,
                                "Percentual de intensidade da luz solar simulada (0-100)",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("int", "sunLightIntensity", 0,
                                "Intensidade da luz solar simulada (0-100%)",
                                0, 0, 0, rtc);

    // RGB color spectrum control (0-100% each channel)
    ecosystemDataPtr->add_parameter("int", "lightRed_intensity", 100,
                                "Intensidade relativa do espectro vermelho (0-100%)",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("int", "lightGreen_intensity", 30,
                                "Intensidade relativa do espectro verde (0-100%)",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("int", "lightBlue_intensity", 50,
                                "Intensidade relativa do espectro azul (0-100%)",
                                0, 0, 0, rtc);
    
    // FAN CONTROL
    ecosystemDataPtr->add_parameter("int", "soilMoistureMaximum", 800,
                                "valor da tensão de comparação do sensor / valor máximo = 1024",
                                0, 0, 0, rtc);
    ecosystemDataPtr->add_parameter("bool", "soilMoistureIsOverLimit", false,
                                "condição de solo muito úmido; 1 = solo muito úmido (true); 0 = solo normal (false)",
                                0, 0, 0, rtc);
}

/* PALUDARIUM */
void PL_FogLightFan::simulate_ecosystem(EcosystemScanner *scannerPtr,
                                            EcosystemActuator *actuatorPtr,
                                            DataInstances *dataPtr,
                                            VisualComm *visualCommPtr,
                                            RTC_DS1307 *rtcPtr
                                        )
{
    // ********* Primary scann *********
    // ********* Irrigation strategy *********
    scannerPtr->read_soil_moisture(dataPtr->configDataPtr, visualCommPtr);
    visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Reading soil moisture..."));
    if (dataPtr->ecosystemDataPtr->sensor_bool("soilIsWet").value) {
        actuatorPtr->fog_system_off(dataPtr->configDataPtr, visualCommPtr);
        visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Soil moisture is ideal. No irrigation needed."));
    }
    else {
        actuatorPtr->fog_system_on(dataPtr->configDataPtr, visualCommPtr);
     }

    // ********* Photosynthesis strategy (simulated via RTC solar cycle) *********
    // Compute decimal hour from RTC
    DateTime now = rtcPtr->now();
    double hour = now.hour() + now.minute() / 60.0 + now.second() / 3600.0;
    visualCommPtr->print_line(("   [PL_FogLightFan::simulate_ecosystem] Current time from RTC ") + String(hour, 2) + "h");

    // Smooth intensity curve for a single window: 0 at edges, 1 at mid-window
    auto window_intensity = [&](double rise, double set)->double {
        // if current time is NOT inside a sunlight window, intensity is 0
        if (!(hour >= rise && hour < set)) return 0.0;
        
        // compute intensity as a sine curve peaking at mid-window
        // x = position of sun during the day
        double x = (hour - rise) / (set - rise); // 0..1
        
        // create a half sine wave
        return sin(M_PI * x);
    };

    visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Calculating sunlight intensity based on RTC time..."));
    // Define windows: morning (07:00-11:00) and afternoon (15:00-19:00)
    double inten_morning = window_intensity(7.0, 11.0);
    double inten_afternoon = window_intensity(15.0, 19.0);
    double intensity = (inten_morning > inten_afternoon) ? inten_morning : inten_afternoon;

    visualCommPtr->print_line(("   [PL_FogLightFan::simulate_ecosystem] Calculated raw sunlight intensity (0.0-1.0)"));
    // Store intensity as an integer percentage (0..100) and update light flag
    int intensity_pct = (int)round(intensity * 100.0);
    dataPtr->ecosystemDataPtr->set_int_value((char *)"sunLightIntensity", intensity_pct, rtcPtr);
    const double threshold = 0.05; // intensity threshold to consider 'lightsOn'
    bool lightsOn = (intensity > threshold);
    dataPtr->ecosystemDataPtr->set_bool_value((char *)"lightsOn", lightsOn, rtcPtr);

    visualCommPtr->print_line(("   [PL_FogLightFan::simulate_ecosystem] Sunlight intensity percentage"));
    
    // Apply light intensity via PWM control
    actuatorPtr->light_system_pwm(dataPtr->configDataPtr, visualCommPtr);
    
    // Debug output
    char _buf[96];
    snprintf(_buf, sizeof(_buf), "   [PL_FogLightFan::simulate_ecosystem] Sun intensity=%d%% (hr=%.2f)", intensity_pct, hour);
    visualCommPtr->print_line(_buf);
    if (lightsOn) {
        visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Sunlight is available. It's day time."));
    } else {
        visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Sunlight is not available. It's night time."));
    }

    // ********* Atmosphere strategy *********
    scannerPtr->read_soil_moisture(dataPtr->configDataPtr, visualCommPtr);    
    if (dataPtr->ecosystemDataPtr->sensor_bool("soilMoistureIsOverLimit").value) {
        visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Soil moisture is over the maximum limit. Activating fan system..."));
        actuatorPtr->fan_system_on(dataPtr->configDataPtr, visualCommPtr);
        while (dataPtr->ecosystemDataPtr->sensor_bool("soilMoistureIsOverLimit").value)
        {
            scannerPtr->read_soil_moisture(dataPtr->configDataPtr, visualCommPtr);
            delay(2000); // wait 2 seconds before next reading to avoid spamming the sensor and the serial output
            visualCommPtr->print_line(("   [PL_FogLightFan::simulate_ecosystem] Soil moisture:") +
                                       String(dataPtr->configDataPtr->config_uint8_t("soilMoistureSensor").value));
        }
        actuatorPtr->fan_system_off(dataPtr->configDataPtr, visualCommPtr);
    } else {
        visualCommPtr->print_line(F("   [PL_FogLightFan::simulate_ecosystem] Soil moisture is within acceptable limits. No need to activate fan system."));
    }
}

/* PALUDARIUM */
void PL_FogLightFan::exit(ConfigData *configDataPtr, VisualComm *visualCommPtr, RTC_DS1307 *rtc) {
    return;
}