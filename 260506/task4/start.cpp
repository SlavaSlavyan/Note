#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "include/PhoneBook.hpp"


int inputInt();
char* inputStr();
int menu();
void showAll(PhoneBook* contacts);
void find(PhoneBook* contacts);
void add(PhoneBook* contacts);
void remove(PhoneBook* contacts);
void wrongInput();

int main()
{
    PhoneBook* contacts = new PhoneBook();

    while (true) 
    {
        switch (menu())
        {
        case 1:
            showAll(contacts);
            break;

        case 2:
            find(contacts);
            break;

        case 4:
            add(contacts);
            break;

        case 5:
            remove(contacts);
            break;
            
        case 6:
            return 0;

        default:
            wrongInput();
            break;
        }
    }
}

int inputInt()
{
    char* raw = new char[1];

    std::cin >> raw;

    int result = std::atoi(raw);

    delete[] raw;

    return result;
}

char* inputStr()
{
    char* str = new char[1];

    std::cin >> str;

    return str;
}

int menu()
{
    system("cls");

    std::cout << "MAIN MENU:\n\n1.Show all contacts\n2.Find contact\n3.Show contact info\n4.Add contact\n5.Remove contact\n6.Exit\n\n>> ";

    return inputInt();
}

void find(PhoneBook* contacts)
{
    system("cls");

    std::cout << "REQUEST << ";
    char* input = inputStr();

    std::cout << '\n';

    contacts->find(input);

    delete[] input;

    _getch();
}

void showAll(PhoneBook* contacts)
{
    system("cls");

    std::cout << "ALL CONTACTS:\n\n";

    contacts->printAll();

    _getch();
}

void add(PhoneBook* contacts)
{
    system("cls");

    std::cout << "NAME << ";
    char* n = inputStr();
    std::cout << "HOME PHONE << ";
    char* hp = inputStr();
    std::cout << "WORK PHONE << ";
    char* wp = inputStr();
    std::cout << "INFO << ";
    char* i = inputStr();

    system("cls");

    contacts->add(n,hp,wp,i);

    delete[] n;
    delete[] hp;
    delete[] wp;
    delete[] i;

    std::cout << "New contact added.\n";

    _getch();
}

void remove(PhoneBook* contacts)
{
    system("cls");

    contacts->printAll();

    std::cout << "\nDELETE ID << ";

    int input = inputInt();
    
    if (input != 0) {
        if (contacts->remove(input - 1)) 
        {
            system("cls");
            std::cout << "Contact was deleted";
            _getch();

            return;
        }
    }

    wrongInput();
}

void wrongInput()
{
    system("cls");

    std::cout << "INVALID INPUT\n";

    _getch();
}