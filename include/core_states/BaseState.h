#pragma once
#include "Context.h"

/*
    This interface should be implemented in every state
    It contains no .cpp pair file
*/

class BaseState {
public:
    virtual void enter(FiniteStateMachine* unit);
    virtual void execute(FiniteStateMachine* unit);
    virtual void exit(FiniteStateMachine* unit);
    virtual ~BaseState() {}
};
