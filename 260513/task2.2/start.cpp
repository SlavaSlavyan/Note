#include <iostream>
#include "include/Developer.hpp"
#include "include/Intern.hpp"
#include "include/Manager.hpp"
#include "include/Employee.hpp"
#include "include/Department.hpp"

int main()
{
    Department* dep = new Department();

    dep->add(new Manager());
    
    return 0;
}