#pragma once
#include "Context.h"
/*
    This interface should be implemented in every state
    It contains no .cpp pair file
    
    The base state class declares methods that all concrete
    states should implement and also provides a backreference to
    the context object associated with the state. States can use
    the backreference to transition the context to another state.
*/

class BaseState {
public:
    virtual ~BaseState();
    
    // used by context.changeState
    virtual void enter(FiniteStateMachine *unit);
    virtual void exit(FiniteStateMachine *unit);
    
    // self
    virtual void run_health_check(FiniteStateMachine *unit);

    // comm
    virtual void connect_wifi(FiniteStateMachine *unit);
    virtual void report_self_diagnostics(FiniteStateMachine *unit);
    
    // error
    virtual void report_error(FiniteStateMachine *unit);

    // update
    virtual void update_config(FiniteStateMachine *unit);
    virtual void update_firmware(FiniteStateMachine *unit);
    
    // simm (24h)
    virtual void run_simmulation(FiniteStateMachine *unit);
    
    // comm
    virtual void report_sensor_data_from_simm_state(FiniteStateMachine *unit);
    
    // self
    virtual void take_a_nap(FiniteStateMachine *unit);
};
