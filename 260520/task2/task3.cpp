#include <iostream>
#include <string>
#include <conio.h>

int main()
{
    // инициализация переменной
    std::string str = "C++ — is strong programming language. Class string is very convenient.";

    // ищем заданное имя
    size_t found = str.find("string");

    // если строка не найдена то выбрасываем исключение
    if (found == std::string::npos) {
        std::cout << "Word not found.";
    }
    else {
        std::cout << "The word 'string' was found at position " << found;
    }

    std::cout << "\n\nEND\n";

    _getch();

    return 0;
}