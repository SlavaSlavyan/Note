#include "../include/Matrix.hpp"
#include <stdexcept>
#include <iostream>

// указывать template <typename T> перед каждой функцией обязательно :(

// реализация главного конструктора
template <typename T>
Matrix<T>::Matrix(int w, int h) : width(w), height(h)
{
    // проверяем передаваемые размеры
    if (width < 1 || height < 1) {
        throw std::invalid_argument("Value of width and height in Matrix need to be bigger than 0.");
    }

    // выделяем память на все строки
    data = new T*[height];

    // выделяем память на каждую строчку отдельно
    for (int i = 0; i < height; i++) {
        data[i] = new T[width];
    }
}

// реализация удобного конструктора
template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list):
Matrix(list.begin()->size(),list.size()) // выделяем память с помощью главного конструктора
{
    // переменные i и j пришлось вынести из-за не очень удобного обращения к list

    int i = 0;

    for (const auto& row : list) 
    {
        int j = 0;

        for (T value : row) {
            data[i][j] = value; // записываем данные
            j++;
        }

        i++;
    }
}

// реализация конструктора копирования который так же выделяет память с помощью главного конструктора
template <typename T>
Matrix<T>::Matrix(const Matrix& other) : Matrix(other.width, other.height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // копируем информацию из другого класса
            data[i][j] = other.data[i][j];
        }
    }
}

// реализация деструктора
template <typename T>
Matrix<T>::~Matrix() 
{
    // удаляем каждую строчку
    for (int i = 0; i < height; i++) {
        delete[] data[i];
    }

    // удаляем сам массив
    delete[] data;

    // зануляем указатель
    data = nullptr;
}

// реализация доступа к отдельным элементам массива (отдельно для записи и чтения)

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

// реализация суммирование матриц
template <typename T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& other)
{
    // размеры матриц должны быть одинаковыми
    if (width != other.width || height != other.height) {
        throw std::invalid_argument("Sizes of matrix needs to be equal to use operator '+'.");
    }

    // создаём новую матрицу
    Matrix<T> newMatrix(width,height);

    // заполняем новую матрицу
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newMatrix(i, j) = data[i][j] + other.data[i][j];
        }
    }

    // возвращаем новую матрицу
    return newMatrix;
}

// реализация вычитания матриц
// тоже самое что и сумма, только результат обратный
template <typename T>
Matrix<T> Matrix<T>::operator - (const Matrix<T>& other)
{
    if (width != other.width || height != other.height) {
        throw std::invalid_argument("Sizes of matrix needs to be equal to use operator '-'.");
    }

    Matrix<T> newMatrix(width,height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newMatrix(i, j) = data[i][j] - other.data[i][j];
        }
    }

    return newMatrix;
}

// реализация перемножения матриц
template <typename T>
Matrix<T> Matrix<T>::operator * (const Matrix<T>& other)
{
    // для перемножения матриц ширина первой должна совпадать с высотой второй
    if (width != other.height) {
        throw std::invalid_argument("Value of columns in first matrix needs to be equal to value of rows in second.");
    }

    // создаём новую матрицу с новыми размерами
    Matrix<T> newMatrix(other.width,height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < other.width; j++) 
        {
            // начальное значение элемента
            newMatrix(i, j) = 0;
            
            // ну а тут лучше посмотрите как матрицы перемножаются, здесь я
            // могу скать только то что они делают это "линейно"
            for (int k = 0; k < width; k++) {
                newMatrix(i, j) += data[i][k] * other.data[k][j];
            }
        }
    }

    // возвращаем новую матрицу
    return newMatrix;
}

// реализация умножения матрицы на скаляр
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

// ВНИМАНИЕ!!! В Обеих реализаиця присваивания я НЕ ЗНАЮ ПРАВИЛЬНО ЛИ Я ОСВОБОЖДАЮ ПАМЯТЬ!!!
// если есть какие либо претензии - каким угодно способом сообщите мне об этом

// реализация удобной перезаписи
template <typename T>
Matrix<T> Matrix<T>::operator = (std::initializer_list<std::initializer_list<T>> list)
{
    // удаляем старые данные
    this->~Matrix();

    // создаём новую матрицу 
    Matrix<T>* newMatrix = new Matrix(list);

    // копируем все поля (хотя скорее не копируем а изменяем место на которое они указывают)
    data = newMatrix->data;
    width = newMatrix->width;
    height = newMatrix->height;

    // возвращаем изменённую матрицу
    return *this;
}

// реализация копирования матрицы
// тоже самое как и в прошлой функции
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

// дальше идут математические операторы с присваиванием
// они сделаны через уже готоые операторы т. к. мне лень всё переписывать
// да и в целом зачем переписывать ¯\_(ツ)_/¯

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

// интерполяция матрицы
template <typename T>
Matrix<T> Matrix<T>::operator ! () const
{
    // создаём новую матрицу с перевёрнутыми размерами
    Matrix<T> newMatrix(height,width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // записываемм данные в новую матрицу (естественно их интерполируя)
            newMatrix(j, i) = data[i][j];
        }
    }

    // возвращаем новую матрицу
    return newMatrix;
}

// реализация сравнения
template <typename T>
bool Matrix<T>::operator == (const Matrix<T>& other) const
{
    // если размеры матриц не совпадают - то они не могут быть равны
    if (width != other.width || height != other.height) {
        return false;
    }

    // проверяем каждую клетку
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // если поля не совпадают - матрицы не равны
            if (other(i, j) != data[i][j]) {
                return false;
            }
        }
    }

    // во всех остальных случаях матрицы равны
    return true;
}

// реализация обратного сравнения
// сделана лениво
template <typename T>
bool Matrix<T>::operator != (const Matrix<T>& other) const
{
    return !(*this == other);
}