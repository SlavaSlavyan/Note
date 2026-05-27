#pragma once
#include "Employee.hpp"
#include <iostream>
#include <cstring>

class Developer : public Employee {

    char* programmingLanguage;
    unsigned int experience;

public:

    Developer(const char* n, unsigned int i, unsigned int s, unsigned int ex, const char* pl) : Employee(n,i,s), experience(ex),
    programmingLanguage(pl ? new char[strlen(pl) + 1] : nullptr) 
    {
        if (programmingLanguage) strcpy_s(programmingLanguage, strlen(pl) + 1, pl);
    }

    Developer() : Developer(nullptr, 0, 0, 0, nullptr) {}

    Developer(const Developer& other) : Developer(other.name, other.id, other.salary, other.experience, other.programmingLanguage) {}

    ~Developer() {
        Employee::~Employee();
        delete[] programmingLanguage;
    }

    unsigned int calculateSalary() const override {
        return salary + experience * 5000;
    }

    void getInfo(bool customSalary = true) const override 
    {
        Employee::getInfo(customSalary);
        std::cout << "Experience: " << experience << " years\nProgramming language: ";
        if (programmingLanguage) std::cout << programmingLanguage << '\n';
        else std::cout << "NULL" << '\n';
        if (customSalary) std::cout << "Salary: " << calculateSalary() << "$\n";
    }
};