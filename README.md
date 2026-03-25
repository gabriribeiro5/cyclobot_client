# Cyclobot Oluṣọgba

Cyclobot Oluṣọgba is an scalable arduino firmware (written in C++). It is designed to keep self contained and small ecosystems alive.

Oluṣọgba means "the gardner" in Yoruba.
By "self contained and small ecosystems" I mean a lot of possibilities, from "a simple terrarium that sits on your desk" to "an entire indoor farm".

Cyclobot Oluṣọgba is designed not only to interact with the ecosystem but also to collect data from it, send this data to a server, get eventual update instructions from the server, update its own configurations and rerun the ecosystem interaction script. This cycle ensures that every microcontroler equiped with cyclobot technology can easily adapt it's behaviour when facing some environment change.

Imagine you have a very strict watering plan for your crops and, for some reason, the temperature go higher than expected, your soil dries faster than expected, nutrients don't have enough time to get absorbed by the roots and thus your crops grow slower. With cyclobot managing this cycle, this type of oscilation can be easily detected and mitigation strategies (such as watering a little earlier or even turning on the fan system to cool down the ambiance) can be taken automatically.

In other words, Cyclobots are basically meant to:
1. Keep track of a given ecosystem's health leveraging from multiple sensors;
2. Send healthcheck data to a given server;
3. Manipulate the ecosystem through actuators (such as watering and fan systems).
4. Leverage from server communication to update it's own configuration and firmware whenever needed.

Foreseeable versions of this software will support human inputs, so they can interact with the device.

##  ♻️ Cyclobot simplified lifecycle
0. Start
1. Health Check
3. Send diagnostics
4. Verify and run updates
5. Run ecosystem simulation
6. Send sensors data
7. Sleep
*Error state may be raised by any other state

## Design
This application leverages from Clean Architecture principles, State and Strategy Design Pattern.
Modules are organized as follows:

- **Main**: Responsible for creating the base context and defining a Switch/Case rule to manage this context
  
- **Context**: Named by main as "cyclobot", this is a Finite State Machine. It provides the following types of objects:
  - The **change_state** method: base method required to create a Finite State Machine;
  - A few **general purpose methods**: defined at the context header, they sumarize this application's basic behaviours;
  - Plenty of **specific purpose methods**: Although those methods are not defined at the Context file, they can (and must) be accessed thru the cyclobot's pointers
  - Most of the **parameters** requiered by specific purpose methods
*Note: if you are paying enough attention, you've probably noticed that this context has basically everything we need to build the applicaion. And that's why you'll see the "cyclobot" keyword everywhere in the core state files.

- **Core States**: Using cyclobot as resource of methods and parameters, each state define it's own rule for the context's methods.
    - Finite State Machine: this is the state management module;
    - Base State: the interface for all states;
    - Self Diagnosis: run periodic health checks and log them for future report;
    - Error: an error management protocol (this one seems to require a cristal ball);
    - Communication: handles every type of external communication (might be with the server or the user);
    - Config Update: update parameter files in the configurations directory;
    - Firmware Update: update code files (good look!);
    - Simulation: tailored behaviours for ecosystem simulation. Must be defined at config;
    - Idle: enters an energy saving mode;

- **Actuators**: Those modules are entirely dedicaded to manage peripheral tools such as watering rele or any other peripheral that might affect the ecosystem.

- **Sensors**: Those modules, in the other hand, are exclusively dedicaded to colect data from the ecosystem.

- **Communication**: Modules in this category are meant to manage every type of communication feature.

- **Configurations**: Parameters everywhere! Control the app behaviour by updating those modules.

- **Tests**: All unit tests that must run before the application starts.

- **Utilities**: Utilities that enhance flexibility and control over the application.

### Strategy Pattern Implementation

The application uses the Strategy Design Pattern to allow different ecosystem simulation behaviors. Each strategy is tailored to a specific type of ecosystem (e.g., paludarium, gardem, etc), enabling modular and extensible ecosystem management without altering the core Finite State Machine logic.

#### BaseStrategy Interface

All strategies must inherit from `BaseStrategy` (located in `include/strategies/BaseStrategy.h`) and implement the following pure virtual methods:

- `create_pin_map()`: Define sensor and actuator pins, and add ecosystem parameters for data streaming.
- `set_self_diagnosis_parameters()`: Configure parameters for self-diagnosis and health monitoring.
- `board_setup()`: Set pin modes (INPUT/OUTPUT) for sensors and actuators.
- `set_ecosystem_params()`: Define ecosystem-specific parameters, thresholds and control variables.
- `simulate_ecosystem()`: Implement the core simulation logic, including sensor readings, decision-making, and actuator control based on ecosystem conditions.
- `exit()`: Perform any necessary cleanup or final actions when the strategy is exited.

#### Implementing a New Strategy

To implement a new strategy for a different ecosystem:

1. Create a new header file (e.g., `MyNewStrategy.h`) in the appropriate subdirectory under `include/strategies/` (e.g., `vivarium/terrarium/`).
2. Define a class inheriting from `BaseStrategy`.
3. Implement all six required methods.
4. In `create_pin_map`, use `dataPtr->configDataPtr->add_pin()` to register pins for sensors and actuators, and `dataPtr->ecosystemDataPtr->add_parameter()` for data tracking.
5. In `set_ecosystem_params`, use `configDataPtr->add_ecosystem_parameter()` to add parameters with default values, descriptions, and timestamps.
6. In `simulate_ecosystem`, leverage `scannerPtr` methods to read sensor data, evaluate conditions against parameters, and use `actuatorPtr` methods to control devices.
7. Ensure the new strategy is instantiated and used in the SimulationState or relevant context.

Example: The `PL_FogLightFan` strategy (in `strategies/vivarium/paludarium/`) manages fog irrigation, LED lighting simulation, and fan ventilation for a paludarium, using soil moisture sensors, light sensors, and humidity controls to maintain optimal conditions.

This design allows developers to easily add support for new ecosystems by creating strategy classes that encapsulate specific behaviors, promoting code reusability and maintainability.


## Supported systems:
Althought the authors of this code are commited to comply with 32 bits system requirements like Arduino Due's and ESP32's,
this application is primarily developed to run on Arduino Mega (ATmega2560).

Once it takes a considerable ammount of memory, this application DOES NOT fit in entry level boards such as Arduino UNO (ATMega328p).

## Running the Application

As an embedded software, this application is meant to run as "plug and play".

1. Attach the src directory to your microcontroller;
2. Set your Cyclobot physical components in place;
3. Plug your microcontroller to an energy source;
4. Enjoy your Cyclobot 🌱🍃🌝

## Pin layout
Future updates of this block will most likely include an url to some specific documentation.

## References:
- State Diagram [https://en.wikipedia.org/wiki/State_diagram#UML_state_machine];
- Finite State Machines [https://en.wikipedia.org/wiki/Finite-state_machine];
- Forragem Verde Hidroponica (Pt 1) [https://www.youtube.com/watch?v=ezPb8cQ_ykY]
- Forragem Verde Hidroponica (Pt 2) [https://www.youtube.com/watch?v=RlDwTFIJP64]

## Inspiration
- A Importância da Exploração Espacial by CienciaSemFim [https://www.youtube.com/watch?v=6mof9nqcvMY]
- Space Farming by BBC (5 min) [https://www.youtube.com/watch?v=vv6ATRPUjrI];
- Space Farming by CNA Insider (47 min) [https://www.youtube.com/watch?v=nXrCtC-KYCc];
