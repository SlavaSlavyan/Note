#include "../include/Rectangle.hpp"
#include <iostream>

// конструктор так же выполняет действия из конструктора Shape
Rectangle::Rectangle(double w, double h) : Shape(), width(w), heigth(h) 
{
    // проверка отрицательных аргументов

    if (width <= 0) {
        width = 1;
    }
    if (heigth <= 0) {
        heigth = 1;
    }
}

// реализация методов

double Rectangle::area() const {
    return width * heigth; // ab
}

double Rectangle::perimeter() const {
    return (width + heigth) * 2; // 2(a+b)
}

void Rectangle::print() const {
    std::cout << "Rectangle size >> " << width << 'x' << heigth
        << "\n          area >> " << area()
        << "\n     perimeter >> " << perimeter() << '\n';
}