#pragma once
#include <iostream>
#include "node.h"
using namespace std;

/// <summary>
/// ������� � �������������� ���������� ������ � �������� ������.
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
    /// ����������� �� ���������  � �������������� ������ �������������.
    /// </summary>
    Queue() : front(nullptr), rear(nullptr), size(0) 
    {
    }

    /// <summary>
    /// ���������� ��� ��������������� ������������ ������.
    /// </summary>
    ~Queue()
    {
        clear();
    }

    /// <summary>
    /// ��������� ����� ������� � ����� �������.
    /// </summary>
    /// <param name="value">�������, ������� ����� ��������.</param>
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
    /// ������� � ���������� ������� �� ������ �������.
    /// </summary>
    /// <returns>�������� ��������.</returns>
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
    /// ���������� ������� ���������� ��������� � �������.
    /// </summary>
    /// <returns>���������� ��������� � �������.</returns>
    int count() const 
    {
        return size;
    }

    /// <summary>
    /// ������� �������, ������ ��� ��������.
    /// </summary>
    void clear() 
    {
        while (!isEmpty())
        {
            unqueue();
        }
    }

    /// <summary>
    /// ���������, �������� �� ������� ������.
    /// </summary>
    bool isEmpty() const
    {
        return size == 0;
    }

    /// <summary>
    /// ������� ��� �������� ������� �� ����������� ����� ������.
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
