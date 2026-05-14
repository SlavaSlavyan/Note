#include "../include/Matrix.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
Matrix<T>::Matrix(int w, int h) : width(w), height(h)
{
    if (width < 1 || height < 1) {
        throw std::invalid_argument("Value of width and height in Matrix need to be bigger than 0.");
    }

    data = new T*[height];

    for (int i = 0; i < height; i++) {
        data[i] = new T[width];
    }
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list):
Matrix(list.begin()->size(),list.size())
{
    int i = 0;

    for (const auto& row : list) 
    {
        int j = 0;

        for (T value : row) {
            data[i][j] = value;
            j++;
        }

        i++;
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : Matrix(other.width, other.height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

template <typename T>
Matrix<T>::~Matrix() 
{
    for (int i = 0; i < height; i++) {
        delete[] data[i];
    }

    delete[] data;
    data = nullptr;
}
template <typename T>
T& Matrix<T>::operator () (int w, int h)
{
    return data[w][h];
}

template <typename T>
const T& Matrix<T>::operator () (int w, int h) const
{
    return data[w][h];
}

template <typename T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& other)
{
    if (width != other.width || height != other.height) {
        throw std::invalid_argument("Sizes of matrix needs to be equal to use operator '+'.");
    }

    Matrix<T> newMatrix(width,height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newMatrix(i, j) = data[i][j] + other.data[i][j];
        }
    }

    return newMatrix;
}
template <typename T>
Matrix<T> Matrix<T>::operator - (const Matrix<T>& other)
{
    if (width != other.width || height != other.height) {
        throw std::invalid_argument("Sizes of matrix needs to be equal to use operator '+'.");
    }

    Matrix<T> newMatrix(width,height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newMatrix(i, j) = data[i][j] - other.data[i][j];
        }
    }

    return newMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator * (const Matrix<T>& other)
{
    if (width != other.height) {
        throw std::invalid_argument("Value of columns in first matrix needs to be equal to value of rows in second.");
    }

    Matrix<T> newMatrix(other.width,height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < other.width; j++) 
        {
            newMatrix(i, j) = 0;

            for (int k = 0; k < width; k++) {
                newMatrix(i, j) += data[i][k] * other.data[k][j];
            }
        }
    }

    return newMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator * (T scalar)
{
    Matrix<T> newMatrix(width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newMatrix(i, j) = data[i][j] * (T)scalar;
        }
    }

    return newMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator = (std::initializer_list<std::initializer_list<T>> list)
{
    this->~Matrix();

    Matrix<T>* newMatrix = new Matrix(list);

    data = newMatrix->data;
    width = newMatrix->width;
    height = newMatrix->height;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator = (const Matrix<T>& other)
{
    this->~Matrix();

    Matrix<T>* newMatrix = new Matrix(other);

    data = newMatrix->data;
    width = newMatrix->width;
    height = newMatrix->height;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator += (const Matrix<T>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator -= (const Matrix<T>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator *= (const Matrix<T>& other)
{
    *this = *this * other;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator *= (T scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator ! () const
{
    Matrix<T> newMatrix(height,width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newMatrix(j, i) = data[i][j];
        }
    }

    return newMatrix;
}

template <typename T>
bool Matrix<T>::operator == (const Matrix<T>& other) const
{
    if (width != other.width || height != other.height) {
        return false;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (other(i, j) != data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
bool Matrix<T>::operator != (const Matrix<T>& other) const
{
    return !(*this == other);
}