#include <iostream>
#include <conio.h>
#include "include/Fraction.hpp"

int main()
{
    // указатели с которыми я буду работать
    Fraction *a, *b;

    // базовый конструктор
    a = new Fraction();
    std::cout << "Base constructor >> " << *a << '\n';
    delete a;

    // проверка математических операторов
    a = new Fraction(1,4);
    b = new Fraction(1,2);

    std::cout << "\nMath operations:\n"
        << *a << " + " << *b << " = " << *a + *b << '\n'
        << *a << " - " << *b << " = " << *a - *b << '\n'
        << *a << " * " << *b << " = " << *a * *b << '\n'
        << *a << " / " << *b << " = " << *a / *b << '\n';

    // проверка сравнений
    std::cout << "\nComparison operators:\n"
        << *a << " == " << *b << " : " << (*a == *b) << '\n'
        << *a << " != " << *b << " : " << (*a != *b) << '\n'
        << *a << " < " << *b << " : " << (*a < *b) << '\n'
        << *a << " > " << *b << " : " << (*a > *b) << '\n';
        
    delete b;

    // проверка ввода и вывода
    std::cout << "\nInput output test:\na << ";
    std::cin >> *a;
    std::cout << "a >> " << *a << "\n\nEND\n";

    delete a;

    _getch();

    return 0;
}