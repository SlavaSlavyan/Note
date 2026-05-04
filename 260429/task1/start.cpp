#include <iostream>
#include <conio.h>
#include "include/product.hpp" // подключаем наш класс

int main()
{
    // создаём экземпляр класса
    Product* prod = new Product("Монитор",int(15),double(15000.0));

    // вызываем методы
    prod->print();
    std::cout << "prod->getTotalCost() >> " << prod->getTotalCost() << std::endl;

    // очищаем память
    delete prod;

    _getch();

    return 0;
}