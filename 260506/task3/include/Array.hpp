#pragma once

class Array
{
    // поля
    int* data;
    int length;

public:

    // Конструктор с задаваемой велечиной
    Array(int length);
    
    // Конструктор с передаваемым массивом (бесполезная хрень)
    Array(const int* data, int length);

    // базовый конструктор который создаёт пустой массив
    Array() : Array(0) {};

    // копировальная мащина >:)
    Array(const Array &other) : Array(other.data, other.length) {}

    // деструктор
    ~Array() {
        delete[] data;
    }

    // метод для прямого получения данных
    int* GetData() { return data; };

    // метод для получения размера массива
    int GetLength() { return length; }

    // метод для получения отдельного элемента внутри массива
    int GetIndex(int i) { return data[i]; }

    // метод для получения минимального значения внутри массива
    int Min();

    // метод для получения максимального значения внутри массива
    int Max();

    // метод для изменения отдельного элемента внутри массива
    Array& Set(int data, int id);

    // метод для добавления нового элемента массива в конец
    Array& Add(int data);

    // метод для добавления нового элемента массива в определёный индекс
    Array& Insert(int data, int id);

    // метод для удаления элементов
    Array& Remove(int id);

    // метод для перестановки двух элементов
    Array& Swap(int i1, int i2);

    // метод для сортировки массива
    Array& Sort();

    // метод для реверса массива
    Array& Reverse();

    // метод для очистки массива
    Array& Clear();

    // метод для вывода массива
    Array& Print();
};