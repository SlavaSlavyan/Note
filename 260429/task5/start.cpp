#include <iostream>
#include <conio.h>
#include "include\Thermometer.hpp"

int main()
{
    // создаём 3 термометра
    Thermometer *t1 = new Thermometer(), 
                *t2 = new Thermometer(20),
                *t3 = new Thermometer("Home", 16);

    // выводим информацию для каждого
    t1->printInfo();
    t2->printInfo();
    t3->printInfo();

    // показываем 2 метода
    std::cout << "\nt1->getCelsius() >> " << t1->getCelsius() << std::endl;
    std::cout << "t2->getFahrenheit() >> " << t2->getFahrenheit() << std::endl;

    // очищаем память
    delete t1, t2, t3;
    
    _getch();
    
    return 0;
}