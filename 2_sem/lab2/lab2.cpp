#include <iostream> 
#include <Queue.h>

using namespace std;

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
            q.insertBeforeNegatives();
            cout << "Вставлены 1 перед отрицательными числами.\n";
            break;

        case 6:
            q.removeNegatives();
            cout << "Удалены все отрицательные числа.\n";
            break;

        case 7:
            cout << "Введите число для подсчета вхождений: ";
            cin >> value;
            cout << "Число " << value << " встречается " << q.countOccurrences(value) << " раз.\n";
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