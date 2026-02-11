#include "Arduino.h"
#include "../../../include/fsm_tools/comm/VisualComm.h"
#include "../../../include/fsm_tools/ParameterInstances.h"
#include <EEPROM.h>

extern unsigned int __bss_end;   // Symbol marking the end of the .bss section (static & global variables in RAM).
extern void *__brkval;           // Current end of the heap. NULL (0) if no malloc() has been used yet.
static const uint16_t EEPROM_TOTAL_SIZE = 4096;  // ATmega2560 EEPROM size

/**
 * @brief Print EEPROM usage statistics to Serial
 * @details Shows total EEPROM size, reserved ConfigData regions, and free space
 */
void VisualComm::print_eeprom_usage(char *currentMethodPtr) {    
  print_line(F(" *************************  **     ****[EEPROM USAGE]****     **  ************************* "));
  // Get ConfigData region info from ConfigData constants
  uint16_t bool_region_start = 0;  // CONFIG_EEPROM_START
  uint16_t bool_region_size = 6 + (10 * 80);  // header + 10 records of 80 bytes
  
  uint16_t int_region_start = bool_region_start + bool_region_size;
  uint16_t int_region_size = 6 + (10 * 83);  // header + 10 records of 83 bytes
  
  uint16_t uint8_region_start = int_region_start + int_region_size;
  uint16_t uint8_region_size = 6 + (10 * 80);  // header + 10 records of 80 bytes
  
  uint16_t total_reserved = bool_region_size + int_region_size + uint8_region_size;
  uint16_t free_space = EEPROM_TOTAL_SIZE - total_reserved;
  
  // Print summary
  
  print(currentMethodPtr); print(F(" Total EEPROM:")); print(EEPROM_TOTAL_SIZE); print_line(F(" bytes"));
  
  print(currentMethodPtr); print(F(" BOOL region: ")); print(bool_region_start); print(F("-")); 
  print(bool_region_start + bool_region_size - 1); print(F(" (")); 
  print(bool_region_size); print_line(F(" bytes)"));
  
  print(currentMethodPtr); print(F(" INT region:  ")); print(int_region_start); print(F("-")); 
  print(int_region_start + int_region_size - 1); print(F(" (")); 
  print(int_region_size); print_line(F(" bytes)"));
  
  print(currentMethodPtr); print(F(" UINT8 region:")); print(uint8_region_start); print(F("-")); 
  print(uint8_region_start + uint8_region_size - 1); print(F(" (")); 
  print(uint8_region_size); print_line(F(" bytes)"));
  
  print(currentMethodPtr); print(F(" Total Reserved: ")); print(total_reserved); print(F(" bytes ("));
  print((total_reserved * 100) / EEPROM_TOTAL_SIZE); print_line(F("%)"));
  
  print(currentMethodPtr); print(F(" Free Space: ")); print(free_space); print(F(" bytes ("));
  print((free_space * 100) / EEPROM_TOTAL_SIZE); print_line(F("%)"));

  print_line(F(" *************************  **     **********************     **  ************************* "));
}
/**
 * @brief Read and display a sample of EEPROM contents (hex dump) *
 *  // Dump first 48 bytes of EEPROM (first BOOL region header + few records)
 *  VisualComm::hex_dump_eeprom(0, 48);
 *
 *  // Dump INT region header
 *  VisualComm::hex_dump_eeprom(806, 48);
 *
 *  // Dump UINT8 region header
 *  VisualComm::hex_dump_eeprom(1642, 48);
 * 
 * @param start_addr Starting EEPROM address
 * @param length Number of bytes to dump
 */
