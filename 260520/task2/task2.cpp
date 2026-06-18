#include <iostream>
#include <string>
#include <conio.h>

int main()
{
    // инициализация переменной
    std::string name, greeting;

    // ввод
    std::cout << "Name << ";
    std::getline(std::cin, name);

    // проверка оператора +
    greeting = "Good day " + name + "!\n\nEND\n";

    // вывод
    std::cout << greeting;

    _getch();

    return 0;
}