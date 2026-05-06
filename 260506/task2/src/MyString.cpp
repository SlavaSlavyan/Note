#include "../include/MyString.hpp"
#include <cstring>
#include <iostream>

// реализация главного конструктора
MyString::MyString(const char* d, int l) : data(d ? new char[l + 1] : nullptr)
{
    if (data) {
        for (int i = 0; i < l; i++) {
            data[i] = d[i];
        }

        data[l] = '\0';
    }
}

// реализация двух других конструкторов которые делегируют всё в основной

MyString::MyString(const char* d) : MyString(d, strlen(d)) {}

MyString::MyString() : MyString(nullptr, 0) {}

// реализация ввода и вывода

void MyString::input()
{
    data = new char[0];

    std::cout << "String data << ";
    std::cin >> data;
}

void MyString::print() 
{
    if (data) {
        std::cout << data << std::endl;
        return;
    }

    std::cout << "NULL\n";
}