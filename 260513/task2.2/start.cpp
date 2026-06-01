#include <iostream>
#include <conio.h>
#include "include/Department.hpp"
#include "include/Employee.hpp"
#include "include/Developer.hpp"
#include "include/Intern.hpp"
#include "include/Manager.hpp"

int main()
{
    // создаём депортамент
    Department* dep = new Department();

    // создаём всех сотрудников
    dep->add(Employee("John",0,1200))
    .add(Developer("Dave",0,1200,2,"C++"))
    .add(Intern("Nay",0,1200,true))
    .add(Manager("Kail",0,1200,1))
    .sort() // сортируем сотрудников по зарглате
    .print(); // выводим всех

    delete dep;

    std::cout << "\nEND\n";

    _getch();

    return 0;
}