#pragma once

#include "stack.hpp"

/**
 * @class MyStack
 * @brief A template class representing a Stack with extended functionality.
 *
 * This class provides the functionality manipulate elements in a stack
 * with setters and getter methods, and a sorting method.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T> class MyStack : public Stack<T>
{
public:
	T Get(int pos);		      // 35n + 26
	void Set(int pos, T num); // 35n + 34
	T& operator[](int n);	  // 35n + 25
	void Sort(int n);		  // n^2
};

/**
 * @brief Retrieves the element at the specified position in the stack.
 * 
 * This method retrieves the element at the specified position in the stack.
 * The position is zero-based, so the first element is at position 0, the second
 * element is at position 1, and so on.
 * 
 * @tparam T The type of elements stored in the stack.
 * @param pos The position of the element to retrieve.
 * @return The element at the specified position.
 */
template <typename T> T MyStack<T>::Get(int pos) // 35n + 26
{
	Stack<T> temporaryStack;					 this->N_op++;

	this->N_op+=3;
	for (int i = 0; i < pos; i++)
	{
		this->N_op+=2;
		temporaryStack.Push(this->Pop());
	}

	T result = this->ShowHead();				 this->N_op+=2;

	this->N_op+=3;
	for (int i = 0; i < pos; i++)
	{
		this->N_op+=2;
		this->Push(temporaryStack.Pop());
	}

	this->N_op+=temporaryStack.N_op+1;
	return result;
}

/**
 * @brief Replaces the value in the stack at the given position, counting from the top of the stack.
 * 
 * To change the value at the specified position, the main stack is disassembled into a temporary stack.
 * After changing the value, the stack is reassembled from the temporary stack.
 * `This method is unsafe as it lacks input parameter checks`.
 * 
 * @tparam T The type of elements stored in the stack.
 * @param pos The position at which the value will be changed.
 * @param num The new value.
 */
template <typename T> void MyStack<T>::Set(int pos, T num) // 35n + 34
{
	Stack<T> temporaryStack;							   this->N_op++;

	this->N_op+=3;
	for (int i = 0; i < pos; i++)
	{
		this->N_op+=2;
		temporaryStack.Push(this->Pop());
	}

	this->Pop();
	this->Push(num);

	this->N_op+=3;
	for (int i = 0; i < pos; i++)
	{
		this->N_op+=2;
		this->Push(temporaryStack.Pop());
	}
	this->N_op+=temporaryStack.N_op;
}

/**
 * @brief Overloaded subscript operator to access elements in the stack.
 * @param n The index of the element to access.
 * @return A reference to the element at the specified index.
 */
template <typename T> T& MyStack<T>::operator[](int n) // 35n + 25
{
	Stack<T> temporaryStack;						   this->N_op+=2;

	this->N_op+=3;
	for (int i = 0; i < n; i++)
	{
		this->N_op+=2;
		temporaryStack.Push(this->Pop());
	}

	T* valueAddress = this->GetHead();				    this->N_op+=2;

	this->N_op+=3;
	for (int i = 0; i < n; i++)
	{
		this->N_op+=2;
		this->Push(temporaryStack.Pop());
	}

	this->N_op+=temporaryStack.N_op+2;
	return *valueAddress;
}

/**
 * @brief Sorts the elements in the stack using the Shell sort algorithm.
 * 
 * The Shell sort algorithm is used to sort the elements in the stack in ascending order.
 * It has a time complexity of O(n^2).
 * 
 * @param n The number of elements in the stack.
 */
template <typename T> void MyStack<T>::Sort(int n) // n^2				  
{
	this->N_op+=3;
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		this->N_op+=5;
		for (int i = gap; i < n; i += 1)
		{
			this->N_op+=2;
			int j;								   this->N_op++;
			T temp = Get(i);					   this->N_op+=2;

			this->N_op+=5;
			for (j = i; j >= gap && Get(j - gap) > temp; j -= gap)
			{
				this->N_op+=5;
				Set(j, Get(j - gap));
			}				

			Set(j, temp);
		}
	}
}