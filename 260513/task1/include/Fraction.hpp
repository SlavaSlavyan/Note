#pragma once
#include <iostream>

class Fraction {

    // поля числитель и знаменатель
    int numerator, denominator;

    // метод сокращения дроби
    void Reduction();

public:

    // главный конструктор
    Fraction(int n, int d);

    // базовый делегирующий конструктор
    Fraction() : Fraction(0, 1) {}

    // перегрузка базовых арифметических операторов

    Fraction operator + (const Fraction& other);

    Fraction operator - (const Fraction& other);

    Fraction operator * (const Fraction& other);

    Fraction operator / (const Fraction& other);

    // перегрузка арифметических операторов с присваиванием

    Fraction operator += (const Fraction& other);

    Fraction operator -= (const Fraction& other);

    Fraction operator *= (const Fraction& other);

    Fraction operator /= (const Fraction& other);

    // перегрузка операторов сравнения

    bool operator == (const Fraction& other) const;
    
    bool operator != (const Fraction& other) const;

    bool operator > (const Fraction& other) const;

    bool operator < (const Fraction& other) const;

    bool operator >= (const Fraction& other) const;

    bool operator <= (const Fraction& other) const;

    // перегрузка операторов присваивания и чтения

    friend std::ostream& operator << (std::ostream& os, const Fraction& f);

    friend std::istream& operator >> (std::istream& in, Fraction& f);
};