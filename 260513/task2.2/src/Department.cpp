#include <type_traits>
#include <iostream>
#include "../include/Department.hpp"
#include "../include/Employee.hpp"
#include "../include/Manager.hpp"
#include "../include/Developer.hpp"
#include "../include/Intern.hpp"

void Department::add(const Employee* newEmployee)
{
    Employee** oldData = new Employee*[count];

    for (int i = 0; i < count; i++) 
    {
        if (std::is_same_v<decltype(employees[i]), Employee*>) oldData[i] = new Employee(*employees[i]);
    }
}