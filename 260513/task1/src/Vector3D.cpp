#include "../include/Vector3D.hpp"
#include <stdexcept>
#include <iostream>

// основной конструктор который записывает данные
Vector3D::Vector3D(float x, float y, float z)
{
    data[0] = x;
    data[1] = y;
    data[2] = z;
    
    // увеличиваем счётчик
    count++;
}

// сумма
Vector3D Vector3D::operator + (const Vector3D& other)
{
    return Vector3D(data[0] + other.data[0],
                    data[1] + other.data[1],
                    data[2] + other.data[2]);
}

// разность
Vector3D Vector3D::operator - (const Vector3D& other)
{
    return Vector3D(data[0] - other.data[0],
                    data[1] - other.data[1],
                    data[2] - other.data[2]);
}

// скалярное произведение
float Vector3D::operator * (const Vector3D& other)
{
    return data[0] * other.data[0] +
           data[1] * other.data[1] +
           data[2] * other.data[2];
}

// умножение на скаляр
Vector3D Vector3D::operator * (float num)
{
    return Vector3D(data[0] * num,
                    data[1] * num,
                    data[2] * num);
}

// всё тоже самое, только с присваиванием 

Vector3D Vector3D::operator += (const Vector3D& other)
{
    *this = *this + other;
    return *this;
}

Vector3D Vector3D::operator -= (const Vector3D& other)
{
    *this = *this - other;
    return *this;
}

Vector3D Vector3D::operator *= (float num)
{
    *this = *this * num;
    return *this;
}

// инкременты и декременты

Vector3D& Vector3D::operator ++ ()
{
    *this += Vector3D(1,1,1);
    return *this;
}

Vector3D Vector3D::operator ++ (int)
{
    Vector3D _temp = *this;
    *this += Vector3D(1,1,1);
    return _temp;
}

Vector3D& Vector3D::operator -- ()
{
    *this -= Vector3D(1,1,1);
    return *this;
}

Vector3D Vector3D::operator -- (int)
{
    Vector3D _temp = *this;
    *this -= Vector3D(1,1,1);
    return _temp;
}

// ввод переменной
float& Vector3D::operator[](size_t index)
{
    if (index >= 0 && index < 3)
    {
        return data[index];
    }

    throw std::out_of_range("Index out of range.");
}

// вывод переменной (константный для безопастности)
const float& Vector3D::operator[](size_t index) const
{
    if (index >= 0 && index < 3)
    {
        return data[index];
    }

    throw std::out_of_range("Index out of range.");
}

// вывод в консоль полного массива
std::ostream& operator << (std::ostream& os, const Vector3D& v)
{
    os << '[' << v.data[0] << ',' << v.data[1] << ',' << v.data[2] << ']';
    return os;
}