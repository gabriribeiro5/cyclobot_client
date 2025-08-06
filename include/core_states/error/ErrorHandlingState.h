#pragma once
#include "..\BaseState.h"
#include "..\..\Context.h"
class FiniteStateMachine; // Forward declaration

class ErrorHandlingState : public BaseState {
public:
    // used by context.changeState
    void enter(FiniteStateMachine *cyclobot) override;
    void exit(FiniteStateMachine *cyclobot) override;

    // error
    void handle_error(FiniteStateMachine *cyclobot) override;
    
    // self
    void run_health_check(FiniteStateMachine *cyclobot) override;

    // comm
    void report_signature_request(FiniteStateMachine *cyclobot) override;
    void session_new(FiniteStateMachine *cyclobot) override;
    void report_config(FiniteStateMachine *cyclobot) override;
    void report_health_check(FiniteStateMachine *cyclobot) override;

    // update
    void update_config(FiniteStateMachine *cyclobot) override;
    void update_simulation_code(FiniteStateMachine *cyclobot) override;
    
    // comm
    void session_stop(FiniteStateMachine *cyclobot) override;
    
    // sim
    void run_simulation(FiniteStateMachine *cyclobot) override;
    
    // comm
    void report_simulation_data(FiniteStateMachine *cyclobot) override;
    
    // self
    void take_a_nap(FiniteStateMachine *cyclobot) override;

    // constructor
    ErrorHandlingState();
};