#pragma once
#include <iostream>
#include "node.h"

using namespace std;

/// <summary>
/// Очередь с использованием шаблонного класса и связного списка.
/// </summary>
template <typename T>
class Queue 
{
private:
    Node<T>* front = nullptr;
    Node<T>* rear = nullptr; 
    int size = 0;

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    Queue() = default;

    /// <summary>
    /// Деструктор для автоматического освобождения памяти.
    /// </summary>
    ~Queue()
    {
        clear();
    }

    /// <summary>
    /// Добавляет новый элемент в конец очереди.
    /// </summary>
    /// <param name="value">Элемент, который нужно добавить.</param>
    void queue(T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (rear) 
        {
            rear->next = newNode;
        }
        else
        {
            front = newNode;
        }
        rear = newNode;
        size++;
    }

    /// <summary>
    /// Удаляет и возвращает элемент из начала очереди.
    /// </summary>
    /// <returns>Удалённое значение.</returns>
    T unqueue() 
    {
        if (!front) 
        {
            throw out_of_range("Queue is empty");
        }
        Node* temp = front;
        T value = temp->data;
        front = front->next;
        if (!front) 
        {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    /// <summary>
    /// Возвращает текущее количество элементов в очереди.
    /// </summary>
    /// <returns>Количество элементов в очереди.</returns>
    int count() const 
    {
        return size;
    }

    /// <summary>
    /// Очищает очередь, удаляя все элементы.
    /// </summary>
    void clear() 
    {
        while (front) 
        {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }

    /// <summary>
    /// Проверяет, является ли очередь пустой.
    /// </summary>
    bool isEmpty() const
    {
        return size == 0;
    }

    /// <summary>
    /// Выводит все элементы очереди на стандартный поток вывода.
    /// </summary>
    void print() const
    {
        Node<T>* temp = front;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /// <summary>
    /// Вставляет элемент со значением 1 перед каждым отррицательным числом в очереди.
    /// </summary>
    void insertBeforeNegatives()
    {
        Node<T>* temp = front;
        Node<T>* prev = nullptr;

        while (temp)
        {
            if (temp->data < 0) 
            {
                Node<T>* newNode = new Node<T>(1);
                if (prev) 
                {
                    prev->next = newNode;
                }
                else 
                {
                    front = newNode;
                }
                newNode->next = temp;
                prev = newNode;
                size++;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    /// <summary>
    /// Удаляет все отрицательные числа из очереди.
    /// </summary>
    void removeNegatives() 
    {
        while (front && front->data < 0) 
        {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
            size--;
        }

        Node<T>* temp = front;
        while (temp && temp->next) 
        {
            if (temp->next->data < 0)
            {
                Node<T>* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
                size--;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (!front) 
        {
            rear = nullptr;
        }
    }

    /// <summary>
    /// Подсчитывает количество вхождений указанного значения в очереди.
    /// </summary>
    /// <param name="value">Значение для подсчёта.</param>
    int countOccurrences(T value) const
    {
        int count = 0;
        Node<T>* temp = front;
        while (temp) 
        {
            if (temp->data == value)
            {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};
