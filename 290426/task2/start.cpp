#include <iostream>
#include <conio.h>
#include "include/lightBulb.hpp" // подключаем наш класс

int main()
{
    // создаём экземпляр класса
    LightBulb* light = new LightBulb();

    // вызываем все методы

    // включаем
    light->turnOn();
    std::cout << light->getState() << std::endl;

    // выключаем
    light->turnOff();
    std::cout << light->getState() << std::endl;

    // переключаем
    light->toggle();
    std::cout << light->getState() << std::endl;

    // очищаем память
    delete light;

    _getch();

    return 0;
}