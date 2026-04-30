#include <iostream>
#include <conio.h>
#include "include/Rectangle.hpp"

int main()
{
    // создаём два экземпляра прямоугольников
    Rectangle *rect1 = new Rectangle(5.0, 3.0),
              *rect2 = new Rectangle(4.0, 4.0);

    // выводим их информацию
    rect1->printInfo();
    rect2->printInfo();

    // очищаем память
    delete rect1, rect2;

    _getch();

    return 0;
}