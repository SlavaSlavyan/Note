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

Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
    if (!denominator) {
        denominator = 1;
    }

    this->Reduction();
}

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
    return double(numerator/denominator) > 
           double(other.numerator/other.denominator);
}

bool Fraction::operator < (const Fraction& other) const
{
    return double(numerator/denominator) <
           double(other.numerator/other.denominator);
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
    
    return in;
}