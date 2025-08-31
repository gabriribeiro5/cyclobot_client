#pragma once
#include "..\BaseState.h"
#include "..\..\Context.h"
class FiniteStateMachine; // Forward declaration


class HTTPClientState : public BaseState {
public:
    // used by context.changeState
    void enter(FiniteStateMachine *fsm_context) override;
    void exit(FiniteStateMachine *fsm_context) override;

    // comm
    void report_signature_request(FiniteStateMachine *fsm_context) override;
    void session_new(FiniteStateMachine *fsm_context) override;
    void report_config(FiniteStateMachine *fsm_context) override;
    void report_health_check(FiniteStateMachine *fsm_context) override;
    
    void session_stop(FiniteStateMachine *fsm_context) override;
    
    // self
    void take_a_nap(FiniteStateMachine *fsm_context) override;

    // constructor
    HTTPClientState();
};