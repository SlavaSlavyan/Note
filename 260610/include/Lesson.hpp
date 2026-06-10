#pragma once

class Lesson {

    // имя урока, учитель и дата
    char * name, * teacher, * date;

public:

    // базовый конструктор
    Lesson();

    // главный конструктор
    Lesson(const char* name, const char* teacher, const char* date);

    // конструктор копирования
    Lesson(const Lesson& other) : Lesson(other.name, other.date, other.teacher) {}

    // деструктор
    ~Lesson() { 
        if (name) delete[] name;
        if (teacher) delete[] teacher;
        if (date) delete[] date;

        name = nullptr;
        teacher = nullptr;
        date = nullptr;
    }

    // геттеры

    const char* getName() const { return name; }

    const char* getTeacher() const { return teacher; }

    const char* getDate() const { return date; }

    // сеттеры

    void setName(const char* name);

    void setTeacher(const char* teacher);

    void setDate(const char* date);

    // вывод
    void print();
};