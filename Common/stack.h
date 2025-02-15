#pragma once

#include <iostream>

// Шаблонная структура данных Stack
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val)
            : data(val)
            , next(nullptr)
        {}
    };

    Node* top;  // Указатель на верхний элемент стека
    int size;    // Размер стека

public:
    // Конструктор
    Stack()
        : top(nullptr)
        , size(0)
    {}

    // Деструктор
    ~Stack() {
        clear();
    }

    // Добавление элемента на вершину стека
    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Извлечение элемента с вершины стека
    T pop() {
        if (top == nullptr) {
            throw std::runtime_error("Stack is empty!");
        }
        Node* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        size--;
        return value;
    }

    // Возвращение элемента на вершине стека, не удаляя его
    T peek() {
        if (top == nullptr) {
            throw std::runtime_error("Stack is empty!");
        }
        return top->data;
    }

    // Возвращение количества элементов в стеке
    int count() {
        return size;
    }

    // Очистка стека
    void clear() {
        while (top != nullptr) {
            pop();
        }
    }
};