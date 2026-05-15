#pragma once
#include <iostream>
#include <initializer_list> // библиотека для того чтобы можно было удобно заполнять матрицу

// задаём шаблон generic, чтобы класс мог принимать любой тип данных
template <typename T>
class Matrix {

    // поле для динамического двумерного массива 
    T** data;

    // ширина и высота
    int width, height;

public:

    // главный конструктор который выделяет память
    Matrix(int w, int h);

    // конструктор с удобной записью данных
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    
    // базовый конструктор (пустая матрица 1 на 1)
    Matrix() : Matrix(1, 1) {}

    // конструктор для копирования
    Matrix(const Matrix& other);

    // деструктор
    ~Matrix();

    // доступ к отдельному элементу матрицы (запись)
    T& operator () (int w, int h);

    // доступ к отдельному элементу матрицы (чтение)
    const T& operator () (int w, int h) const;

    // суммирование матриц
    Matrix operator + (const Matrix& other);

    // вычитание матриц
    Matrix operator - (const Matrix& other);

    // перемножение матриц
    Matrix operator * (const Matrix& other);

    // умножение матрицы на скаляр
    Matrix operator * (T scalar);

    // удобная перезапись матрицы
    Matrix operator = (std::initializer_list<std::initializer_list<T>> list);

    // копирование матрицы
    Matrix operator = (const Matrix& other);

    // математические операции с присваиванием

    Matrix operator += (const Matrix& other);

    Matrix operator -= (const Matrix& other);

    Matrix operator *= (const Matrix& other);

    Matrix operator *= (T scalar);

    // интерполяция матрицы
    Matrix operator ! () const;

    // сравнения матриц

    bool operator == (const Matrix& other) const;

    bool operator != (const Matrix& other) const;

    // вывод матрицы
    // я к сожалению не смог отдельно этот метод вынести в реализацию
    // если у вас это получится то круто
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

// разрешённые типы данных
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;