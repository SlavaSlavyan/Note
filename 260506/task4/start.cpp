#include <iostream>
#include <conio.h>
#include "include/PhoneBook.hpp"

int menu();

int main() 
{
    PhoneBook* contacts = new PhoneBook();

    while (true)
    {
        switch (menu())
        {
        case 0:
            system("cls");
            std::cout << "INVALID INPUT\n";
            _getch();
            break;

        case 1:
            system("cls");
            std::cout << "ALL CONTACTS:\n\n";
            contacts->printAll();
            _getch();
            break;

        case 2: {
            char* name = new char[0];
            system("cls");
            std::cout << "REQUEST << ";
            std::cin >> name;
            contacts->find(name);
            delete[] name;
            _getch();
            break;
        }
        case 4: {
            char *  n = new char[0],
                 * hp = new char[0],
                 * wp = new char[0],
                 *  i = new char[0];

            system("cls");
            std::cout << "NAME << ";
            std::cin >> n;
            std::cout << "HOME PHONE << ";
            std::cin >> hp;
            std::cout << "WORK PHONE << ";
            std::cin >> wp;
            std::cout << "INFO << ";
            std::cin >> i;
            contacts->add(n,hp,wp,i);
            delete[] n;
            delete[] hp;
            delete[] wp;
            delete[] i;
            system("cls");
            std::cout << "New contact was added.\n";
            _getch();
            break;
        }   
        case 5: {
            int id;
            system("cls");
            std::cout << "ID << ";
            std::cin >> id;
            contacts->remove(id);
            system("cls");
            std::cout << "Contact was deleted.\n";
            _getch();
            break;
        }    
        case 6:
            return 0;
        }
    }
}

int menu()
{
    system("cls");

    int enter;

    std::cout << "MAIN MENU:\n\n1.Show all contacts\n2.Find contact\n3.Show contact info\n4.Add contact\n5.Remove contact\n6.Exit\n\n>> ";
    std::cin >> enter;

    if (enter < 1 || enter > 6) {
        return 0;
    }

    return enter;
}