#include "stack.h"

using namespace std;


Stack::Stack()
{
	head = new element;
	head->value = 0;
	head->next = 0;
	empty = true;
}

Stack::~Stack()
{
	if (!Empty())
	{
		element* temporaryElement;

		while (head->next != 0)
		{
			temporaryElement = head;
			head = head->next;
			delete temporaryElement;
		}
	}
	delete head;
}

void Stack::Push(int num)
{
	element* newElement = new element;
	newElement->next = 0;
	newElement->value = num;
	
	if (empty)
	{
		head = newElement;
		empty = false;
	}
	else
	{
		newElement->next = head;
		head = newElement;
	}
}

int Stack::Pop()
{
	if (Empty())
	{
		return -1;
	}
	int length = Length();

	int value = head->value;
	element* temporaryElement = head;
	head = head->next;
	delete temporaryElement;

	if (length == 1)
	{
		empty = true;
	}

	return value;
}

bool Stack::Empty()
{
	return empty;
}

int Stack::Length() {
	if (Empty())
	{
		return 0;
	}

	int length = 0;
	element* temporaryElement = head;

	while (temporaryElement->next != 0)
	{
		temporaryElement = temporaryElement->next;
		length++;
	}
	length++;

	return length;
}

bool Stack::Sorted()
{
	element* temporaryElement = head;
    int lastValue = head->value;

	while (temporaryElement->next != 0)
	{
		temporaryElement = temporaryElement->next;
		if (lastValue > temporaryElement->value)
		{
			return false;
		}
		lastValue = temporaryElement->value;
	}

	return true;
}

int Stack::ShowHead()
{
	if (Empty())
	{
		return -1;
	}
	else
	{
		return head->value;
	}
}

void Stack::ShowAll()
{
	if (!Empty())
	{
		element* temporaryElement = head;

		while (temporaryElement->next != 0)
		{
			cout << temporaryElement->value << " ";
			temporaryElement = temporaryElement->next;
		}
		cout << temporaryElement->value << endl;
	}
}
