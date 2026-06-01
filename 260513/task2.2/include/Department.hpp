#pragma once
#include "Employee.hpp"
#include "Developer.hpp"
#include "Intern.hpp"
#include "Manager.hpp"

// класс департамента для управления сотрудниками
class Department {

    // массив сотрудников
    Employee** data = nullptr;

    // длинна массива и новый уникальный айди
    unsigned int length = 0, newID = 0;

    // общая функция увеличения массива
    void addSize();

public:

    // деструктор
    ~Department();

    // перегрузки для каждого типа сотрудника

    Department& add(const Employee& emp);

    Department& add(const Developer& emp);

    Department& add(const Intern& emp);

    Department& add(const Manager& emp);

    // удаление сотрудника
    Department& remove(unsigned int id);

    // вывод всех сотрудников
    Department& print();

    // сортировка сотрудников по зарплате
    Department& sort();
};