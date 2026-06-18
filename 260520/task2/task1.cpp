#include <iostream>
#include <string>
#include <conio.h>

int main()
{
    // инициализация переменной
    std::string name = "Slava";

    // вывод
    std::cout << "Hello, " << name
    << "!\nName length: " << name.length() // метод length
    << "\nFirst symbol: " << name.at(0) << "\n\nEND\n"; // метод at

    _getch();

    return 0;
}