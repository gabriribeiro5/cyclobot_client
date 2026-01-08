# TODO_ARDUINO.md
## 📡 Cyclobot Firmware - Task Backlog
This file outlines the tasks related to the development of the Cyclobot's Arduino codebase. Tasks are grouped by priority and domain. The goal is to modularize the firmware, improve communication, and ensure reliable, maintainable, and scalable code.

---

### 🧱 Architecture & Modularity
- [x] Modularize directory structure into the following components: core_states, sensor, actuator, comm (client-server), configuration, utils and tests
- [x] Migrate code from rainforest sketch

---

### 💻 Development Environment
- [x] Redesign folder structure to use PlatformIO (State Pattern Friendly)
- [x] Add `plataformio.ini`;

---

### 🧱 Architecture & Modularity
- [x] feat(State Pattern): to handle Cyclobot lifecycle
  - [x] Learn more C++ (too rusty)
  - [x] Create a working model for State Design
  - [x] Match the model with actual file structure
  - [x] Write lifecycle
  - [x] Create timestamp (sim 24h)
  - [x] Implement Cyclobot context into the model
  - [x] Re-write lifecycle (time is validated on each state | stateflow represents the user interface's logic)
  - [x] Update Concrete States

---

### ▶️ Code features and data
- [x] feat(RainforestSimulation): take old project and fit into new design
  - [x] Distribute single file methods across .h modules
  - [x] Write .cpp code based on .h files
    - [x] Cyclobot's base cycle
    - [x] Context (Finite State Machine)
    - [x] Parameter classes
    - [x] Data classes
    - [x] Sharable pointers
    - [x] Self feats (state, config, data)
    - [x] Comm feats (state, comm, config)
    - [x] Update feats (state, config)

---

### 🔧 Bug fixes
- [x] fix(multiple files): String becomes char*
- [x] fix(memory): reduce memory usage
  - [x] Remove unused libraries
  - [x] Remove string literals and use F() macro
  - [x] Use PROGMEM to store constant data in Flash instead of SRAM
  - [x] Compile code using UNO WiFi Rev2 - ATmega4809 (48kb)
- [x] fix(warning): library ArduinoUniqueID may be incompatible with your current board which runs on megaavr architecture(s).
  - [x] Add support for both ArduinoUniqueID and megaavr with conditional compilation using architecture macros

---

### 🧠 Design Enhancements
- [x] style(sharedInstances): categorize pointers
  - [x] Create shared/group
  - [x] Create category classes (Self, Comm, Simulation, Actuator...) inside shared/group
  - [x] Move pointers from CyclobotInstances to their categry classes

---

### ▶️ Mega 2560 Rev3 version 1.0 (256kb)
- [x] style(modules): remove unused files
- [x] feat (Simulation): finally!
  - [x] State
  - [x] Config params
  - [x] Data
  - [x] Sensor (macro scope)
  - [x] Actuator (macro scope)
  - [xxx] Simulation strategies (macro scope)
- [x] feat(shared strategies): Detail shared instances (tools and strategies)
- [x] feat(TraditionalGarden_Water): First detailed simulation strategy

- [x] fix(strategies): names and #includes
- [x] fix(multiple definitions): add prefix to strategies (TG_, AG_, AQ_, etc)

- [x] feat(destructors): memory cleanup for strategy classes
- [x] feat(wokwi) complete:
  - [x] add files (wokwi.toml and diagram.json)
  - [x] map TG_Water pins using online simulator (wokwi)
    - [x] sensors
    - [x] wifi (https://embarcados.com.br/esp8266-com-arduino)
    - [x] irrigation
  - [x] copy diagram.json from online tool
  - [x] Simulate TG_Water in ATmega2560 (256kb)

- [x] Add sleep mode between readings (if battery-powered)
- [x] Optimize RAM usage using `PROGMEM` for constant data

- [x] style(Serial.println): define pattern
- [x] feat(Startup logo): apply to logs
- [x] fix(Serial.println): board simulation stops printing at some point
  - [x] pattern search: take note of switchCaseNum, last2LogLines -> lastMemorySize
  - [x] Open topic at Arduino Docs (https://forum.arduino.cc/t/mega2560-stops-printing-suddenly-in-the-middle-of-a-string/1404437/9)
  - [x] branch: Isolate error traceback snippets into a coherent and sharable representation of the code
    - [x] Create branch
    - [x] Tramontina moment
    - [x] Run
    - [x] Hopefully get the same Serial.println error
  - [x] Share the branch on your Arduino docs topic
  - [x] perf(main): state instances initialization
    - [x] use switch/case to manage initializations
    - [x] add more lines of Serial.flush()
  - [x] perf(flush): every Serial.print() gets a Serial.flush()
    - [x] Implement cyclobot.say()
    - [x] Replace cyclobot.say() with cyclobot.VisualComm.print_line
    - [x] Replace Serial.println with cyclobot.VisualComm.print_line()
    - [x] Replace Serial.print with cyclobot.VisualComm.print()
    - [x] Update methods to get visualCommPtr as parameter
    - [x] Update strategies to get visualCommPtr as parameter

- [x] fix(multiple methods): update call signature (including visualCommptr)
- [x] fix(warning -Woverflow): update const int sleepLenght to unsigned long
- [x] fix(include paths): replace "\" with "/" or vice-versa
- [x] build(warning -Wattributes): suppressed
- [x] build(warning -Wwrite-strings): suppressed
- [x] build(warning -Wunused-parameter): suppressed
- [x] build(warning -Wimplicit-fallthrough): suppressed

- [x] fix(context): tools initialization in cpp
  - [x] Initialize tools in Contex.cpp
  - [x] Initialize wifi parameters in .cpp file
  - [x] Initialize other parameters in their .cpp files
  - [x] Validate parameters by printing them

- [x] feat(print_parameters): create method call
- [x] feat(print_parameters): add and review base parameters
- [x] style(serial.print): remove debug lines
- [x] style(serial.print): apply indentation
- [x] feat(TG_Water): Validated

- [x] doc(README): describe the context's objects
- [x] doc(TODO): review and try to reduce task list
- [x] doc(README): update features checklist
  - [x] Describe Actuators
  - [x] Describe Sensors
  - [x] Describe Communication
  - [x] Describe Configurations
  - [ ] Add setup procedure for development environment
  - [ ] Add pin layout: wiring diagrams and supported sensors/modules

- [x] doc(README): shorten introduction

- [ ] feat(stream_sensors_data): streaming with frequency control
  - [x] create StrategyParameters module
  - [x] create linked-lists
  - [x] change PeripheralMapping to WIfiMapping leave "peripheral" for strategies
  - [x] refactor(design): strategy is defined in main
  - [xx] fix(inclusion errors): fix module references
  - [x] create add_setup_param(type, name, value...)
  - [x] create add_sensor_param(type, name, value...)
  - [ ] strategies must fullfill linked-lists
  - [ ] strategy runs setup_bool("name") to get struct pointer
  - [ ] strategy runs setup_int("name") to get struct pointer
  - [ ] fix(more inclusion errors): fix module references
  - [ ] create stream_sensors_data method
    - [ ] loops_per_sec = 20
    - [ ] remaning_millisecs = (1sec - (now - loop_start)) / 20 #20 loops/second
    - [ ] wait_time = remaning_millisecs / loops_per_sec
    - [ ] if wait_time is positive, wait(stream_frames)
    - [ ] else, raise warnig ("The streaming loop took longer than expected.")
  - [ ] clear strategy parameters at the end of states loop


- [ ] refactor(EcosystemParameters): move to Strategies
  - [ ] create parameters printing method (use streaming methods)
  - [ ] relocate EcosystemParameters printing from start to streaming stage

- [ ] feat(editable parameters): Create external storage <EEPROM.h> for easy parameters management
  - [x] Create storageManagerPtr
  - [ ] Read about EEPROM
  - [ ] Define StorageManager methods

- [ ] fix(warning -Wwrite-strings): review and try reducing occurences
- [ ] fix(warning -Wattributes): review and try reducing occurences
- [ ] fix(warning -Wunused-parameter): review and try reducing occurences

- [ ] feat(Real Time Clock): apply to logs
  - [ ] create comm.time_update
  - [ ] call comm.time_update
  - [ ] set rtc to zero
  - [ ] insert timers in specific logs such as HTTPClientState's and SimulationState's
- [ ] feat(TG_WaterFanLightNutrientThermo): Detailed simulation strategy
  - [ ] map remaning pins using online simulator (wokwi)
    - [ ] fan
    - [ ] light
    - [ ] nutrient
    - [ ] thermo
- [ ] Simulate TG_WaterFanLightNutrientThermo in ATmega2560 (256kb)
- [ ] Draw circuit
- [ ] feat(comm): implement server
- [ ] refactor(api addresses): review and update

- [ ] fix(update): Update constants and variables to match api configurations.
---

### 🧪 Lifecycle test
- [ ] Set UNO prototype
- [ ] Rebuild paludarium with stone wall (only physics no glue)
- [ ] Test full cycle

---

### 🚀 Deployment
- [ ] Add firmware versioning and update logs
- [ ] Support OTA updates (optional/future)
- [ ] Track successful and failed transmissions

---

### ▶️ UNO R3 limited version 1.0 (32kb) - stateless design  
- [ ] feat(PL_RiverLightFan): Detailed simulation strategy
- [ ] Learn about "Flyweight pattern to minimize memory usage for sensor instances"
- [ ] Code reduction to less than 32kb (yes, it hurts...) 
  - [ ] Reduce states quantity
  - [ ] Reduce peripheral mapping if possible
  - [ ] Remove all states
  - [ ] Remove errorHandling feats
  - [ ] Remove update feats
  - [ ] Remove run_health_check
  
---

### ▶️ Mega 2560 Rev3 version 2.0 (256kb)
- [ ] feat(update_strategies)
  - [ ] State
  - [ ] Config
  - [ ] Update
  - [ ] Failure handler strategies (macro scope)
  - [ ] Failure handler strategies (one detailed)
- [ ] feat(failure handler)
  - [ ] Serial print
  - [ ] Send error code to the server
    - [ ] 601 - health_check: Code err
    - [ ] 602 - health_check: Comm err
    - [ ] 603 - health_check: Pin setup err
    - [ ] 604 - sim strategy: Simulation err
  - [ ] Reboot 3x
  - [ ] Standby for a day
- [ ] feat(sound alarm): activated by the server
- [ ] Apply Strategy Pattern for interchangeable communication protocols (Bluetooth, Wifi, etc)

- [ ] Improve rainforest simulation:
  - [ ] Add methods for enhanced logic and user interaction.
  - [ ] Integrate communication features.

- [ ] Monitor voltage or battery levels (if applicable)