void VisualComm::print_eeprom_hex_dump(char *currentMethodPtr, uint16_t start_addr, uint16_t length) {
  print_line(F(" *************************  **     ***[EEPROM CONTENT]***     **  ************************* "));
  print(currentMethodPtr);
  print(F("EEPROM HEX DUMP [0x"));
  Serial.print(start_addr, HEX);
  Serial.flush();
  print(F(" - 0x"));
  Serial.print(start_addr + length - 1, HEX);
  Serial.flush();
  print_line(F("]:"));
  
  for (uint16_t i = 0; i < length; i++) {
    if (i % 16 == 0) {
        print(F("0x"));
        Serial.print(start_addr + i, HEX);
        Serial.flush();
        print(F(": "));
    }
    
    byte val = EEPROM.read(start_addr + i);
    if (val < 0x10) print(F("0"));
    Serial.print(val, HEX);
    Serial.flush();
    print(F(" "));
    
    if ((i + 1) % 16 == 0) Serial.println();
  }
  print_line(F(" *************************  **     **********************     **  ************************* "));
}
void VisualComm::print_free_memory(char *currentMethodPtr) {
  print_line(F(" *************************  **     *****[SRAM USAGE]*****     **  ************************* "));
  int free_memory;

  // If the heap hasn't been used (__brkval == 0)
  if ((int)__brkval == 0) {
    // free space = (address of local var / stack pointer) - (end of bss section)
    free_memory = ((int)&free_memory) - ((int)&__bss_end);
  } else {
    // Otherwise, heap is in use
    // free space = (address of local var / stack pointer) - (current end of heap)
    free_memory = ((int)&free_memory) - ((int)__brkval);
  }

  print(currentMethodPtr);  
  print(" Free Memory: ");
  print(free_memory);
  print_line(" bytes");
  print_line(F(" *************************  **     **********************     **  ************************* "));
}

