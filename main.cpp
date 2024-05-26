#include <iostream>
#include <string>
#include <windows.h>
#include "mystack.h"

using std::cin, std::cout, std::endl, std::boolalpha, std::string, std::to_string;

string formatNumber(unsigned long long int num) {
    const long long THOUSAND = 1000;
    const long long MILLION = 1000000;
    const long long BILLION = 1000000000;

    if (num >= BILLION) {
        return "(" + to_string(num / BILLION) + "B" + ")";
    } else if (num >= MILLION) {
        return "(" + to_string(num / MILLION) + "M" + ")";
    } else if (num >= THOUSAND) {
        return "(" + to_string(num / THOUSAND) + "K" + ")";
    } else {
        return "";
    }
}

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
            stack.Push(rand() % 1001);
        }

        t_s = GetTickCount64();
        stack.Sort(i * 100);
        t_f = GetTickCount64();

        cout << "sort #" << i << "\n";
        cout << "number of elements: " << i * 100 << "\n";
        cout << "sort time (ms): " << t_f - t_s << "\n";
        cout << "number of operations: " << stack.N_op << " " << formatNumber(stack.N_op) << "\n";
        cout << endl;
    }
}

int main()
{
    simple_test();
    full_test();

    return 0;
}
