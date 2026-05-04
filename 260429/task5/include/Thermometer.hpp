#pragma once

// наш класс
class Thermometer {

    // поля
    double celsius;
    char* location;

public:

    // базовый конструктор
    Thermometer();

    // конструктор с указанием температуры
    Thermometer(double tempCelsius);

    // конструктор с указанием всех полей
    Thermometer(const char* place, double tempCelsius);

    // деструктор
    ~Thermometer() { delete[] location; }

    // метод получения температуры в цельсиях
    double getCelsius() { return celsius; }

    // метод получения температуры в фаренгейте
    double getFahrenheit();

    // вывод информации
    void printInfo();
};