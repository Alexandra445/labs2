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
    Node<T>* tail;
    int size;

   /// <summary>
   /// Возвращает узел списка по указанному индексу.
   /// </summary>  
    Node<T>* getNode(int index) const 
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");

        Node<T>* current = tail->next;
        for (int i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        return current;
    }
   

public:
    /// <summary>
    /// Конструктор по умолчанию. Создает пустой список.
    /// </summary>
    CycleList() : tail(nullptr), size(0)
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
   /// Возвращает указатель на головной узел циклического списка.
   /// </summary>
    Node<T>* head() const 
    {
        return tail ? tail->next : nullptr;
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
            tail = newNode;
            tail->next = tail;
        }
        else 
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
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
            throw std::out_of_range("Index out of range");

        if (index == 0) 
        {
            Node<T>* newNode = new Node<T>(value, tail ? tail->next : nullptr);
            if (size == 0) 
            {
                tail = newNode;
                tail->next = tail;
            }
            else
            {
                newNode->next = tail->next;
                tail->next = newNode;
            }
            size++;
            return;
        }

        if (index == size) 
{
            add(value);
            return;
        }

        Node<T>* prev = getNode(index - 1);
        prev->next = new Node<T>(value, prev->next);
        size++;
    }


    /// <summary>
    /// Удаляет элемент из указанной позиции списка.
    /// </summary>
    /// <param name="index">Индекс позиции для удаления (начиная с 0).</param>
    void removeAt(int index)
    {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");

        if (index == 0) 
        {
            Node<T>* temp = tail->next;
            if (size == 1)
            {
                tail = nullptr;
            }
            else
            {
                tail->next = temp->next;
            }
            delete temp;
        }
        else
        {
            Node<T>* prev = getNode(index - 1);
            Node<T>* temp = prev->next;
            prev->next = temp->next;
            if (index == size - 1)
            {
                tail = prev;
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
        return getNode(index)->data;
    }

    /// <summary>
    /// Возвращает количество элементов в списке.
    /// </summary>
    /// <returns>Число элементов в списке.</returns>
    int count() const
    {
        return size;
    }

    /// <summary>
    /// Подсчитывает количество вхождений указанного значения в список.
    /// </summary>
    /// <param name="value">Значение для поиска.</param>
    /// <returns>Количество найденных вхождений.</returns>
    int count(T value) const
    {
        if (size == 0) return 0;
        int count = 0;
        Node<T>* current = head();
        for (int i = 0; i < size; i++)
        {
            if (current->data == value) count++;
            current = current->next;
        }
        return count;
    }
   
    /// <summary>
    /// Удаляет все элементы из списка.
    /// </summary>
    //
    void clear() 
    {
        while (size > 0)
        {
            removeAt(0);
        }
    }
};