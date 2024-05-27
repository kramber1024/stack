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
 * @brief Конструктор. Инициализирует класс.
 * 
 * @tparam T Тип данных в стеке.
 */
template <typename T> Stack<T>::Stack() // 1
{
	N_op = 0;
	head = nullptr;                     N_op++;
}

/**
 * @brief Деструктор. Удаляет все элементы стека из памяти.
 * 
 * @tparam T Тип данных в стеке.
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
 * @brief Основной метод. Добавляет новый элемент в стек на верх.
 * 
 * @tparam T Тип данных в стеке.
 * @param num Значение, которое будет храниться в стеке.
 */
template <typename T> void Stack<T>::Push(T num) // 5
{
	element* newElement = new element;           N_op+=2;
	newElement->value = num;                     N_op++;
	newElement->next = head;                     N_op++;
	head = newElement;                           N_op++;
}

/**
 * @brief Основной метод. Удаляет верхний элемент в стеке и возвращает его значение.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` T ` верхнее значение в стеке или ` T `, если стек пуст.
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
 * @brief Основной метод. Возвращает пуст ли стек.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` true ` если стек пуст, в противном случае ` false `.
 */
template <typename T> bool Stack<T>::Empty() // 2
{
	N_op+=2; return head == nullptr;
}

/**
 * @brief Основной метод. Вычисляет длину стека и возвращает её.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` int ` Длину стека.
 */
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

/**
 * @brief Вспомогательный метод.
 * 
 * Проверяет отсортирован ли стек сверху вниз.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` true ` если стек отсортирован сверху вниз, в противном случае ` false `.
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
 * @brief Основной метод.
 * 
 * Возвращает значение верхнего элемента стека.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` T ` верхнее значение в стеке или ` T `, если стек пуст.
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
 * @brief Вспомогательный метод.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` T* ` адрес значения в голове.
 */
template <typename T> T* Stack<T>::GetHead() // 2
{
	N_op+=2; return &(head->value);
}

/**
 * @brief Вспомогательный метод.
 * 
 * Красиво выводит элементы подряд, сверху вниз стека: `1 2 3`.
 * 
 * @tparam T Тип данных в стеке.
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
