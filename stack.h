#ifndef STACK_H
#define STACK_H

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

#endif
