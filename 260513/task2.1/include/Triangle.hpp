#pragma once
#include "Shape.hpp"

// наследуется от Shape
class Triangle : public Shape {

    // стороны треугольника
    double edges[3];

public:

    Triangle(double e1, double e2, double e3);

    // базовый класс создаст треугольник со сторонами равными 1
    Triangle() : Triangle(1,1,1) {}

    Triangle(const Triangle& other) : Triangle(other.edges[0],other.edges[1],other.edges[2]) {}

    // реализуем методы

    double area() const override;

    double perimeter() const override;

    void print() const override;
};