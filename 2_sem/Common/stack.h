#pragma once
#include <exception>

using namespace std; 

/// <summary>
/// Класс для работы со стеком (LIFO - последний вошел, первый вышел).
/// </summary>
/// <typeparam name="T">Тип данных, который будет храниться в стеке.
template <typename T>
class Stack
{
private:
    /// <summary>
    /// Элемент стека, который хранит данные и ссылку на следующий элемент.
    /// </summary>
    struct Node 
    {
        T data;
        Node* next;
        Node(T val)
            : data(val)
            , next(nullptr)
        {
        }
    };

    Node* top;
    int capacity;

public:
    /// <summary>
    /// Конструктор стека. Создает пустой стек.
    /// </summary>
    Stack()
        : top(nullptr)
        , capacity(0)
    {
    }

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
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        capacity++;
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
        Node* temp = top;         
        top = top->next;
        T data = temp->data;
        delete temp;   
        capacity--;
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
        return capacity;
    }

    /// <summary>
    /// Удаляет все элементы из стека.
    /// </summary>
    void clear()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        capacity = 0; 
    }
};