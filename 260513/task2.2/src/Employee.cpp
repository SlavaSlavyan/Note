#include <iostream>
#include <cstring>
#include "../include/Employee.hpp"

// реализация конструктора
Employee::Employee(const char* n, unsigned int i, unsigned int s) : id(i), salary(s),
name(n ? new char[strlen(n) + 1] : nullptr) 
{
    if (name) strcpy_s(name, strlen(n) + 1, n);
}

// реализация вывода информации 
// (customsalary нужен для замены вывода информации о зарплате из других функций)
void Employee::getInfo(bool customSalary) const
{
    std::cout << "==============================\nID: " << id << "\nName: ";
    if (name) std::cout << name << '\n';
    else std::cout << "NULL" << '\n';
    if (!customSalary) std::cout << "Salary: " << calculateSalary() << "$\n";
}