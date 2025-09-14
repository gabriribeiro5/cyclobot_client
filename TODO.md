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
- [x] feat(State Pattern - incomplete): to handle Cyclobot lifecycle
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
- [x] feat(RainforestSimulation - incomplete): into new design
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

### ▶️ Mega 2560 Rev3 full version (256kb)
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

### 🔧 Bug fixes
- [x] fix(strategies): names and #includes
- [x] fix(multiple definitions): add prefix to strategies (TG_, AG_, AQ_, etc)

### ▶️ Mega 2560 Rev3 full version (256kb)
- [x] feat(destructors): memory cleanup for strategy classes
- [x] feat(wokwi) complete:
  - [x] add files (wokwi.toml and diagram.json)
  - [x] map TG_Water pins using online simulator (wokwi)
    - [x] sensors
    - [x] wifi (https://embarcados.com.br/esp8266-com-arduino)
    - [x] irrigation
  - [x] copy diagram.json from online tool
  - [x] Simulate TG_Water in ATmega2560 (256kb)

- [x] style(Serial.println): define pattern
- [x] feat(Startup logo): apply to logs
- [ ] fix(Serial.println): board simulation stops printing at some point
  - [x] pattern serach: take note of switchCaseNum, last2LogLines -> lastMemorySize
  - [x] Open topic at Arduino Docs (https://forum.arduino.cc/t/mega2560-stops-printing-suddenly-in-the-middle-of-a-string/1404437/9)
  - [x] branch: Isolate error traceback snippets into a coherent and sharable representation of the code
    - [x] Create branch
    - [x] Tramontina moment
    - [x] Run
    - [x] Hopefully get the same Serial.println error
  - [x] feat(flush): add flush() after println()
  - [x] Share the branch on your Arduino docs topic
  - [x] perf(flush): every Serial Print gets a Flush

