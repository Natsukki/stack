#pragma once

#include <exception>
#include <string>

class StackEmpty : public std::exception
{
public:
    StackEmpty(const std::string err)
        : err_(err)
        {}
    virtual const char* what() const noexcept;
private:
    std::string err_;
};
