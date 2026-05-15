#pragma once
#include <iostream>

class Vector3D {

    // сам вектор
    float data[3];

    // счётчик
    static inline int count = 0;

public:

    // основной конструктор
    Vector3D(float x, float y, float z);

    // базовый конструктор
    Vector3D() : Vector3D(0, 0, 0) {}

    // деструктор который уменьшает счётчик
    ~Vector3D() {
        count--;
    }

    // метод для получения счётчика
    static int Count() { return count; }

    // математические операторы

    Vector3D operator + (const Vector3D& other);

    Vector3D operator - (const Vector3D& other);

    // скалярное произведение с другим вектором
    float operator * (const Vector3D& other);

    // умножение на скаляр
    Vector3D operator * (float num);

    // математические операторы с присваиванием

    Vector3D operator += (const Vector3D& other);

    Vector3D operator -= (const Vector3D& other);

    Vector3D operator *= (float num);

    // инкременты и декременты

    Vector3D& operator ++ ();

    Vector3D operator ++ (int);

    Vector3D& operator -- ();

    Vector3D operator -- (int);

    // доступ к координатам по индексу

    float& operator[](size_t index);

    const float& operator[](size_t index) const;

    // вывод в консоль

    friend std::ostream& operator << (std::ostream& os, const Vector3D& v);
};