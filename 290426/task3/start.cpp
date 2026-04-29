#include <iostream>
#include <conio.h>
#include "include/webLink.hpp" // подключаем наш класс

int main()
{
    // создаём экземпляр класса
    WebLink mySite("https://academy.top", "Сайт Компьютерной Академии");

    // вызываем методы
    mySite.print(); 

    _getch();
    
    return 0;
}