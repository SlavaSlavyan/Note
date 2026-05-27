#include "../include/Circle.hpp"
#include <iostream>

// есть и другие способы его получить, но чёт не хочу пока (●'◡'●)
const double PI = 3.14159265358979323846;

// конструктор так же выполняет действия из конструктора Shape
Circle::Circle(double r) : Shape(), radius(r) 
{
    // проверка на отрицательный радиус
    if (radius <= 0) {
        radius = 1;
    }
}

// реализация методов

double Circle::area() const {
    return PI * radius * radius; // пr^2
}

double Circle::perimeter() const {
    return PI * radius * 2; // 2пr
}

void Circle::print() const {
    std::cout << "Circle radius >> " << radius
        << "\n         area >> " << area()
        << "\n    perimeter >> " << perimeter() << '\n';
}