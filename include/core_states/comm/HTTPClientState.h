#pragma once
#include "BaseState.h"

class ClientState : public BaseState {
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
    
    // comm
    void report_simmulation_data();
    
    // self
    void take_a_nap();

    // constructor
    void ClientState(FiniteStateMachine *cyclobot);
};
