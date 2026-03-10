#include "../../../include/fsm_tools/actuator/EcosystemActuator.h"
#include "../../../../include/fsm_tools/config/BaseMapping.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/data/ConfigData.h"
#include <Adafruit_NeoPixel.h>

/*
    Actuator methods for ecosystem control in alphabetical order
*/

// Global WS2812 NeoPixel object (1 LED, pin 7, RGB order)
// Will be initialized in light_system_pwm when pin is known
static Adafruit_NeoPixel *pixel = nullptr;

// ******************* FAN CONTROL *******************
void EcosystemActuator::fan_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::fan_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

// ******************* FOG CONTROL *******************
void EcosystemActuator::fog_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::fog_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

// ******************* IRRIGATION CONTROL *******************
void EcosystemActuator::irrigation_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("        [EcosystemActuator::irrigation_system_off] Turning irrigation system OFF..."));
    digitalWrite(configDataPtr->config_uint8_t("irrigationSystem").value, LOW);
}

void EcosystemActuator::irrigation_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("        [EcosystemActuator::irrigation_system_on] Turning irrigation system ON..."));
    digitalWrite(configDataPtr->config_uint8_t("irrigationSystem").value, HIGH);
}

// ******************* LIGHT CONTROL *******************
void EcosystemActuator::light_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("        [EcosystemActuator::light_system_off] Turning light system OFF..."));
}

void EcosystemActuator::light_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("        [EcosystemActuator::light_system_on] Turning light system ON..."));
}

void EcosystemActuator::light_system_pwm(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    visualCommPtr->print_line(F("        [EcosystemActuator::light_system_pwm] Setting light system PWM..."));
    // Initialize NeoPixel strip on first call
    if (pixel == nullptr) {
        uint8_t data_pin = configDataPtr->config_int("lightRGB_data").value;
        pixel = new Adafruit_NeoPixel(1, data_pin, NEO_RGB + NEO_KHZ800);
        pixel->begin();
        pixel->setPixelColor(0, 0, 0, 0); // Turn off initially
        pixel->show();
    }
    
    // Clamp master intensity to [0, 100]
    int intensity_percent = configDataPtr->config_int("intensity_pct").value;
    intensity_percent = (intensity_percent < 0) ? 0 : (intensity_percent > 100) ? 100 : intensity_percent;
    
    // Read RGB spectrum intensities from config (0-100% each)
    int red_base = configDataPtr->config_int("lightRed_intensity").value;
    int green_base = configDataPtr->config_int("lightGreen_intensity").value;
    int blue_base = configDataPtr->config_int("lightBlue_intensity").value;
    
    // Clamp spectrum values
    red_base = (red_base < 0) ? 0 : (red_base > 100) ? 100 : red_base;
    green_base = (green_base < 0) ? 0 : (green_base > 100) ? 100 : green_base;
    blue_base = (blue_base < 0) ? 0 : (blue_base > 100) ? 100 : blue_base;
    
    // Calculate color values: (master intensity * spectrum%) * 255 / 10000
    uint8_t red_val = (intensity_percent * red_base * 255) / 10000;
    uint8_t green_val = (intensity_percent * green_base * 255) / 10000;
    uint8_t blue_val = (intensity_percent * blue_base * 255) / 10000;
    
    // Set WS2812 color and update display
    pixel->setPixelColor(0, pixel->Color(red_val, green_val, blue_val));
    pixel->show();
    
    // Debug output
    char buf[128];
    snprintf(buf, sizeof(buf), "        [EcosystemActuator::light_system_pwm] Intensity=%d%% | RGB: R=%d G=%d B=%d", 
             intensity_percent, red_val, green_val, blue_val);
    visualCommPtr->print_line(buf);
}

// ******************* TRIM CONTROL *******************
void EcosystemActuator::trim_system_off(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::trim_system_on(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

// ******************* WATER CONTROL *******************
void EcosystemActuator::water_nutrients_dilution(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}

void EcosystemActuator::water_nutrients_increase(ConfigData *configDataPtr, VisualComm *visualCommPtr) {
    return;
}