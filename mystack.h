#pragma once

#include "stack.h"
#include "stack.cpp"

template <typename T> class MyStack : public Stack<T>
{
    public:
        T Get(int pos);
        void Set(int pos, T num);
        void Sort(int n);
};
