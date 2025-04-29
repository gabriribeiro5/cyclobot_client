#pragma once
#include "BaseState.h"

class SelfDiagnosisState : public BaseState {
public:
    void enter(FiniteStateMachine* unit) override;
    void execute(FiniteStateMachine* unit) override;
    void exit(FiniteStateMachine* unit) override;
};
