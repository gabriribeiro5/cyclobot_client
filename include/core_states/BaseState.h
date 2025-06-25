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
    virtual void enter();
    virtual void exit();

    // error
    virtual void report_error();
    
    // self
    virtual void run_health_check();

    // comm
    virtual void report_signature_request();
    virtual void session_new();
    virtual void report_config();
    virtual void report_health_check();

    // update
    virtual void update_config();
    virtual void update_simmulation_code();
    
    // comm
    virtual void session_stop();
    
    // simm
    virtual void run_simmulation();
    
    // comm
    virtual void report_simmulation_data();
    
    // self
    virtual void take_a_nap();
};
