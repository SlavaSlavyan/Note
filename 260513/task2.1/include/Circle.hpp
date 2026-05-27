#pragma once
#include "Shape.hpp"

// наследуется от Shape
class Circle : public Shape {

    // радиус круга
    double radius;

public:
    
    Circle(double r);

    // базовый класс создаст круг с радиусом 1
    Circle() : Circle(1) {};

    Circle(const Circle& other) : Circle(other.radius) {}

    // реализуем методы

    double area() const override;

    double perimeter() const override;

    void print() const override;
};