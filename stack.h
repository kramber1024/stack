#pragma once

#include <iostream>


class Stack
{
private:
	struct element 
	{
		int value;
		element* next;
	};
	element* head;
	bool empty;

public:
	unsigned long long int N_op = 0;

	Stack();
	~Stack();
	void Push(int num);
	int Pop();
	bool Empty();
	int Length();
    bool Sorted();
	int ShowHead();
	void ShowAll();
};
