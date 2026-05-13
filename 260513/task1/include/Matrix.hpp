#pragma once

template <typename T>

class Matrix {

    T** data;
    int width, height;

public:

    Matrix(int w, int h);
    
    Matrix() : Matrix(0, 0);

    Matrix(const Matrix& other);

    ~Matrix();

    Matrix operator + (const Matrix& other);

    Matrix operator - (const Matrix& other);

    Matrix operator * (const Matrix& other);

    Matrix operator * (T scalar);

    Matrix operator += (const Matrix& other);

    Matrix operator -= (const Matrix& other);

    Matrix operator *= (const Matrix& other);

    Matrix operator *= (T scalar);

    T& operator () (int w, int h);

    const T& operator () (int w, int h) const;

    Matrix operator ! () const;

    Matrix operator = (T scalar);

    bool operator == (const Fraction& other) const;

    bool operator != (const Fraction& other) const;
};