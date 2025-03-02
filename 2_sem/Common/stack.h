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
    };

    Node(T val, Node* nextNode) : data(val), next(nextNode)
    {
    }

    Node* top = nullptr;
    int size = 0;

public:
    /// <summary>
    /// ����������� �� ���������.
    /// </summary>
    Stack() = default;

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
        top = new Node(value, top);
        size++;
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
        size--;
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
        return size;
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
        size = 0; 
    }
};