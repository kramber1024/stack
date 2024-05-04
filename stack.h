#pragma once

#include <iostream>


class Stack
{
private:
	struct element 
	{
		int value;
		element* next;
		bool empty = false;
	};
	element* head;

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
