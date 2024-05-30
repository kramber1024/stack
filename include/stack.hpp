#pragma once

#include <iostream>

using std::cout; using std::endl;

template <typename T> class Stack
{
private:
	struct element 
	{
		T value;
		element* next;
	};
	element* head;

public:
	unsigned long long int N_op;

	Stack();          // 1
	~Stack();		  // -
	void Push(T num); // 5
	T Pop();          // 10 
	bool Empty();     // 2
	int Length();     // 2n + 10
	T ShowHead();     // 4
	T* GetHead();     // 2
	bool Sorted();    // -
	void ShowAll();   // -
};


template <typename T> Stack<T>::Stack() // 1
{
	N_op = 0;
	head = nullptr;                     N_op++;
}


template <typename T> Stack<T>::~Stack() // -
{
	if (!Empty())
	{
		element* temporaryElement = nullptr;

		while (head->next != nullptr)
		{
			temporaryElement = head;
			head = head->next;
			delete temporaryElement;
		}
	}
	delete head;
}


template <typename T> void Stack<T>::Push(T num) // 5
{
	element* newElement = new element;           N_op+=2;
	newElement->value = num;                     N_op++;
	newElement->next = head;                     N_op++;
	head = newElement;                           N_op++;
}


template <typename T> T Stack<T>::Pop() // 10
{
	N_op++;
	if (Empty())           
	{
		N_op++; return T();
	}

	T value = head->value;              N_op+=2;
	element* temporaryElement = head;   N_op+=2;
	head = head->next;                  N_op++;
	delete temporaryElement;            N_op++;

	N_op++; return value;
}


template <typename T> bool Stack<T>::Empty() // 2
{
	N_op+=2; return head == nullptr;
}


template <typename T> int Stack<T>::Length()       // 2n + 10
{
	N_op++;
	if (Empty())
	{
		N_op++; return 0;
	}

	int length = 0;                                N_op+=2;
	element* temporaryElement = head;              N_op+=2;

	N_op++;
	while (temporaryElement != nullptr)
	{
		N_op++;
		length++;                                  N_op++;
		temporaryElement = temporaryElement->next; N_op++;
	}

	N_op++; return length;
}


template <typename T> bool Stack<T>::Sorted() // -
{
	if (Empty()) {
		return true;
	}
	
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

/**
 * @brief Returns the value stored in the head element of the stack.
 * 
 * This method returns the value stored in the head element of the stack.
 * If the stack is empty, it returns a default-constructed value of type T.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return T The value stored in the head element of the stack.
 */
template <typename T> T Stack<T>::ShowHead()
{
	N_op++;
	if (Empty())
	{
		N_op++; return T();
	}
	else
	{
		N_op++; return head->value;
	}
}

/**
 * @brief Returns a pointer to the value stored in the head element of the stack.
 * 
 * This method returns a pointer to the value stored in the head element of the stack.
 * This method is used for overloading operator[].
 * If the stack is empty, it returns a nullptr.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return T* A pointer to the value stored in the head element of the stack.
 */
template <typename T> T* Stack<T>::GetHead()
{
	N_op += 2; return &(head->value);
}

/**
 * @brief Displays all the elements in the stack.
 * 
 * This method iterates through the stack and prints each element's value.
 * For example: `1 2 3`.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T> void Stack<T>::ShowAll()
{
	if (Empty())
	{
		cout << endl;
	}
	else
	{
		element* temporaryElement = head;

		while (temporaryElement->next != nullptr)
		{
			cout << temporaryElement->value << " ";
			temporaryElement = temporaryElement->next;
		}
		cout << temporaryElement->value << endl;
	}
}