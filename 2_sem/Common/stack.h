#pragma once

#include <exception>

template <typename T>
class Stack {
private:
    struct Node {
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
    Stack()
        : top(nullptr)
        , capacity(0)
    {}

    ~Stack() {
        clear();
    }

    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        capacity++;
    }

    T pop() {
        if (top == nullptr) {
            throw std::runtime_error("Stack is empty!");
        }
        Node* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        capacity--;
        return value;
    }

    T peek() {
        if (top == nullptr) {
            throw std::runtime_error("Stack is empty!");
        }
        return top->data;
    }

    int count() {
        return capacity;
    }

    void clear() {
        while (top != nullptr) {
            pop();
        }
    }
};