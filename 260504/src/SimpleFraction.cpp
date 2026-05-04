#include "../include/SimpleFraction.hpp"
#include <iostream>

// реализация сокращения дроби
void SimpleFraction::reducing()
{
    // Наибольший Общий Делитель
    int GCD = 0;

    // ищем наибольний общий делитель проверяя каждое число
    for (int i = 2; i <= std::max(numerator, denominator); i++)
    {
        // если число является делителем, то записываем
        if (!(numerator % i) && !(denominator % i)) {
            GCD = i;
        }
    }

    // если делитель был найден сокращаем дробь
    if (GCD) 
    {
        numerator /= GCD;
        denominator /= GCD;
    }
}

// реализация конструктора
SimpleFraction::SimpleFraction(int n, int d) : numerator(n), denominator(d) 
{
    // проверяем если знаменатель равен нулю
    if (!denominator) {
        denominator = 1;
    }

    this->reducing();
}

// реалиация вывода 
void SimpleFraction::print() {
    std::cout << numerator << '/' << denominator << std::endl;
}

// реализация сложения
SimpleFraction& SimpleFraction::addition(SimpleFraction *frac)
{
    numerator = numerator * frac->denominator + frac->numerator * denominator;
    denominator = denominator * frac->denominator;

    this->reducing();
    
    return *this;
}

// реализация вычитания
SimpleFraction& SimpleFraction::subtraction(SimpleFraction *frac)
{
    numerator = numerator * frac->denominator - frac->numerator * denominator;
    denominator = denominator * frac->denominator;

    this->reducing();
    
    return *this;
}

// реализация умножения
SimpleFraction& SimpleFraction::multiplication(SimpleFraction *frac)
{
    numerator = numerator * frac->numerator;
    denominator = denominator * frac->denominator;

    this->reducing();
    
    return *this;
}

// всё те же реализации только для работы с целыми числами
// каждая из них превращает вложенное число в дробь и вызывает
// вышеуказанный соответсвующий метод

SimpleFraction& SimpleFraction::addition(int num)
{
    SimpleFraction frac(num, 1);

    this->addition(&frac);
    
    return *this;
}

SimpleFraction& SimpleFraction::subtraction(int num)
{
    SimpleFraction frac(num, 1);

    this->subtraction(&frac);
    
    return *this;
}

SimpleFraction& SimpleFraction::multiplication(int num)
{
    SimpleFraction frac(num, 1);

    this->multiplication(&frac);
    
    return *this;
}