#pragma once

#include <iostream>

using std::cout; using std::endl;

/**
 * @brief Стек.
 * 
 * Реализован при помощи односвязнанного списка.
 * 
 * @tparam T Тип данных в стеке.
 */
template <typename T> class Stack
{
	private:
		/**
		 * @brief Элемент односвязнанного списка.
		 */
		struct element 
		{
			T value;
			element* next;
		};
		element* head;
		bool empty;

	public:
		unsigned long long int N_op;

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

/**
 * @brief Конструктор. Инициализирует класс.
 * 
 * @tparam T Тип данных в стеке.
 */
template <typename T> Stack<T>::Stack()
{
	head = new element;
	head->value = 0;
	head->next = 0;
	empty = true;
	N_op = 0;
}

/**
 * @brief Деструктор. Удаляет все элементы стека из памяти.
 * 
 * @tparam T Тип данных в стеке.
 */
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

/**
 * @brief Основной метод. Добавляет новый элемент в стек на верх.
 * 
 * @tparam T Тип данных в стеке.
 * @param num Значение, которое будет храниться в стеке.
 */
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

/**
 * @brief Основной метод. Удаляет верхний элемент в стеке и возвращает его значение.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` T ` верхнее значение в стеке или ` -1 `, если стек пуст.
 */
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

/**
 * @brief Основной метод. Возвращает пуст ли стек.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` true ` если стек пуст, в противном случае ` false `.
 */
template <typename T> bool Stack<T>::Empty()
{
	return empty;
}

/**
 * @brief Основной метод. Вычисляет длину стека и возвращает её.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` int ` Длину стека.
 */
template <typename T> int Stack<T>::Length()
{
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

/**
 * @brief Вспомогательный метод.
 * 
 * Проверяет отсортирован ли стек сверху вниз.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` true ` если стек отсортирован сверху вниз, в противном случае ` false `.
 */
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

/**
 * @brief Основной метод.
 * 
 * Возвращает значение верхнего элемента стека.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` T ` верхнее значение в стеке или ` -1 `, если стек пуст.
 */
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

/**
 * @brief Вспомогательный метод.
 * 
 * Красиво выводит элементы подряд, сверху вниз стека: `1 2 3`.
 * 
 * @tparam T Тип данных в стеке.
 */
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
