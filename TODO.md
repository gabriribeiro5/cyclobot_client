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
- [ ] feat(RainforestSimulation - incomplete): into new design
  - [x] Distribute single file methods across .h modules
  - [ ] Write .cpp code based on .h files
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
- [ ] feat (Simulation): finally!
  - [x] State
  - [x] Config params
  - [x] Data
  - [x] Sensor (macro scope)
  - [x] Actuator (macro scope)
  - [xxx] Simulation strategies (macro scope)
- [x] feat(shared strategies): Detail shared instances (tools and strategies)
- [x] feat(TraditionalGarden_Water): First detailed simulation strategy
- [x] fix(strategies): names and #includes
- [ ] feat(failure handler):
  - [ ] State
  - [ ] Config
  - [ ] Data
  - [ ] Failure handler strategies (macro scope)
  - [ ] Failure handler strategies (one detailed)
- [ ] Write code for memory cleanup on exit functions
- [ ] Run code online with Mega 2560 Rev3 - ATmega2560 (256kb)

---

### ▶️ UNO R3 limited version (32kb) - stateless design  
- [ ] Code reduction to less than 32kb (yes, it hurts...)
  - [ ] Reduce states quantity
  - [ ] Remove all states
  - [ ] Remove errorHandling feats
  - [ ] Remove update feats
  - [ ] Remove run_health_check
  
---

### 🧠 Design Enhancements
- [ ] style(sharedInstances): categorize pointers
  - [ ] Create shared/group
  - [ ] Create category classes (Self, Comm, Simulation, Actuator...) inside shared/group
  - [ ] Move pointers from CyclobotInstances to their categry classes
  - [ ] Inside the empty CyclobotInstances create pointers to category classes

### 📄 Rename project
- [x] refactor(project name): `Cyclobot` replaces `Eco Units`
- [x] fix(multiple files): apply method_name_pattern

---

### 🧪 Lifecycle test
- [ ] Set UNO prototype
- [ ] Rebuild paludarium with stone wall (only physics no glue)
- [ ] Test full cycle

---

### 🧱 Architecture & Modularity
- [ ] Design interface for persistent storage (EEPROM/SD/Fake)
- [ ] Refactor sensor interface for polymorphism and code reuse
- [ ] Abstract network communication layer

---

### 🧠 Design Enhancements
- [ ] Use Flyweight to minimize memory usage for sensor instances
- [ ] Strategy Pattern for interchangeable communication protocols

---

### 🔁 Communication State
- [ ] Implement Wi-Fi scanning and connectivity.
- [ ] Implement HTTP client abstraction
- [ ] Support JSON formatting for API payloads
- [ ] Reflect server response codes for debugging
- [ ] Add retry strategy and timeout control

---

### ⏫ Update State
- [ ] Update constants and variables from server configurations.

---

### ⚙️ Simulation States
- [ ] Improve rainforest simulation:
  - [ ] Add methods for enhanced logic and user interaction.
  - [ ] Integrate communication features.
- [ ] Collect self-diagnostics.

---

### 🧪 Testing & Debugging
- [ ] Add simulation mode for sensors
- [ ] LED or serial logs for diagnostics (status/error)
- [ ] Unit test critical logic using PlatformIO or Arduino mocks (searche Eclipse / Sloeber)
- [ ] Measure memory usage and performance bottlenecks

---

### 🔋 Power & Resource Management
- [x] Add sleep mode between readings (if battery-powered)
- [x] Optimize RAM usage using `PROGMEM` for constant data
- [ ] Monitor voltage or battery levels (if applicable)

---

### 📄 Documentation
- [ ] Add README.md for firmware features and pin layout
- [ ] Document setup procedure for development environment
- [ ] Include wiring diagrams and supported sensors/modules

---

### 🚀 Deployment
- [ ] Add firmware versioning and update logs
- [ ] Support OTA updates (optional/future)
- [ ] Track successful and failed transmissions
