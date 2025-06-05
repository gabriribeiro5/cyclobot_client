#pragma once
#include "BaseState.h"

class SimmulationState : public BaseState {
public:
    // used by context.changeState
    void enter() override;
    void exit() override;

    // error
    void report_error();

    // self
    void run_health_check();

    // comm
    void report_health_check();

    // update
    void update_firmware();
    void update_config();
    
    // simm
    void run_simmulation();
    /* 
    - get Simm module name
    - instantiate Simm class
    - RunSimmulation
    */
    
    // comm
    void report_simmulation_data();
    
    // self
    void take_a_nap();

    // constructor
    void SimmulationState(FiniteStateMachine *cyclobot);
};
