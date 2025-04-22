#ifndef BASE_STATE_H
#define BASE_STATE_H

class StateMachine;  // Forward declaration

class BaseState {
public:
    virtual void enter() = 0;
    virtual void update() = 0;
    virtual ~BaseState() {}
};

#endif
