#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Queue 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) 
        {
        }
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) 
    {
    }

    void queue(T value) 
    {
        Node* newNode = new Node(value);
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

    int count() 
    {
        return size;
    }

    void clear() 
    {
        while (front) 
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }

    bool isEmpty() 
    {
        return size == 0;
    }

    void print()
    {
        Node* temp = front;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << std::endl;
    }

    void insertBeforeNegatives()
    {
        Node* temp = front;
        Node* prev = nullptr;

        while (temp)
        {
            if (temp->data < 0) 
            {
                Node* newNode = new Node(1);
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

    void removeNegatives() 
    {
        while (front && front->data < 0) 
        {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }

        Node* temp = front;
        while (temp && temp->next) 
        {
            if (temp->next->data < 0)
            {
                Node* delNode = temp->next;
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

    int countOccurrences(T value) 
    {
        int count = 0;
        Node* temp = front;
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
