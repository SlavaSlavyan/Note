#include <iostream>
#include <conio.h>
#include "include/Circle.hpp"
#include "include/Shape.hpp"
#include "include/Rectangle.hpp"
#include "include/Triangle.hpp"

int main()
{
    // создаём все фигуры
    Shape* shapes[] = {new Circle(1.5),
                       new Rectangle(3,5),
                       new Triangle(3,4,5)};

    // вызываем функции print для каждой фигуры
    for (int i = 0; i < 3; i++) 
    {
        shapes[i]->print();
        std::cout << '\n';
    }

    // очищение памяти и и показ счётчика
    for (int i = 0; i < 3; i++) 
    {
        std::cout << "delete shapes [" << i << "]\n";
        delete shapes[i];
        std::cout << "Shape::Count << " << Shape::Count() << '\n';
    }

    std::cout << "\nEND\n";

    _getch();

    return 0;
}