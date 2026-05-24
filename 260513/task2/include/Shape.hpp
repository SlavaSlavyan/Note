#pragma once

class Shape {

protected:

    inline static unsigned int count = 0;

public:

    Shape() { count++; }

    Shape(const Shape& other) : Shape() {}

    virtual ~Shape() { count--; }

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual void print() const = 0;

    static unsigned int Count() { return count; }
};