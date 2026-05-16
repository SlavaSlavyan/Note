#include <iostream>
#include <conio.h>
#include "include/Matrix.hpp"

int main()
{
    // указатели с которыми я буду работать
    Matrix<int> *a, *b;

    // базовый конструктор
    a = new Matrix<int>();
    std::cout << "Base constructor (data is null) >> " << *a << '\n';
    delete a;

    // проверка математических операторов
    a = new Matrix<int>({{1,2,3}});
    b = new Matrix<int>({{6,4,5}});

    std::cout << "\nMath operations:\n"
        << *a << " + " << *b << " = " << *a + *b << '\n'
        << *a << " - " << *b << " = " << *a - *b << '\n'
        << *a << " * !" << *b << " = " << *a * !*b << '\n'
        << *a << " * " << 5 << " = " << *a * 5 << '\n';

    // доступ к координатам по индексу
    std::cout << "\nAccess to coordinates by index:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "a[" << 0 << ',' << i << "] >> " << (*a)(0,i) << '\n';
    }

    // проверка сравнений
    std::cout << "\nComparison operators:\n"
        << *a << " == " << *b << " : " << (*a == *b) << '\n'
        << *a << " != " << *b << " : " << (*a != *b) << "\n\nEND\n";
    
    delete a;
    delete b;

    _getch();

    return 0;
}