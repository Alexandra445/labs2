#pragma once
#include <exception>

using namespace std; 

/// <summary>
/// ����� ��� ������ �� ������ (LIFO - ��������� �����, ������ �����).
/// </summary>
/// <typeparam name="T">��� ������, ������� ����� ��������� � �����.
template <typename T>
class Stack
{
private:
    /// <summary>
    /// ������� �����, ������� ������ ������ � ������ �� ��������� �������.
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
    /// ����������� �����. ������� ������ ����.
    /// </summary>
    Stack()
        : top(nullptr)
        , capacity(0)
    {
    }

    /// <summary>
    /// ����������. ������� ��� �������� �� �����.
    /// </summary>
    ~Stack()
    {
        clear();
    }

   /// <summary>
   /// ��������� ������� �� ������� �����.
   /// </summary>
    void push(T value) 
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        capacity++;
    } 

   /// <summary>
  /// ������� ������� ������� �� ����� � ���������� ��� ��������.
  /// </summary>
  /// <returns>�������� �������� ��������.</returns>
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
    /// ���������� �������� �������� �������� ��� �������� �� �����.
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
    /// ���������� ���������� ��������� � �����.
    /// </summary>
    int count()
    {
        return capacity;
    }

    /// <summary>
    /// ������� ��� �������� �� �����.
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