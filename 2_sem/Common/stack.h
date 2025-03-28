﻿#pragma once

#include <stdexcept>
#include "node.h"

using namespace std;

/// <summary>
/// Класс для работы со стеком (LIFO - последний вошел, первый вышел).
/// </summary>
/// <typeparam name="T">Тип данных, который будет храниться в стеке.
template <typename T>
class Stack
{
private:
    Node<T>* top = nullptr;
    int size = 0;

public:
    /// <summary>
    /// Конструктор по умолчанию
    /// </summary>
    Stack() = default;

    /// <summary>
    /// Деструктор. Удаляет все элементы из стека.
    /// </summary>
    ~Stack()
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент на вершину стека.
    /// </summary>
    void push(T value)
    {
        top = new Node<T>(value, top);
        size++;
    }

    /// <summary>
   /// Удаляет верхний элемент из стека и возвращает его значение.
   /// </summary>
   /// <returns>Значение верхнего элемента.</returns>
    T pop()
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty!");
        }
        Node<T>* temp = top;
        top = top->next;
        T data = temp->data;
        delete temp;
        size--;
        return data;
    }

    /// <summary>
    /// Возвращает значение верхнего элемента без удаления из стека.
    /// </summary>
    T peek()
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty!");
        }
        return top->data;
    }

    /// <summary>
    /// Возвращает количество элементов в стеке.
    /// </summary>
    int count()
    {
        return size;
    }

    /// <summary>
    /// Удаляет все элементы из стека.
    /// </summary>
    void clear()
    {
        while (top != nullptr)
        {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
};