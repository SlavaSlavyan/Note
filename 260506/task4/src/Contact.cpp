#include "../include/Contact.hpp"
#include <cstring>

// реализация конструктора (в списке инициализации выделяется память под каждую строку)
Contact::Contact(const char* n, const char* hp, const char* wp, const char* i):
name(n ? new char[strlen(n) + 1] : nullptr),
homePhone(hp ? new char[strlen(hp) + 1] : nullptr),
workPhone(wp ? new char[strlen(wp) + 1] : nullptr),
info(i ? new char[strlen(i) + 1] : nullptr)
{
    const char* init_vars[] = {n, hp, wp, i};
    char* vars[] = {name, homePhone, workPhone, info};

    // копируем информацию
    for (int i = 0; i < 4; i++) {
        if (vars[i]) {
            strcpy_s(vars[i], strlen(init_vars[i]) + 1, init_vars[i]);
        }
    }
}

// реализация всех свойств

char* Contact::getName() const {
    if (name) {
        return name;
    }

    return (char*)"NULL";
};

char* Contact::getHomePhone() const {
    if (homePhone) {
        return homePhone;
    }

    return (char*)"NULL";
};

char* Contact::getWorkPhone() const {
    if (workPhone) {
        return workPhone;
    }

    return (char*)"NULL";
};

char* Contact::getInfo() const {
    if (info) {
        return info;
    }

    return (char*)"NULL";
};

void Contact::setName(const char* init_name) {
    if (init_name) {
        name = new char[strlen(init_name) + 1];
        strcpy_s(name, strlen(init_name) + 1, init_name);
    }
};

void Contact::setHomePhone(const char* init_homePhone) {
    if (init_homePhone) {
        homePhone = new char[strlen(init_homePhone) + 1];
        strcpy_s(homePhone, strlen(init_homePhone) + 1, init_homePhone);
    }
};

void Contact::setWorkPhone(const char* init_workPhone) {
    if (init_workPhone) {
        workPhone = new char[strlen(init_workPhone) + 1];
        strcpy_s(workPhone, strlen(init_workPhone) + 1, init_workPhone);
    }
};

void Contact::setInfo(const char* init_info) {
    if (init_info) {
        info = new char[strlen(init_info) + 1];
        strcpy_s(info, strlen(init_info) + 1, init_info);
    }
};