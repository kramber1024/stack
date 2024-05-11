#include "stack.h"

template <typename T> Stack<T>::Stack()
{
	head = new element;
	head->value = 0;
	head->next = 0;
	empty = true;
}

template <typename T> Stack<T>::~Stack()
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

template <typename T> void Stack<T>::Push(T num)
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

template <typename T> T Stack<T>::Pop()
{
	if (Empty())
	{
		return -1;
	}
	int length = Length();

	T value = head->value;
	element* temporaryElement = head;
	head = head->next;
	delete temporaryElement;

	if (length == 1)
	{
		empty = true;
	}

	return value;
}

template <typename T> bool Stack<T>::Empty()
{
	return empty;
}

template <typename T> int Stack<T>::Length() {
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

template <typename T> bool Stack<T>::Sorted()
{
	element* temporaryElement = head;
    T lastValue = head->value;

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

template <typename T> T Stack<T>::ShowHead()
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

template <typename T> void Stack<T>::ShowAll()
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
