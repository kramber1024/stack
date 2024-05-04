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
	Stack();
	~Stack();
	void Push(int num);
	int Pop();
	bool Empty();
	int Length();
	int ShowHead();
	void ShowAll();
};
