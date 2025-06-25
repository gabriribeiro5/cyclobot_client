#pragma once
#include <stdexcept>
#include <string>

class StateTransitionException : public std::runtime_error {
public:
    explicit StateTransitionException(const std::string& msg)
        : std::runtime_error("StateTransitionException: " + msg) {}
};
