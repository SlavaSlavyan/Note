#pragma once
#include "Employee.hpp"

class Department {

    Employee* employees = new Employee[0];
    unsigned int newID = 0, employeesCount = 0;

public:

    ~Department();

    bool add(const Employee*);

    bool remove(const Employee*);

    unsigned int total_salary() const;

    unsigned int max_salary() const;

    void print() const;
};