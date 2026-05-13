#include "../include/Matrix.hpp"
#include <stdexcept>

template <typename T>
Matrix<T>::Matrix(int w, int h) : width(w), height(h)
{
    if (width < 1 || height < 1) {
        throw std::invalid_argument("Value of width and height in Matrix need to be bigger than 0.")
    }

    data = new T*[height];

    for (int i = 0; i < height; i++) {
        data[i] = new T[width];
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : Matrix(other.width, other.height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] = other[i][j];
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
Matrix<T>::Matrix operator + (const Matrix<T>::Matrix& other)
{
    if (width != other.width || height != other.height < 1) {
        throw std::invalid_argument("Value of width and height in Matrix need to be bigger than 0.")
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] = other[i][j];
        }
    }
}

Matrix operator - (const Matrix& other);