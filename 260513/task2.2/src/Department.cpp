#include <iostream>
#include <stdexcept>

#include "../include/Department.hpp"
#include "../include/Employee.hpp"
#include "../include/Developer.hpp"
#include "../include/Intern.hpp"
#include "../include/Manager.hpp"

// функция для увеличения массива на 1
// Я САМ В АХУЕ С ТОГО НА СКОЛЬКО ОНА ОГРОМНАЯ
void Department::addSize()
{
    // создаём массив для копирования информации
    Employee** oldData = nullptr;

    if (data) // если информация есть, то копируем
    {
        // выделяем память
        oldData = new Employee*[length];

        // копируем УКАЗАТЕЛИ не информацию!
        for (unsigned int i = 0; i < length; i++) {
            oldData[i] = data[i];
        }

        // очищаем старые указатели
        // (удаляется только массив указателей, сама информация остаётся)
        delete[] data;
    }

    // выделяем новую память на старый указатель
    data = new Employee*[length + 1];

    if (oldData) // если есть информация для копирования
    {
        // копируем
        for (unsigned int i = 0; i < length; i++) {
            data[i] = oldData[i];
        }

        // удаляем массив старых указателей
        delete[] oldData;
    }

    // обновляем поле размера
    length++;
    newID++;
}

// деструктор
Department::~Department()
{
    if (data) 
    {
        for (unsigned int i = 0; i < length; i++) {
            delete data[i];
        }

        delete[] data;

        data = nullptr;
    }
}

// перегрузки для каждого типа сотрудников
// все они вызывают функцию увеличения массива и 
// заполняют последнее поле в массиве

Department& Department::add(const Employee& emp)
{
    addSize();
    data[length - 1] = new Employee(emp);
    data[length - 1]->setID(newID - 1);
    return *this;
}

Department& Department::add(const Developer& emp)
{
    addSize();
    data[length - 1] = new Developer(emp);
    data[length - 1]->setID(newID - 1);
    return *this;
}

Department& Department::add(const Intern& emp)
{
    addSize();
    data[length - 1] = new Intern(emp);
    data[length - 1]->setID(newID - 1);
    return *this;
}

Department& Department::add(const Manager& emp)
{
    addSize();
    data[length - 1] = new Manager(emp);
    data[length - 1]->setID(newID - 1);
    return *this;
}

// метод удаления сотрудника
Department& Department::remove(unsigned int id)
{
    if (!data || id >= length) {
        throw std::out_of_range("Индекс выходит за допустимый диапазона массива!");
    }
    
    // сохраняем все указатели

    Employee** oldData = new Employee*[length];

    for (unsigned int i = 0; i < length; i++) {
        oldData[i] = data[i];
    }

    delete oldData[id]; // удаляем сотрудника
    delete[] data;

    data = nullptr;

    if (length - 1) // если есть что копировать копируем всех сотрудников без удалённого
    {
        data = new Employee*[length - 1];

        for (unsigned int i = 0; i < id; i++) {
            data[i] = oldData[i];
        }

        for (unsigned int i = id + 1; i < length; i++) {
            data[i - 1] = oldData[i];
        }
    }

    delete[] oldData;

    // обновляем размер массива
    length--;

    return *this;
}

Department& Department::print()
{
    if (!data) {
        std::cout << "NO EMPLOYEES FOUND!\n";
        return *this;
    }

    for (unsigned int i = 0; i < length; i++) {
        data[i]->getInfo();
    }

    std::cout << "==============================\n";

    return *this;
}

// простой бабл сорт
Department& Department::sort()
{
    int n = length;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (data[j]->calculateSalary() < data[j + 1]->calculateSalary()) 
            {
                // переставляем местами указатели
                Employee* tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                
                swapped = true;

            }
        }

        if (!swapped) break;
    }

    return *this;
}