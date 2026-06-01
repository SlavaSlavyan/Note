#pragma once
#include "Employee.hpp"
#include <iostream>

// класс менеджера
class Manager : public Employee {

    // количество подчинённых
    unsigned int subordinatesCount;

public:

    Manager(const char* n, unsigned int i, unsigned int s, unsigned int sc) : Employee(n,i,s), subordinatesCount(sc) {}

    Manager() : Manager(nullptr, 0, 0, 0) {}

    Manager(const Manager& other) : Manager(other.name, other.id, other.salary, other.subordinatesCount) {}

    // +100 за каждого подчинённого
    unsigned int calculateSalary() const override {
        return salary + subordinatesCount * 100;
    }

    void getInfo(bool customSalary = true) const override
    {
        Employee::getInfo(customSalary);
        std::cout << "Subordinates: " << subordinatesCount << " people\n";
        if (customSalary) std::cout << "Salary: " << calculateSalary() << "$\n";
    }
};