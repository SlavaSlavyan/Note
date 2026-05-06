#pragma once

class MyString {

    // информация
    char* data;

public:

    // конструктор с задаваемой строкой и длинной
    MyString(const char* d, int l);

    // конструктор с задаваемой строкой (динамическая)
    MyString(const char* d);

    // конструктор который позволяет 
    MyString();

    // копировать епт
    MyString(const MyString &other) : MyString(other.data) {}

    // деструктор
    ~MyString() {
        delete[] data;
    }

    // метод ввода
    void input();

    // метод вывода
    void print();
};