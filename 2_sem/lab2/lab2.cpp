#include <iostream> 
#include <type_traits>
#include <queue.h>

using namespace std;

int displayMenu();

template <typename T>
void insertBeforeNegatives(Queue<T>& queue, bool (*predicate)(const T&) = nullptr)
{
    static_assert(is_arithmetic<T>::value, "T must be an arithmetic type (e.g., int, double)");

    int originalSize = queue.count();  

    for (int i = 0; i < originalSize; ++i)
    {
        T value = queue.unqueue();  

        if (predicate && predicate(value))
        {
            queue.queue(T{ 1 });  
        }
        queue.queue(value);  
    }

    cout << "Завершено добавление 1 перед элементами, удовлетворяющими условию.\n";
}

template <typename T>
void removeNegatives(Queue<T>& queue, bool (*predicate)(const T&) = nullptr)
{
    static_assert(is_arithmetic<T>::value, "T must be an arithmetic type (e.g., int, double)");

    int originalSize = queue.count(); 

    for (int i = 0; i < originalSize; ++i)
    {
        T value = queue.unqueue();  

        if (predicate && !predicate(value)) 
        {
            queue.queue(value);  
        }
    }

    cout << "Удалены все элементы, удовлетворяющие условию.\n";
}

template <typename T>
int countOccurrences(const Queue<T>& queue, T value)
{
    Queue<T> temp = queue;  
    int count = 0;

    while (!temp.isEmpty())
    {
        if (temp.unqueue() == value)  
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    setlocale(LC_ALL, "RUS");

    Queue<int> intQueue;;

    int choice;
    int value;

    do 
    {
        choice = displayMenu();

        switch (choice) 
        {
        case 1:
            int value;
            cout << "Введите число: ";
            cin >> value;
            intQueue.queue(value);
            break;

        case 2:
            try 
            {
                cout << "Извлечено: " << intQueue.unqueue() << endl;
            }
            catch (const out_of_range& e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            cout << "Количество элементов: " << intQueue.count() << endl;
            break;

        case 4:
            intQueue.clear();
            cout << "Очередь очищена.\n";
            break;

        case 5:
            insertBeforeNegatives(intQueue);
            cout << "Вставлены 1 перед отрицательными числами.\n";
            break;

        case 6:
            removeNegatives(intQueue);
            cout << "Удалены все отрицательные числа.\n";
            break;
        case 7:
            cout << "Введите число для подсчета вхождений: ";
            cin >> value;
            cout << "Число " << value << " встречается " << countOccurrences(intQueue, value) << " раз.\n";
            break;
        case 8:
            cout << "Очередь: ";
            intQueue.print();
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

int displayMenu()
{
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