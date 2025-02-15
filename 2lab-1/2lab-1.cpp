#include <iostream>

#include "stack.h"

using namespace std;

// Точка входа в программу, где есть чтение и вывод чисел
int main() {
    Stack<int> stack;
    int number;
    setlocale(LC_ALL, "RUS");
    cout << "Введите последовательность чисел (для завершения введите 0):" << endl;

    // Чтение чисел, пока не встречен 0
    while (true) {
        cout << "Введите число: ";
        cin >> number;

        // Завершаем ввод, если число 0
        if (number == 0) {
            break;
        }

        stack.push(number);  // Добавляем число в стек
    }

    // Вывод положительных чисел в обратном порядке
    cout << "Положительные числа в обратном порядке:" << endl;
    while (stack.count() > 0) {
        int value = stack.pop();
        if (value > 0) {
            cout << value << " ";  // Выводим только положительные
        }
    }
    cout << endl;

    return 0;
}