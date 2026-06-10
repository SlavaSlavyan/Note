#pragma once
#include "Lesson.hpp"

class Schedule {

    // массив уроков
    Lesson** data = nullptr;
    unsigned int count = 0;

public:

    // деструктор
    ~Schedule();

    // метод добавления урока
    void Add();

    // метод удаления урока
    void Remove();

    // метод поиска урока по имени преподавателя
    void Find();

    // вывод всей таблицы
    void Print();
};