#pragma once
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
    /// Конструктор по умолчанию  с использованием списка инициализации.
    /// </summary>
    Queue() : front(nullptr), rear(nullptr), size(0) 
    {
    }

    /// <summary>
    // Конструктор копирования
    /// </summary>
    Queue(const Queue& other)
    {
        Node<T>* temp = other.front;
        while (temp)
        {
            queue(temp->data);  
            temp = temp->next;
        }
    }

    /// <summary>
    // Оператор присваивания
    /// </summary>
    Queue& operator=(const Queue& other)
    {
        if (this != &other)  
        {
            clear();  
            Node<T>* temp = other.front;
            while (temp)
            {
                queue(temp->data); 
                temp = temp->next;
            }
        }
        return *this;
    }

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
        Node<T>* temp = front; 
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
        while (!isEmpty())
        {
            unqueue();
        }
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
};
