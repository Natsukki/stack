#include "stack.hh"

template<class T>
size_t Stack<T>::max_size() const
{
    return this->max_size_;
}

template<class T>
size_t Stack<T>::size() const
{
    return elt_.size();
}

template<class T>
Stack<T>& Stack<T>::push(const T& item)
{
    if (this->size() == this->max_size_)
        throw StackMaxSize("Unable to push, stack max size reached.");
    elt_.push_back(item);
    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator+=(const T& item)
{
    return push(item);
}

template<class T>
Stack<T>& Stack<T>::operator<<(const T& item)
{
    return push(item);
}

template<class T>
T Stack<T>::pop()
{
    if (!size())
        throw StackEmpty("Unable to pop, stack is empty.");
    T ret = elt_.back();
    elt_.pop_back();
    return ret;
}

template<class T>
T Stack<T>::operator--()
{
    return pop();
}

template<class T>
T Stack<T>::operator[](size_t i)
{
    if (i >= this->size())
        throw std::out_of_range("Out of range.");
    return this->elt_[this->size() - 1 - i];
}

template<class T>
bool Stack<T>::operator==(Stack<T>& stack)
{
    if (stack.size() != elt_.size())
        return false;
    for (size_t i = 0; i < elt_.size(); i++)
    {
        if (elt_[i] != stack[i])
            return false;
    }
    return true;
}

template<class T>
std::ostream& Stack<T>::print(std::ostream& s) const
{
    if (!this->size())
        return s;
    s << elt_[0];
    for (size_t i = 1; i < size(); i++)
        s << " " << elt_[i];
    return s;
}

template<class T>
typename std::vector<T>::const_reverse_iterator Stack<T>::begin() const
{
    return elt_.crbegin();
}

template<class T>
typename std::vector<T>::reverse_iterator Stack<T>::begin()
{
    return elt_.rbegin();
}

template<class T>
typename std::vector<T>::const_reverse_iterator Stack<T>::end() const
{
    return elt_.crend();
}

template<class T>
typename std::vector<T>::reverse_iterator Stack<T>::end()
{
    return elt_.rend();
}

template<class T>
void Stack<T>::resize(size_t t)
{
    try
    {
        elt_.reserve(t);
    }
    catch(std::length_error& e)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch(std::bad_alloc& e)
    {
        throw  StackCreationFailed("Allocation failed.");
    }
    while (t < size())
        pop();
    max_size_ = t;
}

template<class T>
std::ostream& operator<<(std::ostream& ostr, const Stack<T>& p)
{
    return p.print(ostr);
}