void VisualComm::print_parameters(ParameterInstances *paramPtr) {
  print_line(F(" *************************  **     ***[CONFIGURATIONS]***     **  ************************* "));
  
  // DEVICE PARAMETERS
  print_line(F("[VisualComm::print_parameters] DEVICE Parameters:"));
  print(F(" - Cyclobot ID: "));
  print_line(paramPtr->deviceParametersPtr->cyclobotId);
  print(F(" - Cyclobot Token: "));
  print_line(paramPtr->deviceParametersPtr->cyclobotToken);
  print(F(" - First Awakening: "));
  print_line(paramPtr->deviceParametersPtr->firstAwakening);
  print(F(" - Sleep Length (ms): "));
  print_line(paramPtr->deviceParametersPtr->sleepLength);
  
  // PERIPHERAL PARAMETERS
  print_line(F("[VisualComm::print_parameters] PERIPHERAL Parameters:"));
  print(F(" - WiFi ESP RX Pin: "));
  print_line(paramPtr->BaseMappingPtr->wifiEspRX);
  print(F(" - WiFi ESP TX Pin: "));
  print_line(paramPtr->BaseMappingPtr->wifiEspTX);
  print(F(" - WiFi ESP RST Pin: "));
  print_line(paramPtr->BaseMappingPtr->wifiEspRST);
  print(F(" - WiFi ESP GPIO2 Pin: "));
  print_line(paramPtr->BaseMappingPtr->wifiEspGPIO2);

  // WIFI PARAMETERS
  print_line(F("[VisualComm::print_parameters] WIFI Parameters:"));
  print(F(" - WiFi SSID: "));
  print_line(paramPtr->wifiParametersPtr->wifiSsid);
  print(F(" - WiFi Firmware Latest Version: "));
  print_line(paramPtr->wifiParametersPtr->wifiFirmwareLatestVersion);
  
  print(F(" - Network Key Index: "));
  print_line(paramPtr->wifiParametersPtr->networkKeyIndex);
  
  print(F(" - Wait Time Per Connection Attempt (ms): "));
  print_line(paramPtr->wifiParametersPtr->waitTimePerConnectionAttempt);
  print(F(" - Max Connection Attempt: "));
  print_line(paramPtr->wifiParametersPtr->maxConnectionAttempt);
  
  print(F(" - Wait Time Per Scan Attempt (ms): "));
  print_line(paramPtr->wifiParametersPtr->waitTimePerScanAttempt);
  print(F(" - WiFi Max Scan Attempt: "));
  print_line(paramPtr->wifiParametersPtr->wifiMaxScanAttempt);
  
  print(F(" - WiFi Status: "));
  print_line(paramPtr->wifiParametersPtr->wifiStatus);
  print(F(" - WiFi Shield Is On: "));
  print_line(paramPtr->wifiParametersPtr->wifiShieldIsOn);
  print(F(" - Network SSID Index: "));
  print_line(paramPtr->wifiParametersPtr->networkSsidIndex);
  print(F(" - Connection Attempt Count: "));
  print_line(paramPtr->wifiParametersPtr->connAttemptCount);
  print(F(" - Scan Count: "));
  print_line(paramPtr->wifiParametersPtr->scanCount);
  
  // CLIENT PARAMETERS
  print_line(F("[VisualComm::print_parameters] CLIENT Parameters:"));
  print(F(" - Server IP: "));
  print_line(paramPtr->clientParametersPtr->apiServer);
  print(F(" - Server Port: "));
  print_line(paramPtr->clientParametersPtr->clientPort);
  print(F(" - Wait Time Per Connection Attempt (ms): "));
  print_line(paramPtr->clientParametersPtr->waitTimePerConnectionAttempt);
  print(F(" - Message Trace: "));
  print_line(paramPtr->clientParametersPtr->msgTrace);
  print(F(" - Reading Lines: "));
  print_line(paramPtr->clientParametersPtr->readingLines);
  print(F(" - Timeout Reference (ms): "));
  print_line(paramPtr->clientParametersPtr->timoutReference);
  print(F(" - Response Timeout Limit (ms): "));
  print_line(paramPtr->clientParametersPtr->responseTimeoutLimit);
  print(F(" - Server Is Up: "));
  print_line(paramPtr->clientParametersPtr->serverIsUp);
  print(F(" - Server Response Chars: "));
  print_line(paramPtr->clientParametersPtr->server_response_chars);
  print(F(" - Server Response: "));
  print_line(paramPtr->clientParametersPtr->server_response);
  
  // sizes
  print(F(" - Signature Request Size: "));
  print_line(paramPtr->clientParametersPtr->SIGNATURE_REQUESTS_CAPACITY);
  

  // UPDATE PARAMETERS
  
  
  // ECOSYSTEM PARAMETERS
  print_line("[VisualComm::print_parameters] ECOSYSTEM Parameters:");
  print(F(" - Soil Is Wet: "));
  print_line(paramPtr->ecosystemParametersPtr->soilIsWet);
  print(F(" - Soil Moisture Limit: "));
  print_line(paramPtr->ecosystemParametersPtr->soilMoistureLimit);
  print(F(" - Current Temperature: "));
  print_line(paramPtr->ecosystemParametersPtr->currentTemperature);
  print(F(" - Min Temperature Expected: "));
  print_line(paramPtr->ecosystemParametersPtr->minTemperatureExpected);
  print(F(" - Max Temperature Expected: "));
  print_line(paramPtr->ecosystemParametersPtr->maxTemperatureExpected);
  print(F(" - Initial Watering Time Limit: "));
  print_line(paramPtr->ecosystemParametersPtr->initialWateringTimeLimit);
  print(F(" - Growth Rate: "));
  print_line(paramPtr->ecosystemParametersPtr->growthRate);
  print(F(" - Decrease Rate: "));
  print_line(paramPtr->ecosystemParametersPtr->decreaseRate);
  print(F(" - Watering Time Limit: "));
  print_line(paramPtr->ecosystemParametersPtr->wateringTimeLimit);
  print(F(" - Climate: "));
  print_line(paramPtr->ecosystemParametersPtr->climate);
  print(F(" - Sun Light Available: "));
  print_line(paramPtr->ecosystemParametersPtr->sunLightAvailable);
  print(F(" - Stand By: "));
  print_line(paramPtr->ecosystemParametersPtr->standBy);
  print(F(" - Event Start: "));
  print_line(paramPtr->ecosystemParametersPtr->eventStart.timestamp());
  print(F(" - Event End: "));
  print_line(paramPtr->ecosystemParametersPtr->eventEnd.timestamp());
  print(F(" - Time Buffer (ms): "));
  print_line(paramPtr->ecosystemParametersPtr->timeBufferMicroSec);

  print_line(F(" *************************  **     **********************     **  ************************* "));
}

