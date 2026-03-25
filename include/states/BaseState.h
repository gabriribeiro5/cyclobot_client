#pragma once
/*
    This interface should be implemented in every state
    It contains no .cpp pair file
    
    The base state class declares methods that all concrete
    states should implement and also provides a backreference to
    the context object associated with the state. States can use
    the backreference to transition the context to another state.
*/
class FiniteStateMachine; // Forward declaration

class  BaseState {
public:
    // constructor
    virtual ~BaseState() {}

    // used by context.changeState
    virtual void enter(FiniteStateMachine *cyclobot);
    virtual void exit(FiniteStateMachine *cyclobot);
    
    // error
    virtual void handle_error(FiniteStateMachine *cyclobot);
    
    // self
    virtual void run_health_check(FiniteStateMachine *cyclobot);
    
    // comm
    virtual void report_signature_request(FiniteStateMachine *cyclobot);
    virtual void session_new(FiniteStateMachine *cyclobot);
    virtual void report_config(FiniteStateMachine *cyclobot);
    virtual void report_health_check(FiniteStateMachine *cyclobot);
    
    // update
    virtual void update_config(FiniteStateMachine *cyclobot);
    virtual void update_simulation_code(FiniteStateMachine *cyclobot);
    
    // comm
    virtual void session_stop(FiniteStateMachine *cyclobot);
    
    // sim
    virtual void run_simulation(FiniteStateMachine *cyclobot);
    
    // comm
    virtual void report_ecosystem_data(FiniteStateMachine *cyclobot);
    
    // self
    virtual void take_a_nap(FiniteStateMachine *cyclobot);
};