#include <iostream>
#include <conio.h>
#include "include/PhoneBook.hpp"

void mainMenu(int* status);
void allContacts(int* status, PhoneBook* contacts);

int main()
{
    PhoneBook* contacts = new PhoneBook();

    int status = 0;

    while (true) 
    {
        switch (status)
        {
        case 0:
            mainMenu(&status);
            break;
        case 1:
            allContacts(&status, contacts);
            break;
        }

        if (status == 5) {
            break;
        }
    }

    delete contacts;

    return 0;
}

void mainMenu(int* status) 
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << "MAIN MENU:\n\n1.Show all contacts\n" <<
    "2.Find contact\n3.Add contact\n4.Delete Contact\n5.Exit\n\n>> ";

    std::cin >> *status;

    if (*status < 0 || *status > 5) {
        *status = 0;
        std::cout << "\033[2J\033[1;1H" << "INVALID INPUT\n";
        _getch();
    }
}

void allContacts(int* status, PhoneBook* contacts)
{
    contacts->printAll();
    _getch();
    *status = 0;
}

void findContact(int* status, PhoneBook* contacts)
{
    
}