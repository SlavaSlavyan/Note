#include "../include/Fraction.hpp"

// реализация сокращения по алгоритму Евклида
void Fraction::Reduction()
{
    int a = numerator, b = denominator;

    while (b)
    {
        int _temp = b;
        b = a % b;
        a = _temp;
    }
    
    numerator /= a;
    denominator /= a;
}

// основной конструктор
Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
    // исключаем ноль
    if (!denominator) {
        denominator = 1;
    }

    // сокращаем дробь
    this->Reduction();
}

// ну а дальше мне лень расписывать всё и так понятно что это всё реализации

Fraction Fraction::operator + (const Fraction& other)
{
    return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
}

Fraction Fraction::operator - (const Fraction& other)
{
    return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
}

Fraction Fraction::operator * (const Fraction& other)
{
    return Fraction(numerator * other.numerator, 
                        denominator * other.denominator);
}

Fraction Fraction::operator / (const Fraction& other)
{
    return Fraction(numerator * other.denominator, 
                        denominator * other.numerator);
}

Fraction Fraction::operator += (const Fraction& other)
{
    *this = *this + other;
    return *this;
}

Fraction Fraction::operator -= (const Fraction& other)
{
    *this = *this - other;
    return *this;
}

Fraction Fraction::operator *= (const Fraction& other)
{
    *this = *this * other;
    return *this;
}

Fraction Fraction::operator /= (const Fraction& other)
{
    *this = *this / other;
    return *this;
}

bool Fraction::operator == (const Fraction& other) const
{
    return (numerator == other.numerator &&
            denominator == other.denominator);
}

bool Fraction::operator != (const Fraction& other) const
{
    return !(*this == other);
}

bool Fraction::operator > (const Fraction& other) const 
{
    double a, b;

    a = numerator/(float)denominator;
    b = other.numerator/(float)other.denominator;

    return (a > b);
}

bool Fraction::operator < (const Fraction& other) const
{
    double a, b;

    a = numerator/(float)denominator;
    b = other.numerator/(float)other.denominator;

    return (a < b);
}

bool Fraction::operator >= (const Fraction& other) const
{
    return !(*this < other);
}

bool Fraction::operator <= (const Fraction& other) const
{
    return !(*this > other);
}

std::ostream& operator << (std::ostream& os, const Fraction& f)
{
    os << f.numerator << '/' << f.denominator;
    return os;
}

std::istream& operator >> (std::istream& in, Fraction& f) 
{
    in >> f.numerator >> f.denominator;
    f.Reduction();
    return in;
}