#include "main.h"

using namespace std;

int main()
{
	MyStack stack;

    for (int i = 1; i < 101; i++)
    {
        stack.Push(i);
    }
    cout << stack.Length() << endl;
    stack.ShowAll();
    // cout << stack.Get(3) << endl;
    // stack.ShowAll();
}
