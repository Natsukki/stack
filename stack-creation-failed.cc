#include "stack-creation-failed.hh"

const char* StackCreationFailed::what() const noexcept
{
    return err_.c_str();
}
