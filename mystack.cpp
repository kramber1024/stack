#include "mystack.h"

template <typename T> T MyStack<T>::Get(int pos)
{
    Stack<T> temporaryStack;

    for (int i = 0; i < pos; i++)
    {
        temporaryStack.Push(this->Pop());
    }

    T result = this->ShowHead();

    for (int i = 0; i < pos; i++)
    {
        this->Push(temporaryStack.Pop());
    }

    return result;
}

template <typename T> void MyStack<T>::Set(int pos, T num)
{
    Stack<T> temporaryStack;

    for (int i = 0; i < pos; i++)
    {
        temporaryStack.Push(this->Pop());
    }

    this->Pop();
    this->Push(num);

    for (int i = 0; i < pos; i++)
    {
        this->Push(temporaryStack.Pop());
    }
}

template <typename T> void MyStack<T>::Sort(int n)
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
