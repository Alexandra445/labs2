#pragma once
#include "node.h"
#include <stdexcept>

/// <summary>
/// Класс `CycleList` реализует структуру данных "односвязный циклический список".
/// Список поддерживает произвольный доступ к элементам и основные операции: добавление, вставку, удаление и очистку.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
template <typename T>
class CycleList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    /// <summary>
    /// Конструктор по умолчанию. Создает пустой список.
    /// </summary>
    CycleList() : head(nullptr), tail(nullptr), size(0)
    {
    }

    /// <summary>
    /// Деструктор. Освобождает всю память, занятую списком.
    /// </summary>
    ~CycleList()
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент в конец списка.
    /// </summary>
    /// <param name="value">Значение для добавления.</param>
    void add(T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (size == 0) 
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        size++;
    }

    /// <summary>
    /// Вставляет элемент в указанную позицию списка.
    /// </summary>
    /// <param name="index">Индекс позиции для вставки (начиная с 0).</param>
    /// <param name="value">Значение для вставки.</param>
    void insert(int index, T value) 
    {
        if (index < 0 || index > size) 
        {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) 
        {
            Node<T>* newNode = new Node<T>(value, head);
            head = newNode;
            if (size == 0) 
            {
                tail = head;
            }
            tail->next = head;
            size++;
        }
        else if (index == size)
        {
            add(value);
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) 
            {
                current = current->next;
            }
            Node<T>* newNode = new Node<T>(value, current->next);
            current->next = newNode;
            size++;
        }
    }

    /// <summary>
    /// Удаляет элемент из указанной позиции списка.
    /// </summary>
    /// <param name="index">Индекс позиции для удаления (начиная с 0).</param>
    void removeAt(int index)
    {
        if (index < 0 || index >= size) 
        {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0)
        {
            Node<T>* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            if (size == 1) 
            {
                head = tail = nullptr;
            }
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) 
            {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = temp->next;
            if (index == size - 1)
            {
                tail = current;
            }
            delete temp;
        }
        size--;
    }

    /// <summary>
    /// Оператор индексации для доступа к элементам списка.
    /// </summary>
    /// <param name="index">Индекс элемента (начиная с 0).</param>
    /// <returns>Ссылка на элемент по указанному индексу.</returns>
    T& operator[](const int index)
    {
        if (index < 0 || index >= size) 
        {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    /// <summary>
    /// Возвращает количество элементов в списке.
    /// </summary>
    /// <returns>Число элементов в списке.</returns>
    int count()
    {
        return size;
    }

    /// <summary>
    /// Подсчитывает количество вхождений указанного значения в список.
    /// </summary>
    /// <param name="value">Значение для поиска.</param>
    /// <returns>Количество найденных вхождений.</returns>
    int count(T value)
    {
        int cnt = 0;
        Node<T>* current = head;
        for (int i = 0; i < size; i++)
        {
            if (current->data == value)
            {
                cnt++;
            }
            current = current->next;
        }
        return cnt;
    }

    /// <summary>
    /// Удаляет все элементы из списка.
    /// </summary>
    void clear() 
    {
        while (size > 0)
        {
            removeAt(0);
        }
    }
};