#pragma once
#include "Shape.hpp"

// наследуется от Shape
class Rectangle : public Shape {

    // ширина и высота прямоугольника
    double width, heigth;

public:

    Rectangle(double w, double h);

    // базовый класс создаст прямоугольник с высотой 1 и шириной 1
    Rectangle() : Rectangle(1,1) {}

    Rectangle(const Rectangle& other) : Rectangle(other.width, other.heigth) {}

    // реализуем методы

    double area() const override;

    double perimeter() const override;

    void print() const override;
};