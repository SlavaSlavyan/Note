#pragma once
#include "Date.hpp"
#include <iostream>

// класс человека
class Human {

    // статический счётчик который находится ТОЛЬКО в классе
    static int count;

    // поля класса которое будут находится в ЭКЗЕМПЛЯРЕ класса
    int id;
    char *name, *surname, *patronymic;
    Date* date;

public:

    // Конструктор со всеми полями
    Human(int id, const char* n, const char* s, const char* p, const Date* d);

    // Конструктор по умолчанию который делегирует свои обязанности
    Human() : Human(0, nullptr, nullptr, nullptr, nullptr) {}

    // Хз как это называется правильно, но этот метод копирует информацию из вложенного класса
    Human(const Human &other) : Human(other.id, other.name, other.surname, other.patronymic, other.date) {};

    // деструктор
    ~Human() {
        delete[] name, 
        delete[] surname,
        delete[] patronymic, 
        delete[] date;
        count--; // минусует счётчик
    }

    // куча геттеров

    static int getCount() { return count; }

    char* getName() const { return name; }

    char* getSurname() const { return surname; }
    
    char* getPatronymic() const { return patronymic; }

    Date* getDate() const { return date; }

    // метод вывода информации
    void info() const;
};