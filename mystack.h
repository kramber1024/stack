#pragma once

#include "stack.h"

/**
 * @brief Стек с расширенными возможностями.
 * 
 * Унаследован от Stack.
 * 
 * @tparam T Тип данных в стеке.
 */
template <typename T> class MyStack : public Stack<T>
{
    public:
        T Get(int pos);
        void Set(int pos, T num);
        void Sort(int n);
        T& operator[](int n);
};

/**
 * @brief Возвращает значение из стека по позиции, считая с верха стека.
 * 
 * Чтобы получить значение по позиции, основной стек "разбирается" в вспомогательный.
 * После получения значения стек "собирается" обратно из вспомогательного.
 * `Метод небезопасен, так как отсутствуют проверки на входной параметр`.
 * 
 * @tparam T Тип данных в стеке.
 * @param pos Позиция, с которой будет читаться значение.
 * @return T Значение, находящиеся на позиции.
 */
template <typename T> T MyStack<T>::Get(int pos)
{
    Stack<T> temporaryStack;

    for (int i = 0; i < pos; i++)
    {
        temporaryStack.Push(this->Pop());
    }

    T result = this->ShowHead();

    for (int i = 0; i < pos; i++)
    {
        this->Push(temporaryStack.Pop());
    }

    return result;
}

/**
 * @brief Заменяет значение в стека по позиции, считая с верха стека.
 * 
 * Чтобы изменить значение по позиции, основной стек "разбирается" в вспомогательный.
 * После изменения значения стек "собирается" обратно из вспомогательного.
 * `Метод небезопасен, так как отсутствуют проверки на входной параметр`.
 * 
 * @tparam T Тип данных в стеке.
 * @param pos Позиция, на которой будет изменено значение.
 * @param num Новое значение.
 */
template <typename T> void MyStack<T>::Set(int pos, T num)
{
    Stack<T> temporaryStack;

    for (int i = 0; i < pos; i++)
    {
        temporaryStack.Push(this->Pop());
    }

    this->Pop();
    this->Push(num);

    for (int i = 0; i < pos; i++)
    {
        this->Push(temporaryStack.Pop());
    }
}

template <typename T> T& MyStack<T>::operator[](int n)
{
    Stack<T> temporaryStack;

    for (int i = 0; i < n; i++)
    {
        temporaryStack.Push(this->Pop());
    }

    T* valueAddress = this->GetHead();

    for (int i = 0; i < n; i++)
    {
        this->Push(temporaryStack.Pop());
    }

    return *valueAddress;
}

/**
 * @brief Сортирует значения в стеке алгоритмом Шелла.
 * 
 * После сортировки самые большие значения будут внизу стека: `1 2 3`.
 * 
 * @tparam T Тип данных в стеке.
 * @param n Длина стека. Необходим для асимптотической оценка алгоритма.
 */
template <typename T> void MyStack<T>::Sort(int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int j;
            T temp = Get(i);

            for (j = i; j >= gap && Get(j - gap) > temp; j -= gap)
            {
                Set(j, Get(j - gap));
            }                

            Set(j, temp);
        }
    }
}