void VisualComm::print_terminal_logo() {
  print_line(F(" "));
  print_line(F(" **"));
  print_line(F(" *****"));
  print_line(F(" *********"));
  print_line(F(" *************"));
  print_line(F(" *****************"));
  print_line(F(" *********************"));
  print_line(F(" *************************  "));
  print_line(F(" *************************  **"));
  print_line(F(" *************************  **                        **      **  ************************* "));
  print_line(F(" *************************  **                    *  * *      **  ************************* "));
  print_line(F(" *************************  **                  *   *  *      **  ************************* "));
  print_line(F(" *************************  **                 *   *   *      **  ************************* "));
  print_line(F(" *************************  **                *   *    *      **  ************************* "));
  print_line(F(" *************************  **                *  *    *       **  ************************* "));
  print_line(F(" *************************  **                 *  *           **  ************************* "));
  print_line(F(" *************************  **                *               **  ************************* "));
  print_line(F(" *************************  **               *                **  ************************* "));
  print_line(F(" *************************  **      *        **               **  ************************* "));
  print_line(F(" *************************  **     * *       **               **  ************************* "));
  print_line(F(" *************************  **      *        **               **  ************************* "));
  print_line(F(" *************************  **      *        **               **  ************************* "));
  print_line(F(" *************************  **        *     **                **  ************************* "));
  print_line(F(" *************************  **         *   **                 **  ************************* "));
  print_line(F(" *************************  **          * **                  **  ************************* "));
  print_line(F(" *************************  **          ***                   **  ************************* "));
  print_line(F(" *************************  **          ***                   **  ************************* "));
  print_line(F(" *************************  **          ***            *      **  ************************* "));
  print_line(F(" *************************  **          ***           * *     **  ************************* "));
  print_line(F(" *************************  **           ***           *      **  ************************* "));
  print_line(F(" *************************  **             ***        *       **  ************************* "));
  print_line(F(" *************************  **              ***     *         **  ************************* "));
  print_line(F(" *************************  **               **** **          **  ************************* "));
  print_line(F(" *************************  **                 *****          **  ************************* "));
  print_line(F(" *************************  **                  ****          **  ************************* "));
  print_line(F(" *************************  **                  ****          **  ************************* "));
  print_line(F(" *************************  **                  ****          **  ************************* "));
  print_line(F(" *************************  **                 ****           **  ************************* "));
  print_line(F(" *************************  **                ****            **  ************************* "));
  print_line(F(" *************************  **               ****             **  ************************* "));
  print_line(F(" *************************  **             *****              **  ************************* "));
  print_line(F(" *************************  **     **********************     **  ************************* "));
  print_line(F(" ***********************  **     **************************     **  *********************** "));
  print_line(F(" *********************  **     ******************************    **  ********************** "));
  print_line(F(" *******************  **     **********************************    **  ******************** "));
  print_line(F(" *****************  **     **************************************    **  ****************** "));
  print_line(F(" ***************  **     ******************************************     **  *************** "));
  print_line(F("                 **    **********************************************     **                "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F(" ************** **     ****  C Y C L O B O T   O L U S O G B A  *****     ** ************** "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F(" ************** **     **********************************************     ** ************** "));
  print_line(F("                **     **********************************************     **                "));
  print_line(F(" ***************  **     ******************************************     **  *************** "));
  print_line(F(" *****************  **     **************************************     **  ***************** "));
  print_line(F(" *******************  **     **********************************     **  ******************* "));
  print_line(F(" *********************  **     ******************************     **  ********************* "));
  print_line(F(" ***********************  **     **************************     **  *********************** "));
  print_line(F(" *************************  **     **********************     **  ************************* "));
  print_line(F(" *************************  **                                **  ************************* "));
}