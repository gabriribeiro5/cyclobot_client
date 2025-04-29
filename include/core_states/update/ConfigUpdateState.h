#pragma once
#include "BaseState.h"

class ConfigUpdateState : public BaseState {
public:
    void enter(FiniteStateMachine* unit) override;
    void execute(FiniteStateMachine* unit) override;
    void exit(FiniteStateMachine* unit) override;
};
