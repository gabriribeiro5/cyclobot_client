# Project: Cyclobot Oluṣọgba
## Author: Gabriel Ribeiro Emegildio
## GitHub: @gabriribeiro5
## edX: @gabriribeiro
## From: São Paulo, SP, Brazil
## Video recorded at: 28/12/2025

Hi, my name is Gabriel and you're watching a description video of my final project for Harvard's Computer Science online course.

This task requires that we build something of our interest, that we solve an actual problem, that we impact our community, or (no pressure) that we change the world.

We must strive to create something that outlives this course.

So, the problem I decided to take is... **global warming**. Cities like São Paulo and New York produce tons of CO2 every year and it has been accumulated in our air for decades.

If only these cities could have their buildings growing some green life attached to their structures - evolving towards a Solar Punk type of city rather than a Cyber Punk - we'd be able to reduce the amount of CO2 around us.

====================================================================================================================================================================================================================================================================================


## The macro solution
The macro solution for this problem is having arduinos (or any other compatible microcontrollers) dedicaded to take care of plants in hard-to-reach places, such as the external walls of high buildings.

Those devices, equiped with sensors and actuators, would scan the environment and decide, when to activate watering systems, cut down the sunlight or even activate a trimming system.

Each device is constantly connected to a server that not only analizes each environment data, but also the devices self-diagnosis data.

This server then decides if a given device must (or not) change its parameters or update its firmware, allowing those devices to quikly adapt and last longer.

## The selected project
Designing the database and the API for this project has been quite cool but the **device's software** is **a perfect fit** for CS50's final project. Besides the fact that it's documentation is pretty advanced, this project requires an strict memory management, just like C, while forces me to learn arduino's **PREFERED language**.

Cyclobot Oluṣọgba is an scalable arduino firmware, written in C++, that leverages from State and Strategy 
Design Patterns to ensure modularity and flexibility.

By changing STATES, the controller stablishes a loop where:
- First it runs a Health Check for sensors and actuators;
- It sends the health check data to a server and awaits for update instructions;
- It runs the updates accordingly with server instructions;
- And then it selects what we might call an Ecosysem Simulation (or just an Strategy) specially tailored for a given ecosystem, that will define "what", "when" and "for how long" sensors and actuator will be activted.
 - After running an Strategy, it sends the sensors data to the server and finally enters an energy saving mode.

I'm Gabriel Ribeiro and this is CS50.