#include "stack-max-size.hh"

const char* StackMaxSize::what() const noexcept
{
    return err_.c_str();
}
