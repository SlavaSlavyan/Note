#pragma once

class SimpleFraction {

    // поля
    int numerator, denominator;

    // метод сокращения (вызывается автоматически во всех остальных методах)
    void reducing();

public:

    // конструктор с полями
    SimpleFraction(int n, int d);

    // базовый конструктор с базовыми значениями 0 и 1
    SimpleFraction() : SimpleFraction(0, 1) {};

    // метод вывода
    void print();

    // метод сложения
    SimpleFraction& addition(SimpleFraction *frac);

    // метод вычитания
    SimpleFraction& subtraction(SimpleFraction *frac);

    // метод умножения
    SimpleFraction& multiplication(SimpleFraction *frac);

    // тоже самое только для работы с int

    SimpleFraction& addition(int num);

    SimpleFraction& subtraction(int num);

    SimpleFraction& multiplication(int num);
};