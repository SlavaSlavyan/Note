#include "../include/Circle.hpp"
#include <iostream>

const double PI = 3.14159265358979323846;

Circle::Circle(double r) : Shape(), radius(r) 
{
    if (radius <= 0) {
        radius = 1;
    }
}

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return PI * radius * 2;
}

void Circle::print() const {
    std::cout << "Circle radius >> " << radius
        << "\n         area >> " << area()
        << "\n    perimeter >> " << perimeter() << '\n';
}