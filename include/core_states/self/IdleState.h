#pragma once
#include "BaseState.h"

class IdleState : public BaseState {
public:
    // used by context.changeState
    void enter() override;
    void exit() override;

    // error
    void report_error() override;
    
    // self
    void run_health_check() override;

    // comm
    void report_signature_request() override;
    void session_new() override;
    void report_config() override;
    void report_health_check() override;

    // update
    void update_config() override;
    void update_simmulation_code() override;
    
    // comm
    void session_stop() override;
    
    // simm
    void run_simmulation() override;
    
    // comm
    void report_simmulation_data() override;
    
    // self
    void take_a_nap() override;

    // constructor
    void IdleState(FiniteStateMachine *cyclobot);
};
