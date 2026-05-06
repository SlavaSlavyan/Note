#include <iostream>
#include <conio.h>
#include "include/Array.hpp"

int main()
{
    // создаём массив
    Array* arr = new Array();

    // задаём значения [1,2,3,4,5]
    arr->Add(1).Add(2).Add(3).Add(4).Add(5).Print();

    // добавляем 0 в первый элемент, убираем шестой элемент
    // и меняем местами первый и пятый элементы
    arr->Insert(0,0).Remove(5).Swap(0,4).Print();

    // сортируем и отражаем и заменяем третий элемент на 10
    arr->Sort().Reverse().Set(10,2).Print();

    // вызываем парочку дополнительных методов

    std::cout << "arr->GetData() >> " << arr->GetData() << std::endl;

    std::cout << "arr->GetIndex(0) >> " << arr->GetIndex(0) << std::endl;

    std::cout << "arr->GetLength() >> " << arr->GetLength() << std::endl;

    std::cout << "arr->Min() >> " << arr->Min() << std::endl;

    std::cout << "arr->Max() >> " << arr->Max() << std::endl;

    // очищаем
    arr->Clear().Print();

    delete arr;

    _getch();

    return 0;
}