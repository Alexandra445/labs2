#include <iostream>

#include <stack.h>

using namespace std; 

int main() {
    setlocale(LC_ALL, "RUS");

    Stack<int> stack;
    int number;

    cout << "Введите последовательность чисел (для завершения введите 0):" << endl;
     
    while (true) {
        cout << "Введите число: ";
        cin >> number;
         
        if (number == 0) {
            break;
        }

        stack.push(number);  
    }
     
    cout << "Положительные числа в обратном порядке:" << endl;
    while (stack.count() > 0) {
        int value = stack.pop();
        if (value > 0) {
            cout << value << " ";  
        }
    }
    cout << endl;

    return 0;
}
