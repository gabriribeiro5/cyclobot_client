#pragma once

class StateTransitionException {
  public:
    const char* message;

    explicit StateTransitionException(const char* msg)
      : message(msg) {}

    const char* what() const {
      return message;
    }
};