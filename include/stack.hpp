#pragma once

#include <iostream>

using std::cout, std::endl;

/**
 * @class Stack
 * @brief A template class representing a Stack data structure implemented using a linked list.
 *
 * This class provides the functionality to store and manipulate elements in a stack.
 * The stack follows the LIFO principle.
 * 
 * The stack is implemented using a linked list, where each element in the stack
 * is represented by a element containing the value and a pointer to the next element.
 * The head pointer points to the top of the stack.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T> class Stack
{
private:
	/**
	 * @brief Represents an element in a stack.
	 *
	 * This struct holds the value of the element and a pointer to the next element in the stack.
	 */
	struct element 
	{
		T value; /** The value of the element. */
		element* next; /** Pointer to the next element in the stack. */
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

/**
 * @brief Constructs an empty Stack object.
 *
 * This constructor initializes the Stack object by setting the number of operations (N_op) to 0
 * and the head pointer to nullptr.
 * 
 * @tparam T The type of elements stored in the Stack.
 */
template <typename T> Stack<T>::Stack() // 1
{
	N_op = 0;
	head = nullptr;                     N_op++;
}

/**
 * @brief Destructor for the Stack class.
 * 
 * This destructor is responsible for deallocating the memory used by the Stack.
 * It iterates through the linked list and deletes each element.
 * 
 * @tparam T The type of elements stored in the Stack.
 */
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

/**
 * @brief Pushes a new element onto the stack.
 * 
 * This method creates a new element and adds it to the top of the stack.
 * The value of the new element is set to the given number.
 * 
 * @tparam T The type of elements stored in the stack.
 * @param num The number to be added to the stack.
 */
template <typename T> void Stack<T>::Push(T num) // 5
{
	element* newElement = new element;           N_op+=2;
	newElement->value = num;                     N_op++;
	newElement->next = head;                     N_op++;
	head = newElement;                           N_op++;
}

/**
 * @brief Removes and returns the top element from the stack.
 * 
 * This method removes and returns the top element from the stack.
 * If the stack is empty, it returns a default-constructed object of type T.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return T The top element of the stack.
 */
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

/**
 * @brief Returns whether the stack is empty or not.
 * 
 * This method check if head is nullptr.
 * If it is, the stack is empty and the method returns true.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return int The number of elements in the stack.
 */
template <typename T> bool Stack<T>::Empty() // 2
{
	N_op+=2; return head == nullptr;
}

/**
 * @brief Returns the number of elements in the stack.
 * 
 * This method counts the number of elements in the stack by iterating through
 * the linked list and incrementing a counter for each element encountered.
 * If the stack is empty, it returns 0.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return int The number of elements in the stack.
 */
template <typename T> int Stack<T>::Length() // 2n + 10
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

/**
 * @brief Checks if the elements in the stack are sorted in ascending order.
 * 
 * This method iterates through the elements in the stack and compares each element
 * with the next element. If any element is greater than the next element, the stack
 * is considered unsorted and the method returns false. If all elements are in ascending
 * order or the stack is empty, the method returns true.
 * 
 * @tparam T The type of elements stored in the stack.
 * @return true if the elements are sorted in ascending order or the stack is empty, false otherwise.
 */
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
template <typename T> T Stack<T>::ShowHead() // 4
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
 * If the stack is empty, it returns a nullptr.
 * This method is used for overloading operator[].
 * 
 * @tparam T The type of elements stored in the stack.
 * @return T* A pointer to the value stored in the head element of the stack.
 */
template <typename T> T* Stack<T>::GetHead() // 2
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
template <typename T> void Stack<T>::ShowAll() // -
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