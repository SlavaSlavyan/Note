#pragma once
#include "Employee.hpp"
#include "Manager.hpp"
#include "Developer.hpp"
#include "Intern.hpp"

class Department {

    Employee** employees = new Employee*[0];
    unsigned int count = 0, newID = 0;

public:

    void add(const Employee* newEmployee);

};