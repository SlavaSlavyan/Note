#pragma once

// наш класс
class Rectangle {

    // поля
    double width, height;

public:

    // конструктор
    Rectangle(double initWidth, double initHeight);

    // inline методы
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getArea() const { return width * height; }
    double getPerimeter() const { return 2 * (width + height); }
    bool isSquare() const { return width == height; }

    // метод вывода информации
    void printInfo();
};