#include "stack.h"

using namespace std;


Stack::Stack()
{
	head = new element;
	head->value = 0;
	head->next = 0;
	head->empty = true;
}

Stack::~Stack()
{
	element* temporaryElement;
	while (head->next != 0)
	{
		temporaryElement = head;
		head = head->next;
		delete temporaryElement;
	}
	delete head;
}

void Stack::Push(int num)
{
	element* newElement = new element;
	newElement->next = 0;
	newElement->value = num;
	
	if (head->empty)
	{
		head = newElement;
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

	element* temporaryElement = head;
	int value = temporaryElement->value;
	head = head->next;
	delete temporaryElement;

	return value;
}

bool Stack::Empty()
{
	if (head->empty)
	{
		return true;
	}
	return false;
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
	element* temporaryElement = head;

	while (temporaryElement->next != 0)
	{
		cout << temporaryElement->value << " ";
		temporaryElement = temporaryElement->next;
	}
	cout << temporaryElement->value << endl;
}
