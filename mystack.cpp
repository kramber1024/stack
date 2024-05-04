#include "mystack.h"

using namespace std;


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

void MyStack::Set(int pos, int num)
{
    Stack temporaryStack;

    for (int i = 0; i < pos; i++)
    {
        temporaryStack.Push(Pop());
    }

    Pop();
    Push(num);

    for (int i = 0; i < pos; i++)
    {
        Push(temporaryStack.Pop());
    }
}

void MyStack::Sort(int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int j;
            int temp = Get(i);

            for (j = i; j >= gap && Get(j - gap) > temp; j -= gap)
            {
                Set(j, Get(j - gap));
            }                

            Set(j, temp);
        }
    }
}
