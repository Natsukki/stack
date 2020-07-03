#pragma once

#include <exception>
#include <string>

class StackCreationFailed : public std::exception
{
public:
    StackCreationFailed(const std::string err)
        : err_(err)
        {}
    virtual const char* what() const noexcept;
private:
    std::string err_;
};
