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
        T Get(int pos);           // 35n + 26
        void Set(int pos, T num); // 35n + 34
        T& operator[](int n);     // 35n + 25
        void Sort(int n);         // n^2
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
template <typename T> T MyStack<T>::Get(int pos) // 35n + 26
{
    Stack<T> temporaryStack;                     this->N_op++;

    this->N_op+=3;
    for (int i = 0; i < pos; i++)
    {
        this->N_op+=2;
        temporaryStack.Push(this->Pop());
    }

    T result = this->ShowHead();                 this->N_op+=2;

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
template <typename T> void MyStack<T>::Set(int pos, T num) // 35n + 34
{
    Stack<T> temporaryStack;                               this->N_op++;

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

template <typename T> T& MyStack<T>::operator[](int n) // 35n + 25
{
    Stack<T> temporaryStack;                           this->N_op+=2;

    this->N_op+=3;
    for (int i = 0; i < n; i++)
    {
        this->N_op+=2;
        temporaryStack.Push(this->Pop());
    }

    T* valueAddress = this->GetHead();                 this->N_op+=2;

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
 * @brief Сортирует значения в стеке алгоритмом Шелла.
 * 
 * После сортировки самые большие значения будут внизу стека: `1 2 3`.
 * 
 * @tparam T Тип данных в стеке.
 * @param n Длина стека. Необходим для асимптотической оценка алгоритма.
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
            int j;                                                 this->N_op++;
            T temp = Get(i);                                       this->N_op+=2;

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
