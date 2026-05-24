#pragma once
#include "Shape.hpp"

class Triangle : public Shape {

    double edges[3];

public:

    Triangle(double e1, double e2, double e3);

    Triangle() : Triangle(1,1,1) {}

    Triangle(const Triangle& other) : Triangle(other.edges[0],other.edges[1],other.edges[2]) {}

    double area() const override;

    double perimeter() const override;

    void print() const override;
};