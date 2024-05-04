#include "mystack.h"

using namespace std;


int MyStack::Get(int pos)
{
    Stack temporaryStack;

    for (int i = 0; i < pos - 1; i++)
    {
        temporaryStack.Push(Pop());
    }

    int result = ShowHead();

    for (int i = 0; i < pos - 1; i++)
    {
        Push(temporaryStack.Pop());
    }

    return result;
}

void MyStack::Set(int pos, int num)
{
    Stack temporaryStack;

    for (int i = 0; i < pos - 1; i++)
    {
        temporaryStack.Push(Pop());
    }

    Pop();
    Push(num);

    for (int i = 0; i < pos - 1; i++)
    {
        Push(temporaryStack.Pop());
    }
}
