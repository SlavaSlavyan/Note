#pragma once
#include "Contact.hpp"

class PhoneBook {

    Contact** contacts; // массив всех контактов
    unsigned int length; // длинна массива

public:

    // конструктор и деструктор

    PhoneBook();

    ~PhoneBook();

    // метод добавления нового контакта
    void add(const char* n, const char* hp, const char* wp, const char* i);

    // метод удаление контакта
    bool remove(int id);

    // метод поиска контакта
    void find(const char* request);

    // метод вывода
    void printAll();
};