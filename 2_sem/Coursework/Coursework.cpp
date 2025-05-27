#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#define NOMINMAX
#include <Windows.h>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_GRADES = 5;

struct Student 
{
    char fio[51];
    int groupNumber;
    int grades[MAX_GRADES];
    double stipend;
    char additionalInfo[51];
};

void addStudent(Student students[], int& count);
void displayStudents(const Student students[], int count);
void editStudent(Student students[], int count);
void deleteStudent(Student students[], int& count);
void deleteGroup(Student students[], int& count);
void saveToFile(const Student students[], int count);
void loadFromFile(Student students[], int& count);
void displayGroupsByCondition(const Student students[], int count, double threshold);
void menu();

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, studentCount);
            break;
        case 2:
            displayStudents(students, studentCount);
            break;
        case 3:
            editStudent(students, studentCount);
            break;
        case 4:
            deleteStudent(students, studentCount);
            break;
        case 5:
            deleteGroup(students, studentCount);
            break;
        case 6:
            saveToFile(students, studentCount);
            break;
        case 7:
            loadFromFile(students, studentCount);
            break;
        case 8:
        {
            double threshold;
            cout << "Введите пороговое значение для соотношения (стипендия / сумма баллов): ";
            cin >> threshold;
            displayGroupsByCondition(students, studentCount, threshold);
            break;
        }
        case 0:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
    while (choice != 0);

    return 0;
}

void menu() 
{
    cout << "\nМеню:\n";
    cout << "1. Добавить студента\n";
    cout << "2. Отобразить всех студентов\n";
    cout << "3. Редактировать данные студента\n";
    cout << "4. Удалить студента\n";
    cout << "5. Удалить студентов из группы\n";
    cout << "6. Сохранить студентов в файл\n";
    cout << "7. Загрузить студентов из файла\n";
    cout << "8. Вывести номера групп по условию\n"; 
    cout << "0. Выйти\n";
    cout << "Ваш выбор: ";
}

void addStudent(Student students[], int& count) 
{
    if (count >= MAX_STUDENTS) 
    {
        cout << "Список студентов переполнен!\n";
        return;
    }

    cout << "Введите ФИО студента (до 50 символов): ";
    cin.ignore();
    cin.getline(students[count].fio, 51);

    cout << "Введите номер группы: ";
    cin >> students[count].groupNumber;

    cout << "Введите 5 оценок за последнюю сессию: ";
    for (int i = 0; i < MAX_GRADES; ++i) 
    {
        cin >> students[count].grades[i];
    }

    cout << "Введите размер стипендии: ";
    cin >> students[count].stipend;

    cout << "Введите дополнительную информацию (до 50 символов, например телефон): ";
    cin.ignore();
    cin.getline(students[count].additionalInfo, 51);

    count++;
    cout << "Студент добавлен успешно!\n";
}

void displayStudents(const Student students[], int count)
{
    if (count == 0)
    {
        cout << "Список студентов пуст.\n";
        return;
    }

    cout << "\nСписок студентов:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Студент №" << i + 1 << ":\n";
        cout << "ФИО: " << students[i].fio << "\n";
        cout << "Номер группы: " << students[i].groupNumber << "\n";
        cout << "Оценки: ";
        for (int j = 0; j < MAX_GRADES; ++j) {
            cout << students[i].grades[j] << " ";
        }
        cout << "\nСтипендия: " << students[i].stipend << "\n";
        cout << "Дополнительная информация: " << students[i].additionalInfo << "\n\n";
    }
}

void editStudent(Student students[], int count)
{
    if (count == 0) {
        cout << "Список студентов пуст.\n";
        return;
    }

    int index;
    cout << "Введите номер студента для редактирования (1-" << count << "): ";
    cin >> index;

    if (index < 1 || index > count) 
    {
        cout << "Некорректный номер студента.\n";
        return;
    }

    Student& student = students[index - 1];

    cout << "Редактируем данные студента:\n";
    cout << "Текущее ФИО: " << student.fio << ". Введите новое ФИО: ";
    cin.ignore();
    cin.getline(student.fio, 51);

    cout << "Текущий номер группы: " << student.groupNumber << ". Введите новый номер группы: ";
    cin >> student.groupNumber;

    cout << "Текущие оценки: ";
    for (int i = 0; i < MAX_GRADES; ++i) 
    {
        cout << student.grades[i] << " ";
    }
    cout << "\nВведите новые 5 оценок: ";
    for (int i = 0; i < MAX_GRADES; ++i) 
    {
        cin >> student.grades[i];
    }

    cout << "Текущий размер стипендии: " << student.stipend << ". Введите новый размер стипендии: ";
    cin >> student.stipend;

    cout << "Текущая дополнительная информация: " << student.additionalInfo << ". Введите новую информацию: ";
    cin.ignore();
    cin.getline(student.additionalInfo, 51);

    cout << "Данные успешно обновлены!\n";
}

