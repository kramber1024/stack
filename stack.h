#pragma once

#include <iostream>

using std::cout, std::endl;

template <typename T> class Stack
{
	private:
		struct element 
		{
			T value;
			element* next;
		};
		element* head;
		bool empty;

	public:
		unsigned long long int N_op = 0;

		Stack();
		~Stack();
		void Push(T num);
		T Pop();
		bool Empty();
		int Length();
		bool Sorted();
		T ShowHead();
		void ShowAll();
};
