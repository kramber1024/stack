#pragma once

#include <iostream>
#include "stack.h"


class MyStack : public Stack {
public:
    int Get(int pos);
    void Set(int pos, int num);
    void Sort(int n);
};
