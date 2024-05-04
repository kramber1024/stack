#include "main.h"

using namespace std;

int main()
{
	MyStack stack;

    for (int i = 1; i < 6; i++)
    {
        stack.Push(i);
    }
    cout << "before: ";
    stack.ShowAll();

    stack.Set(3, 99);
    
    cout << "after: ";
    stack.ShowAll();
}
