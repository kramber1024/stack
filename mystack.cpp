#include "mystack.h"


int MyStack::Get(int pos)
{
    Stack temporaryStack;

    for (int i = 0; i < pos; i++)
    {
        temporaryStack.Push(Pop());
    }

    int result = ShowHead();

    for (int i = 0; i < pos; i++)
    {
        Push(temporaryStack.Pop());
    }

    return result;
}