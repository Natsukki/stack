#pragma once

#include <exception>
#include <string>

class StackMaxSize : public std::exception
{
public:
    StackMaxSize(const std::string err)
        : err_(err)
        {}
    virtual const char* what() const noexcept;
private:
    std::string err_;
};
