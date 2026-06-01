#pragma once
#include "Employee.hpp"
#include <iostream>

// класс интерна
class Intern : public Employee {
    
    // поле наличия наставника
    bool haveMentor;

public:

    Intern(const char* n, unsigned int i, unsigned int s, bool hm) : Employee(n,i,s), haveMentor(hm) {}

    Intern() : Intern(nullptr, 0, 0, false) {}

    Intern(const Intern& other) : Intern(other.name, other.id, other.salary, other.haveMentor) {}

    // от общей зарплаты интерн получает 70%
    unsigned int calculateSalary() const override {
        return salary * 0.7f;
    }

    void getInfo(bool customSalary = true) const override
    {
        Employee::getInfo(customSalary);
        if (haveMentor) std::cout << "Have mentor: YES\n";
        else std::cout << "Have mentor: NO\n"; 
        if (customSalary) std::cout << "Salary: " << calculateSalary() << "$\n";
    }
};