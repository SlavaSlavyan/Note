// ПОКА ЧТО САМЫЙ НЕКРАСИВЫЙ ФАЙЛ ЗА ВСЁ ВРЕМЯ

#include "../include/Human.hpp"
#include <cstring>
#include <iostream>

// ставим начальное значение счётчику
int Human::count = 0;

// реализуем конструктор с херовой тучей аргументов и огрооооомным списком инициализаторов полей класса
Human::Human(int i, const char* n, const char* s, const char* p, const Date* d):
id(i),
name(n ? new char[strlen(n) + 1] : nullptr),
surname(s ? new char[strlen(s) + 1] : nullptr),
patronymic(p ? new char[strlen(p) + 1] : nullptr),
date(d ? new Date(*d) : nullptr)
{
    // копируем информацию в строки из аргументов

    if (name) {
        strcpy_s(name, strlen(n) + 1, n);
    }
    if (surname) {
        strcpy_s(surname, strlen(s) + 1, s);
    }
    if (patronymic) {
        strcpy_s(patronymic, strlen(p) + 1, p);
    }

    // плюсуем счётчик
    count++;
}

// реализация вывода информации
// ненавижу nullptr столько проблем из-за одной хрени
void Human::info() const 
{
    std::cout << "===============[ID:" << id << "]===============\n";
    std::cout << "Full name: " << (name ? name : "NULL") << ' '
              << (surname ? surname : "NULL") << ' '
              << (patronymic ? patronymic : "NULL") << std::endl;

    if (date) {
        std::cout << "Date: " << date->getDay() << '.' << date->getMonth() << '.' << date->getYear() << std::endl; 
        return;
    }

    std::cout << "Date: NULL\n";
}