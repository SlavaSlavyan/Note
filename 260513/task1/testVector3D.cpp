#include <iostream>
#include <conio.h>
#include "include/Vector3D.hpp"

int main()
{
    // указатели с которыми я буду работать
    Vector3D *a, *b;

    // базовый конструктор
    a = new Vector3D();
    std::cout << "Base constructor >> " << *a << '\n';
    delete a;

    // проверка математических операторов
    a = new Vector3D(1,2,3);
    b = new Vector3D(4,5,6);

    std::cout << "\nMath operations:\n"
        << *a << " + " << *b << " = " << *a + *b << '\n'
        << *a << " - " << *b << " = " << *a - *b << '\n'
        << *a << " * " << *b << " = " << *a * *b << '\n'
        << *a << " * " << 5 << " = " << *a * 5 << '\n';
    
    // проверка инкремента и декремента
    std::cout << "\nIncrements and decrements:\n"
        << *a << "++ >> " << ++*a << '\n'
        << *b << "-- >> " << --*b << '\n';

    // доступ к координатам по индексу
    std::cout << "\nAccess to coordinates by index:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "a[" << i << "] >> " << (*a)[i] << '\n';
    }

    int test = Vector3D::Count();

    // проверка счётчика
    std::cout << "\nCount of vectors:\n"
        << "Vector3D::Count() >> " << test << '\n';
    delete a;
    delete b;

    _getch();

    return 0;
}