void deleteStudent(Student students[], int& count) 
{
    if (count == 0) {
        cout << "Список студентов пуст.\n";
        return;
    }

    int index;
    cout << "Введите номер студента для удаления (1-" << count << "): ";
    cin >> index;

    if (index < 1 || index > count)
    {
        cout << "Некорректный номер студента.\n";
        return;
    }

    for (int i = index - 1; i < count - 1; ++i) 
    {
        students[i] = students[i + 1];
    }

    count--;
    cout << "Студент успешно удален!\n";
}

void deleteGroup(Student students[], int& count)
{
    if (count == 0)
    {
        cout << "Список студентов пуст.\n";
        return;
    }

    int group;
    cout << "Введите номер группы для удаления: ";
    cin >> group;

    int i = 0;
    while (i < count)
    {
        if (students[i].groupNumber == group)
        {
            for (int j = i; j < count - 1; ++j)
            {
                students[j] = students[j + 1];
            }
            count--;
        }
        else {
            i++;
        }
    }

    cout << "Все студенты из группы " << group << " удалены.\n";
}

void saveToFile(const Student students[], int count) 
{
    ofstream file("students.txt");
    if (!file) 
    {
        cout << "Ошибка при открытии файла для записи.\n";
        return;
    }

    file << count << "\n";
    for (int i = 0; i < count; ++i) 
    {
        file << students[i].fio << "\n";
        file << students[i].groupNumber << "\n";
        for (int j = 0; j < MAX_GRADES; ++j)
        {
            file << students[i].grades[j] << " ";
        }
        file << "\n";
        file << students[i].stipend << "\n";
        file << students[i].additionalInfo << "\n";
    }

    file.close();
    cout << "Данные успешно сохранены в файл.\n";
}

void loadFromFile(Student students[], int& count)
{
    ifstream file("students.txt");
    if (!file)
    {
        cout << "Ошибка при открытии файла для чтения.\n";
        return;
    }

    file >> count;
    file.ignore();

    for (int i = 0; i < count; ++i)
    {
        file.getline(students[i].fio, 51);
        file >> students[i].groupNumber;
        for (int j = 0; j < MAX_GRADES; ++j)
        {
            file >> students[i].grades[j];
        }
        file >> students[i].stipend;
        file.ignore();
        file.getline(students[i].additionalInfo, 51);
    }

    file.close();
    cout << "Данные успешно загружены из файла.\n";
}

void displayGroupsByCondition(const Student students[], int count, double threshold)
{
    if (count == 0) 
    {
        cout << "Список студентов пуст.\n";
        return;
    }

    int groups[MAX_STUDENTS] = 
    {
        0 
    };
    int groupCount = 0;

    for (int i = 0; i < count; ++i)
    {
        int sumGrades = 0;
        for (int j = 0; j < MAX_GRADES; ++j)
        {
            sumGrades += students[i].grades[j];
        }

        if (sumGrades > 0 && (students[i].stipend / sumGrades) > threshold)
        {
            bool alreadyExists = false;
            for (int k = 0; k < groupCount; ++k) 
            {
                if (groups[k] == students[i].groupNumber) 
                {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
            {
                groups[groupCount++] = students[i].groupNumber;
            }
        }
    }

    if (groupCount == 0) 
    {
        cout << "Нет групп, соответствующих условию.\n";
    }
    else 
    {
        sort(groups, groups + groupCount); 
        cout << "Номера групп, соответствующие условию:\n";
        for (int i = 0; i < groupCount; ++i)
        {
            cout << groups[i] << " ";
        }
        cout << "\n";
    }
}