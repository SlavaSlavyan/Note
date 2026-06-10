#include "../include/Lesson.hpp"
#include <cstring>
#include <iostream>

// Реализация базового конструктора. Инициализирует все переменные со значением NULL
Lesson::Lesson() : name(nullptr), teacher(nullptr), date(nullptr) {}

// Реализация главного конструктора
Lesson::Lesson(const char* initName, const char* initTeacher, const char* initDate) : Lesson()
{
    // создаём списки ссылок чтобы не писать одно и тоже несколько раз

    const char* initVars[3] = {initName, initTeacher, initDate};
    char** vars[3] = {&name, &teacher, &date}; // я хуй знает как иначе сделать, в иных случаях всё ломается

    // копируем информацию из аргументов для каждой переменной

    for (int i = 0; i < 3; i++) {
        
        *vars[i] = new char[strlen(initVars[i]) + 1];
        strcpy_s(*vars[i], strlen(initVars[i]) + 1, initVars[i]);
    }
}

// реализация сеттеров

void Lesson::setName(const char* initName)
{
    delete[] name;

    name = new char[strlen(initName) + 1];
    strcpy_s(name, strlen(initName) + 1, initName);
}

void Lesson::setTeacher(const char* initTeacher)
{
    delete[] teacher;

    teacher = new char[strlen(initTeacher) + 1];
    strcpy_s(teacher, strlen(initTeacher) + 1, initTeacher);
}

void Lesson::setDate(const char* initDate)
{
    delete[] date;

    date = new char[strlen(initDate) + 1];
    strcpy_s(date, strlen(initDate) + 1, initDate);
}

// реализация вывода
void Lesson::print()
{
    std::cout << "==============================\nDate: ";
    if (date) std::cout << date;
    else std::cout << "NULL";

    std::cout << "\nLesson: ";
    if (name) std::cout << name;
    else std::cout << "NULL";

    std::cout << "\nTeacher: ";
    if (teacher) std::cout << teacher << '\n';
    else std::cout << "NULL\n";
}