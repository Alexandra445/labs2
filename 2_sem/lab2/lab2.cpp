#include <iostream> 
#include <queue.h>

using namespace std;

int displayMenu() {
    int choice;
    cout << "\nМеню:\n";
    cout << "1. Добавить элемент в очередь\n";
    cout << "2. Извлечь элемент из очереди\n";
    cout << "3. Показать количество элементов\n";
    cout << "4. Очистить очередь\n";
    cout << "5. Вставить 1 перед каждым отрицательным числом\n";
    cout << "6. Удалить все отрицательные числа\n";
    cout << "7. Подсчитать вхождения числа\n";
    cout << "8. Вывести очередь\n";
    cout << "9. Выйти\n";
    cout << "Выберите действие: ";
    cin >> choice;
    return choice;
}

template <typename T>
void insertBeforeNegatives(Queue<T>& q) {
    Queue<T> newQueue; 
    while (!q.isEmpty()) {
        T value = q.unqueue();
        if (value < 0) {
            newQueue.queue(1);
        }
        newQueue.queue(value);
    }
    while (!newQueue.isEmpty()) {
        q.queue(newQueue.unqueue());
    }
    cout << "Вставлены 1 перед отрицательными числами.\n";
}

template <typename T>
void removeNegatives(Queue<T>& q) {
    Queue<T> newQueue; 
    while (!q.isEmpty()) {
        T value = q.unqueue();
        if (value >= 0) {
            newQueue.queue(value); 
        }
    }
    while (!newQueue.isEmpty()) {
        q.queue(newQueue.unqueue());
    }
    cout << "Удалены все отрицательные числа.\n";
}

template <typename T>
int countOccurrences(const Queue<T>& q, T value) {
    Queue<T> temp = q; 
    int count = 0;
    while (!temp.isEmpty()) {
        if (temp.unqueue() == value) {
            count++;
        }
    }
    return count;
}

int main() 
{
    setlocale(LC_ALL, "RUS");

    Queue<int> q;

    int choice, value;

    do 
    {
        choice = displayMenu();

        switch (choice) 
        {
        case 1:
            cout << "Введите число: ";
            cin >> value;
            q.queue(value);
            break;

        case 2:
            try 
            {
                cout << "Извлечено: " << q.unqueue() << endl;
            }
            catch (const out_of_range& e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            cout << "Количество элементов: " << q.count() << endl;
            break;

        case 4:
            q.clear();
            cout << "Очередь очищена.\n";
            break;

        case 5:
            insertBeforeNegatives(q);
            cout << "Вставлены 1 перед отрицательными числами.\n";
            break;

        case 6:
            removeNegatives(q);
            cout << "Удалены все отрицательные числа.\n";
            break;

        case 7:
            cout << "Введите число для подсчета вхождений: ";
            cin >> value;
            cout << "Число " << value << " встречается " << countOccurrences(q,value) << " раз.\n";
            break;

        case 8:
            cout << "Очередь: ";
            q.print();
            break;

        case 9:
            cout << "Выход...\n";
            break;

        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }
    while (choice != 9);

    return 0;
}