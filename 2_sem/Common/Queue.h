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
    /// ����������� �� ���������.
    /// </summary>
    Queue() = default;

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

    /// <summary>
    /// ��������� ������� �� ��������� 1 ����� ������ �������������� ������ � �������.
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
    /// ������� ��� ������������� ����� �� �������.
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
    /// ������������ ���������� ��������� ���������� �������� � �������.
    /// </summary>
    /// <param name="value">�������� ��� ��������.</param>
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
