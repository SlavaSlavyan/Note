// ГЛАВНЫЙ "АБСТРАКТНЫЙ" класс от которого наследуются остальные

#pragma once

class Shape {

protected:

    // статический счётчик фигур
    inline static unsigned int count = 0;

public:

    // в базовом конструкторе реализуем увеличение счётчика
    Shape() { count++; }

    Shape(const Shape& other) : Shape() {}

    // в базовом деструкторе реализуем уменьшение счётчика
    virtual ~Shape() { count--; }

    // методы которые нужно реализовать

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual void print() const = 0;

    // вывод счётчика
    static unsigned int Count() { return count; }
};