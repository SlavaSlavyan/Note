#include <iostream>
#include <conio.h>
#include "include/Human.hpp"
#include "include/Date.hpp"

int main()
{
    // создаём дату и двух людей.
    Date* d1 = new Date(7,10,2026);
    Human * h1 = new Human(1,"Ivan", "Ivanovich", "Ivanov", d1),
          * h2 = new Human(); // параметры по умолчанию

    // выводим информацию
    h1->info();
    h2->info();

    // показываю что счётчик меняется при очистке памяти

    std::cout << "\nHuman::getCount() >> " << Human::getCount() << std::endl;

    delete h1,
    delete h2;

    std::cout << "\nHuman::getCount() >> " << Human::getCount() << std::endl;
    
    _getch();

    return 0;
}