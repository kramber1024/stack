#include "main.h"

using std::cin, std::cout, std::endl, std::boolalpha;

void simple_test()
{
    int n;
    cout << "Please, enter number of elements n = ";
    cin >> n;

    MyStack<int> stack;

    for (int i = 0; i < n; i++)
    {
        int x = rand() % 101;
        stack.Push(x);
    }

    cout << "before: ";
    stack.ShowAll();
    cout << boolalpha << "sorted: " << stack.Sorted() << endl;

    stack.Sort(stack.Length());

    cout << "after: ";
    stack.ShowAll();
    cout << boolalpha << "sorted: " << stack.Sorted() << "\n" << endl;
}

void full_test()
{
    unsigned long long int t_s, t_f;
    int j, i;
    for (i = 1; i < 11; i++)
    {
        MyStack<int> stack;

        for (j = 0; j < i * 100; j++)
        {
            stack.Push(rand() % 100001);
        }

        t_s = GetTickCount64();
        stack.Sort(stack.Length());
        t_f = GetTickCount64();

        cout << "sort #" << i << endl;
        cout << "number of elements: " << i * 100 << endl;
        cout << "sort time (ms): " << t_f - t_s << endl;
        // cout << "number of operations: " << "NOT_READY" << endl;
        cout << endl;
    }
}

int main()
{
    simple_test();
    full_test();

    return 0;
}
