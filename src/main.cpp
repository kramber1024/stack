﻿#include <iostream>
#include <string>
#include <windows.h>
#include "mystack.hpp"

using std::cin, std::cout, std::endl, std::boolalpha, std::string, std::to_string;

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

    stack.Sort(n);

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
            stack.Push(rand() % 10001);
        }

        t_s = GetTickCount64();
        stack.Sort(i * 100);
        t_f = GetTickCount64();

        cout << "sort #" << i << "\n";
        cout << "number of elements: " << i * 100 << "\n";
        cout << "sort time (ms): " << t_f - t_s << "\n";
        cout << "number of operations: " << stack.N_op << "\n";
        cout << endl;
    }
}

int main()
{
    simple_test();
    full_test();
    
    system("pause");

    return 0;
}
