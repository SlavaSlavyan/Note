#include <iostream>
#include <typeinfo>
#include "include/Employee.hpp"

int main() 
{
    Employee* test = new Employee();
    std::cout << typeid(test).name() << std::endl; // Выведет "i" (для int)
    return 0;
}