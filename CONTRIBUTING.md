# Cyclobot Oluṣọgba
An scalable arduino sketch designed to keep closed and small ecosystems alive.

## Dependencies:
DO NOT update ArduinoJson version.
- ArduinoJson 6.19.4 is the latest version compatible with Arduino.
- All versions between 6.19.4 and 7.4.2 have been tested.

## Supported systems:
Althought the authors of this code are commited to comply with 32 bits system requirements like Arduino Due's and ESP32's,
this application is primarily developed to run on Arduino Mega (ATmega2560).

Once it takes a considerable ammount of memory, this application DOES NOT fit in entry level boards such as Arduino UNO.

## Intro to ATmega2560 with wifi shield integrated (ESP8266)
- [Overall board components](https://robotdyn.com/mega-wifi-r3-atmega2560-esp8266-flash-32mb-usb-ttl-ch340g-micro-usb.html)
- [ESP8266 documentation](https://docs.espressif.com/projects/esp-at/en/release-v2.3.0.0_esp8266/Get_Started/index.html?__cf_chl_rt_tk=qwndUwwEdTQsyV59v7J2pPML_YdZ4Pl5dquXCJzhc3M-1772374263-1.0.1.1-.RRak5LLP6xNSQHJhUab3Ho8H89S5XYre906qvZuNvk)
- [How to connect wifi](https://forum.arduino.cc/t/arduino-mega-at2560-with-integrated-esp8266-wifi-how-to-connect/1320451/5)

### ESP8266EX Firmware update:
**DIP Switches:**
- 1, 2, 3, 4 and 8: OFF
- 5, 6, 7: ON

**Serial Switch:** RXD0 and TXD0
*Press 'mode' before fash firmware

[How to flash firmware to ESP8266](https://www.robocore.net/tutoriais/gravacao-firmware-esp8266?srsltid=AfmBOoq7Z2siZ1wv-m1VK9QuEQdM3FSby37vNpy6y2hfVySedJudaHWn)

### Sandard mode (ATmega2560 + ESP8266 + USB Serial open) 
**DIP Switches:**
- 1, 2, 3 and 4: ON
- 5, 6, 7 and 8: OFF
**Serial Switch:** RXD3 and TXD3

