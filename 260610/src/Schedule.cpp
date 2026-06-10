#include "../include/Schedule.hpp"
#include "../include/Lesson.hpp"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <limits>
#include <cstring>

// реализация деструктора
Schedule::~Schedule()
{
    for (unsigned int i = 0; i < count; i++) {
        delete data[i];
    }

    delete[] data;
    data = nullptr;
}

// реализация добавления урока
void Schedule::Add() 
{
    // создаём новый массив с увеличенной памятью
    Lesson** newData = new Lesson*[count + 1];

    // если есть старая информация переносим её в новый массив
    if (count) {
        for (unsigned int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
    }

    // заменяем значение старого указателя на новый
    data = newData;

    // создаём новый урок NULL
    data[count] = new Lesson();
    
    // работа с пользователем

    // буффер для ввода
    char buffer[256];

    // ввод каждой переменной

    std::system("cls");
    std::cout << "Lesson Name << ";
    std::cin.getline(buffer, 256);
    
    data[count]->setName(buffer);

    std::system("cls");
    std::cout << "Lesson Date << ";
    std::cin.getline(buffer, 256);
    
    data[count]->setDate(buffer);

    std::system("cls");
    std::cout << "Lesson Teacher << ";
    std::cin.getline(buffer, 256);
    
    data[count]->setTeacher(buffer);

    std::system("cls");
    std::cout << "New lesson created!\n\n";

    _getch();

    count++;
}

// реализация удаления урока
void Schedule::Remove()
{
    // вывод всех доступных уроков

    std::system("cls");

    // ловим исключение если нет уроков для удаления
    if (!count) {
        std::cout << "No lessons for remove\n\n";
        _getch();
        return;
    }

    for (unsigned int i = 0; i < count; i++) {
        std::cout << i << ". [" << data[i]->getDate() << "] " 
            << data[i]->getName() << " | " << data[i]->getTeacher() << '\n';
    }

    // взаимодействие с пользователем

    unsigned int lesson_id;
    
    std::cout << "\nLesson ID to delete << ";

    // исключение при ошибке ввода
    if (!(std::cin >> lesson_id)) 
    {
        std::system("cls");
        std::cout << "Invalid input!\n\n";

        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        _getch();
        return;
    }

    // исключение при удалении несуществующего урока
    if (lesson_id >= count) 
    {
        std::system("cls");
        std::cout << "Did not foud lesson by id " << lesson_id << " !\n\n";

        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        _getch();
        return;
    }

    // удаление урока
    delete data[lesson_id];

    // переопределение массива

    if (count != 1) // если массив не оказался пустым после удаления урока
    {
        // выделяем новую память
        Lesson** newData = new Lesson*[count - 1]; 

        // переносим ссылки в новый массив

        for (unsigned int i = 0; i < lesson_id; i++) {
            newData[i] = data[i];
        }
        
        for (unsigned int i = lesson_id + 1; i < count; i++) {
            newData[i - 1] = data[i];
        }

        delete[] data;
        data = newData;
    }
    else
    {
        delete[] data;
        data = nullptr;
    }

    std::system("cls");
    std::cout << "Lesson deleted!\n\n";

    _getch();

    count--;
}

// реализация метода поиска
void Schedule::Find() 
{
    // работа с пользователем

    // буффер для ввода
    char buffer[256];

    std::system("cls");
    std::cout << "Teacher name << ";
    std::cin.getline(buffer, 256);

    std::system("cls");

    // проверка того, найден ли хотя бы один урок введённого учителя
    bool any = false;

    for (unsigned int i = 0; i < count; i++)
    {
        bool found = true;

        for (unsigned int j = 0; j < strlen(data[i]->getName()); j++) {
            if (buffer[j] != data[i]->getName()[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            data[i]->print();
            if (!any) any = true;
        }
    }

    if (!any) {
        std::cout << "==============================\n  NO LESSONS FOUND\n";
    }

    std::cout << "==============================\n\n\n";

    _getch();
}

// реализация вывода
void Schedule::Print() 
{
    std::system("cls");
    
    if (!count) {
        std::cout << "==============================\n"
            << "  NO LESSONS FOUND\n"
            << "==============================\n\n\n";
        
        _getch();

        return;
    }

    for (unsigned int i = 0; i < count; i++) {
        data[i]->print();
    }

    std::cout << "==============================\n\n\n";

    _getch();
}