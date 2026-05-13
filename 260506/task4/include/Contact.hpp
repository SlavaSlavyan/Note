#pragma once

class Contact {

    // имя, телефоны и информация
    char *name, *homePhone, *workPhone, *info;

public:

    // главный конструктор со всеми полями
    Contact(const char* n, const char* hp, const char* wp, const char* i);

    // базовый конструктор который делегирует свои обязанности
    Contact() : Contact(nullptr, nullptr, nullptr, nullptr) {}

    // конструктор копирования (хз зачем на самом деле)
    Contact(const Contact &other) : Contact(other.name, other.homePhone, other.workPhone, other.info) {}; 

    // деструктор
    ~Contact() {
        delete[] name;
        delete[] homePhone;
        delete[] workPhone;
        delete[] info;
    }

    // свойства

    char* getName() const;

    char* getHomePhone() const;

    char* getWorkPhone() const;

    char* getInfo() const;

    void setName(const char* init_name);

    void setHomePhone(const char* init_homePhone);

    void setWorkPhone(const char* init_workPhone);

    void setInfo(const char* init_info);
};