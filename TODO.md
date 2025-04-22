# TODO_ARDUINO.md

## 📡 Eco Unit Firmware - Task Backlog
This file outlines the tasks related to the development of the Eco Unit's Arduino codebase. Tasks are grouped by priority and domain. The goal is to modularize the firmware, improve communication, and ensure reliable, maintainable, and scalable code.

---

### 🧱 Architecture & Modularity
- [x] Modularize directory structure into the following components: core_states, sensor, actuator, comm (client-server), configuration, utils and tests
- [ ] Migrate code from rainforest sketch
- [ ] Use the State Design Pattern to handle Eco Unit lifecycle
- [ ] Refactor sensor interface for polymorphism and code reuse
- [ ] Abstract network communication layer
- [ ] Design interface for persistent storage (EEPROM/SD/Fake)

---

### 🧠 Design Patterns
- [ ] Apply State Pattern for operation modes (Idle, Measuring, Uploading)
- [ ] Use Flyweight to minimize memory usage for sensor instances
- [ ] Strategy Pattern for interchangeable communication protocols

---

### ⚙️ Communication
- [ ] Implement HTTP client abstraction
- [ ] Support JSON formatting for API payloads
- [ ] Reflect server response codes for debugging
- [ ] Add retry strategy and timeout control

---

### 🧪 Testing & Debugging
- [ ] Add simulation mode for sensors
- [ ] LED or serial logs for diagnostics (status/error)
- [ ] Unit test critical logic using PlatformIO or Arduino mocks (searche Eclipse / Sloeber)
- [ ] Measure memory usage and performance bottlenecks

---

### 🔋 Power & Resource Management
- [ ] Add sleep mode between readings (if battery-powered)
- [ ] Optimize RAM usage using `PROGMEM` for constant data
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

