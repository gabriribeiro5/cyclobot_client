Hi, contributor!

Thanks for supporting this project - your contribution means a lot! This guide will help you during the entire contribution proccess. We are together on it!

Here I'll provide you with all necessary instructions on how to:

🔧 Understand required tools amd dependencies
▶️ Run the application in a microcontroler
📄 Read application outputs
👨‍💻 Change source code dynamically
🧪 Test and debug your changes
📝 **Name branches and commit your updates correctly**
📬 Send acceptable pull requests
I recommend keeping this file open as you go through each step. I also encourage you to copy and run any code snippets I’ve included to make your work easier.

Have fun!

🔧

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
*Press 'mode' before fash firmware.

[How to flash firmware to ESP8266](https://www.robocore.net/tutoriais/gravacao-firmware-esp8266?srsltid=AfmBOoq7Z2siZ1wv-m1VK9QuEQdM3FSby37vNpy6y2hfVySedJudaHWn)

### Standard mode (ATmega2560 + ESP8266 + USB Serial open) 
**DIP Switches:**
- 1, 2, 3 and 4: ON
- 5, 6, 7 and 8: OFF
**Serial Switch:** RXD3 and TXD3

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


### ✅ Branch Naming Guidelines

All branch names in this project **must follow the [Conventional Branch](https://conventionalbranch.org/) specification**. This ensures consistent, readable branch history and enables automated tooling like Continuous Integration/Continuous Deployment pipelines.

#### Prefixes
- feature/ (or feat/): For new features (e.g., feature/add-login-page, feat/add-login-page)
- bugfix/ (or fix/): For bug fixes (e.g., bugfix/fix-header-bug, fix/header-bug)
- hotfix/: For urgent fixes (e.g., hotfix/security-patch)
- release/: For branches preparing a release (e.g., release/v1.2.0)
- chore/: For non-code tasks like dependency, docs updates (e.g., chore/update-dependencies)


#### Formatting Rules
- Use lowercase: Write all letters in lower case.
- Use hyphens: Separate words with a hyphen (-) instead of spaces or underscores.
- Keep it short: Limit descriptions to 3 to 5 clear words.
- No special characters.

#### Tools to adopt and enforce Conventional Branch:

- commit-check: Check branch names, commit messages, and related Git metadata locally.
- commit-check-action: Validate branch names automatically in GitHub Actions.
- VSCode Conventional Branch: Create Conventional Branch names from Visual Studio Code.
- Conventional Branch Skill: Teach AI coding assistants how to create valid Conventional Branch names.



### ✅ Commit Message Guidelines

All commits in this project **must follow the [Conventional Commits](https://www.conventionalcommits.org/) specification**. This ensures consistent, readable commit history and enables automated tooling like changelogs and semantic versioning.

#### 🚫 Avoid using `git commit`

Instead, use **Commitizen** to create structured and meaningful commit messages.
Once you are very confident with commit message structure and it's options,
you may use TODO file to both log your actions and create your commit messages.

#### 🔧 Installing Commitizen
If you haven't installed it yet, please check the section "Installing Developer Tools" at the beginning of this file.

#### 📝 Using Commitizen
Once your Commitizen is installed and you have added your changes to be commited, run the following command to commit your changes:

```bash
cz commit
```

* Use the arrow keys to select the type of change you’re committing.
* Answer the prompted questions using the "Commit pattern references" bellow.
* Press `Enter` after each answer.
* Your commit will be formatted correctly and automatically checked against project rules.

> 💡 Tip: To view your previous commits, run `git log` in your terminal.


**Commit pattern reference**
Our commits follow this structure:

* **`fix:`** — Patches a bug (maps to **PATCH** in Semantic Versioning).
* **`feat:`** — Introduces a new feature (maps to **MINOR**).
* **`BREAKING CHANGE:`** — Introduces a breaking API change (maps to **MAJOR**). This can be included in any commit type using a `BREAKING CHANGE:` footer or by adding a `!` after the type/scope (e.g., `feat!:`, `refactor!:`, etc.).

Other allowed types include:

* `build:` — Changes to build system or dependencies
* `chore:` — Routine maintenance tasks
* `ci:` — Continuous integration-related changes
* `docs:` — Documentation updates
* `style:` — Code style changes (formatting, etc.)
* `refactor:` — Code changes that neither fix a bug nor add a feature
* `perf:` — Performance improvements
* `test:` — Adding or updating tests

For more details, see the [Conventional Commits documentation](https://www.conventionalcommits.org/en/v1.0.0/).


### 📬 Send acceptable pull requests
Make sure that:
1. The application runs as expected
2. Your commit messages follow the Conventional Commit guidelines
3. Your branch name follows the Conventional Branch guidelines

Then:
You’re ready to open your pull request 🥳
Thank you for contributing!