#pragma once
#include <string>

// класс даты
class Date {

    // поля
    int day, month, year;

public:

    // простой конструктор
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // и ещё геттеры

    int getDay() const { return day; }

    int getMonth() const { return month; }

    int getYear() const { return year; }
};