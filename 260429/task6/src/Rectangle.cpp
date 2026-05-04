#include "../include/Rectangle.hpp"
#include <iostream>

// реализация конструктора
Rectangle::Rectangle(double initWidth, double initHeight)
{
    // проверяем аргументы

    if (initWidth < 0) {
        initWidth = 1.0;
    }

    if (initHeight < 0) {
        initHeight = 1.0;
    }

    // заполяняем поля
    this->width = initWidth;
    this->height = initHeight;
}

// реализация методы вывода информации
void Rectangle::printInfo()
{
    std::cout << "==========================\n";
    std::cout << "Rectangle size: " << this->width << " X " << this->height << std::endl;
    std::cout << "Area: " << this->getArea() << std::endl;
    std::cout << "Perimeter: " << this->getPerimeter() << std::endl;
    std::cout << "Is a square: ";
    
    if (this->isSquare()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}