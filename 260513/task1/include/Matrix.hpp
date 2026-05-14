#pragma once
#include <iostream>
#include <initializer_list>

template <typename T>
class Matrix {

    T** data;
    int width, height;

public:

    Matrix(int w, int h);

    Matrix(std::initializer_list<std::initializer_list<T>> list);
    
    Matrix() : Matrix(1, 1) {}

    Matrix(const Matrix& other);

    ~Matrix();

    T& operator () (int w, int h);

    const T& operator () (int w, int h) const;

    Matrix operator + (const Matrix& other);

    Matrix operator - (const Matrix& other);

    Matrix operator * (const Matrix& other);

    Matrix operator * (T scalar);

    Matrix operator = (std::initializer_list<std::initializer_list<T>> list);

    Matrix operator = (const Matrix& other);

    Matrix operator += (const Matrix& other);

    Matrix operator -= (const Matrix& other);

    Matrix operator *= (const Matrix& other);

    Matrix operator *= (T scalar);

    Matrix operator ! () const;

    bool operator == (const Matrix& other) const;

    bool operator != (const Matrix& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m)
    {
        for (int i = 0; i < m.height; i++)
        {
            os << '[';

            for (int j = 0; j < m.width; j++) {
                os << m.data[i][j];
                if (j != m.width - 1) { os << ','; }
            }

            os << "]\n";
        }

        return os;
    }
};

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;