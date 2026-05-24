#pragma once
#include "Shape.hpp"

class Circle : public Shape {

    double radius;

public:
    
    Circle(double r);

    Circle() : Circle(1) {};

    Circle(const Circle& other) : Circle(other.radius) {}

    double area() const override;

    double perimeter() const override;

    void print() const override;
};