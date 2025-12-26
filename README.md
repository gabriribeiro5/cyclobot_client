# Cyclobot Oluṣọgba

Cyclobot Oluṣọgba is an scalable arduino firmware (C++) designed to keep self contained and small ecosystems alive.

Oluṣọgba means "the gardner" in Yoruba.

You may replace "self contained and small ecosystems" with options that might range from "a simple terrarium that sits on your desk" to "an entire living room", "a rooftop garden" or even "a section of the zoo".

Each of those places are home to some kind of life that we actualy care.

Some of those lifes might require a temperature control system to make them fell cozy while watching TV, other lifes might require an specific amount of light per day, others might even require an specific amount of water, depending on current temperature and soil moisture.

Cyclobot Oluṣọgba is designed not only to interact with the ecosystem thru a given script but also to collect data about the ecosystem, send it to a server, get eventual update instructions from the server, update configurations and firmware, handle forseable errors, manage energy consumption and rerun the ecosystem simulation.


Cyclobots are meant to:
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
5. Simulation
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
