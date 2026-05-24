#pragma once
#include "Shape.hpp"

class Rectangle : public Shape {

    double width, heigth;

public:

    Rectangle(double w, double h);

    Rectangle() : Rectangle(1,1) {}

    Rectangle(const Rectangle& other) : Rectangle(other.width, other.heigth) {}

    double area() const override;

    double perimeter() const override;

    void print() const override;
};