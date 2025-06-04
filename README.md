# eco_unit
An scalable arduino sketch designed to keep closed and small ecosystems alive.

---
## ✅ Features
- [ x ] Check soil moisture level
- [ x ] Activate/deactivate rain system accordingly with soil moisture level
- [ ] Mimics sunlight daily cicle by gradually switching On/Off individual LED lights
- [ ] Activate/Deactivate fan system to simulate wind (activation time and duration are both random)
- [ ] Store collected data in EEPROM or SD (if available)
- [ ] Scan and connect to known Wi-Fi networks
- [ ] Build web client to communicate with API (GET/POST)
- [ ] Send stored data to webserver
- [ x ] Collects current date and time on sturtup
- [ ] Implement local time synchronization via NTP or API
- [ ] Handle incoming configuration updates and apply changes
- [ ] Collect new config file data to update system behavior

##  ♻️ Eco Unit simplified lifecycle
0. Start
1. Self Diagnosis
2. Comm
4. Simm
5. Comm
6. Sleep
*Update and Error are wildcards to be handled

## Eco Unit
This software is designed to run in IoT devices called Eco Units.

Eco Units are meant to:
1. Keep track of a given ecosystem's health leveraging from multiple sensors;
2. Send healthcheck data to a given server;
3. Manipulate the ecosystem through actuators (such as watering and fan systems).
4. Leverage from server communication to update it's own configuration and firmware whenever needed.

Foreseeable versions of this software will support human inputs, so they can interact with the device.

## Design
This application leverages from Clean Architecture principles and State Design Pattern.
Modules are organized as follows:

- **Core States**: All possible states for the machine being controlled.
    - Finite State Machine: State management module;
    - Base State: Interface for all states;
    - Self Diagnosis: ;
    - Error: ;
    - Communication: ;
    - Firmware Update: ;
    - Config Update: ;
    - Simulation: Tailored behaviours for ecosystem simulation. Must be defined at config;
    - Idle: ;

- **Actuators**: .

- **Sensors**: .

- **Communication**: .

- **Configurations**: .

- **Tests**: Unit tests that must run before the application starts.

- **Utilities**: Utilities that enhance flexibility and control over the application.

## Running the Application

As an embedded software, this application is meant to run as "plug and play".

1. Attach the src directory to your microcontroller;
2. Set your Eco Unit physical components in place;
3. Plug your microcontroller to an energy source;
4. Enjoy your Eco Unit 🌱🍃🌝

## Pin layout


## References:
- State Diagram [https://en.wikipedia.org/wiki/State_diagram#UML_state_machine];
- Finite State Machines [https://en.wikipedia.org/wiki/Finite-state_machine];
- Forragem Verde Hidroponica (Pt 1) [https://www.youtube.com/watch?v=ezPb8cQ_ykY]
- Forragem Verde Hidroponica (Pt 2) [https://www.youtube.com/watch?v=RlDwTFIJP64]

## Inspiration
- A Importância da Exploração Espacial by CienciaSemFim [https://www.youtube.com/watch?v=6mof9nqcvMY]
- Space Farming by BBC (5 min) [https://www.youtube.com/watch?v=vv6ATRPUjrI];
- Space Farming by CNA Insider (47 min) [https://www.youtube.com/watch?v=nXrCtC-KYCc];