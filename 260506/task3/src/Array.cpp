#include "../include/Array.hpp"
#include <iostream>

// реализация главного конструктора который выделяет память на наш массив
Array::Array(int length) : length(length)
{
    if (length < 0) {
        length = 0;
    }

    data = new int[length];
}

// реализация конструктора с передаваемым массивом который так же
// частично делегирует свои обязанности на главный конструктор
Array::Array(const int* initData, int initLength) : Array(initLength)
{
    // копируем информацию из передаваемого аргумента
    if (initData) {
        for (int i = 0; i < length; i++) {
            data[i] = initData[i];
        }
    }
}

// реализация метода поиска минимального значания
int Array::Min() 
{
    int min = 0;

    for (int i = 1; i < length; i++) {
        if (data[min] < min) {
            min = data[min];
        }
    }

    return min;
}

// реализация метода поиска максимального значания
int Array::Max() 
{
    int max = 0;

    for (int i = 1; i < length; i++) {
        if (data[max] > max) {
            max = data[max];
        }
    }

    return max;
}

// реализация метода изменения элементов массива
Array& Array::Set(int data, int id)
{
    if (id < length && id > -1) {
        this->data[id] = data;
    }

    return *this;
}

// реализация добавления элемента
Array& Array::Add(int data)
{
    // создаём копию нашего массива
    int* oldData = new int[length];

    for (int i = 0; i < length; i++) {
        oldData[i] = this->data[i];
    }

    // очищаем оригинальные данные и выделяем новую память
    this->data = new int[length + 1];

    // копируем старую информацию
    for (int i = 0; i < length; i++) {
        this->data[i] = oldData[i];
    }

    // записываем последний элемент
    this->data[length] = data;

    // обновляем счётчик
    length++;

    // чистим старую память
    delete[] oldData;

    return *this;
}

// реализация добавления элемента №2
Array& Array::Insert(int data, int id)
{
    // проверяем вложенные данные
    if (id < length && id > -1)
    {
        // создаём копию нашего массива
        int* oldData = new int[length];

        for (int i = 0; i < length; i++) {
            oldData[i] = this->data[i];
        }

        // очищаем оригинальные данные и выделяем новую память
        this->data = new int[length + 1];

        // копируем старую информацию до заданного элемента
        for (int i = 0; i < id; i++) {
            this->data[i] = oldData[i];
        }

        // записываем новый элемент
        this->data[id] = data;

        // копируем остальную информацию
        for (int i = id + 1; i <= length; i++) {
            this->data[i] = oldData[i-1];
        }

        // обновляем счётчик
        length++;

        // чистим старую память
        delete[] oldData;
    }

    return *this;
}

// реализация удаления элемента
Array& Array::Remove(int id) 
{
    // проверяем вложенные данные
    if (id < length && id > -1)
    {
        // создаём копию нашего массива
        int* oldData = new int[length];

        for (int i = 0; i < length; i++) {
            oldData[i] = this->data[i];
        }

        // очищаем оригинальные данные и выделяем новую память
        this->data = new int[length - 1];

        // копируем старую информацию до удалённого элемента
        for (int i = 0; i < id; i++) {
            this->data[i] = oldData[i];
        }

        // копируем остальную информацию
        for (int i = id; i <= length; i++) {
            this->data[i] = oldData[i+1];
        }

        // обновляем счётчик
        length--;

        // чистим старую память
        delete[] oldData;
    }

    return *this;
}

// реализация мены двух элементов местами
Array& Array::Swap(int i1, int i2)
{
    // проверяем вложенные данные и меняем местами два элемента
    if (i1 > -1 && i2 > -1 && i1 < length && i2 < length && i1 != i2) 
    {
        int oldData = data[i1];

        data[i1] = data[i2];

        data[i2] = oldData;
    }  

    return *this;
}

// реализация сортировки (это бабл сорт)
Array& Array::Sort()
{
    bool swapped;

    for (int i = 0; i < length - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < length - i - 1; j++)
        {
            if (data[j] > data[j + 1]) 
            {
                this->Swap(j, j + 1);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    return *this;
}

// реализация реверсии
Array& Array::Reverse()
{
    int* oldData = new int[length];

    for (int i = 0; i < length; i++) {
        oldData[i] = this->data[i];
    }

    this->data = new int[length];

    for (int i = 0; i < length; i++) {
        this->data[i] = oldData[length - 1 - i];
    }

    delete[] oldData;

    return *this;
}

// реализация очиски
Array& Array::Clear()
{
    data = new int[0];

    length = 0;

    return *this;
}

// реализация вывода
Array& Array::Print()
{
    std::cout << '[';

    for (int i = 0; i < length; i++) 
    {
        std::cout << data[i];
        if (i != length - 1) { std::cout << ','; }
    }

    std::cout << "]\n";

    return *this;
}