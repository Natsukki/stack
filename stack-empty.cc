#include "stack-empty.hh"

const char* StackEmpty::what() const noexcept
{
    return err_.c_str();
}
