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

		Stack();          // 
		~Stack();		  // -
		void Push(T num); // 
        T Pop();          // 
        bool Empty();     // 
		int Length();     // 
		bool Sorted();    // -
		T ShowHead();     // 
		void ShowAll();   // -
		T* GetHead();     // 
};

/**
 * @brief Конструктор. Инициализирует класс.
 * 
 * @tparam T Тип данных в стеке.
 */
template <typename T> Stack<T>::Stack() // 
{
	N_op = 0;
	head = nullptr;
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
template <typename T> void Stack<T>::Push(T num) // 
{
	element* newElement = new element;
	newElement->value = num;
	newElement->next = head;
	head = newElement;
}

/**
 * @brief Основной метод. Удаляет верхний элемент в стеке и возвращает его значение.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` T ` верхнее значение в стеке или ` T `, если стек пуст.
 */
template <typename T> T Stack<T>::Pop() // 
{
	if (Empty())
	{
		return T();
	}

	T value = head->value;
	element* temporaryElement = head;
	head = head->next;
	delete temporaryElement;

	return value;
}

/**
 * @brief Основной метод. Возвращает пуст ли стек.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` true ` если стек пуст, в противном случае ` false `.
 */
template <typename T> bool Stack<T>::Empty() // 2
{
	return head == nullptr;                  // +1 +1
}

/**
 * @brief Основной метод. Вычисляет длину стека и возвращает её.
 * 
 * @tparam T Тип данных в стеке.
 * @return ` int ` Длину стека.
 */
template <typename T> int Stack<T>::Length()       // 2n + 10 
{
	if (Empty())
	{
		return 0;
	}

	int length = 0;                                
	element* temporaryElement = head;              

	while (temporaryElement != nullptr)
	{
		length++;                                  
		temporaryElement = temporaryElement->next; 
	}

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
template <typename T> T Stack<T>::ShowHead() // 
{
	if (Empty())
	{
		return T();
	}
	else
	{
		return head->value;
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
	return &(head->value);
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
