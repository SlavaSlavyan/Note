#include <iostream>
#include "include/Lesson.hpp"
#include "include/Schedule.hpp"
#include <conio.h>
#include <limits>

int main()
{
    Schedule* dataBase = new Schedule();

    while (true)
    {
        std::system("cls");

        int userInput;

        std::cout << "1. Add lesson\n2. Remove lesson\n3. Find lesson\n4.Print all lessons\n\n0. Exit\n\n>> ";

        // исключение при ошибке ввода
        if (!(std::cin >> userInput)) 
        {
            std::system("cls");
            std::cout << "Invalid input!\n\n";

            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            _getch();
            continue;
        }
        
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userInput)
        {
        case 0:
            delete dataBase;
            return 0;
        
        case 1:
            dataBase->Add();
            break;
        case 2:
            dataBase->Remove();
            break;
        case 3:
            dataBase->Find();
            break;
        case 4:
            dataBase->Print();
            break;
        
        default:
            std::system("cls");
            std::cout << "Invalid input!\n\n";
            _getch();
            break;
        }
    }
}