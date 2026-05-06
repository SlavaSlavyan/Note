#include <iostream>
#include <conio.h>
#include "include/MyString.hpp"

int main()
{
    // создаём три строчки разными способами
    MyString *str1 = new MyString(), // пустая строка (nullptr)
             *str2 = new MyString("test"), // строка с динамическим размером
             *str3 = new MyString("test", 3); // стока с задаваемым размером
    
    // вывод
    str1->print();
    str2->print();
    str3->print();

    // ввод для первой строки
    str1->input();

    // вывод
    str1->print();

    delete str1;
    delete str2;
    delete str3;

    _getch();

    return 0;
}