#include "../include/Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double w, double h) : Shape(), width(w), heigth(h) 
{
    if (width <= 0) {
        width = 1;
    }
    if (heigth <= 0) {
        heigth = 1;
    }
}

double Rectangle::area() const {
    return width * heigth;
}

double Rectangle::perimeter() const {
    return (width + heigth) * 2;
}

void Rectangle::print() const {
    std::cout << "Rectangle size >> " << width << 'x' << heigth
        << "\n          area >> " << area()
        << "\n     perimeter >> " << perimeter() << '\n';
}