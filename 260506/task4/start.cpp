#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <limits> // для очистки cin
#include "include/PhoneBook.hpp"

// оч много инициализации :P
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
    // создаём нашу книгу контактов
    PhoneBook* contacts = new PhoneBook();

    // основной цикл программы
    while (true) 
    {
        // menu получает ввод от пользователя и выполняет соответствубющие действия
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
        
        // выход из программы
        case 6:
            delete contacts;
            return 0;

        // неверный ввод
        default:
            wrongInput();
            break;
        }
    }
}

// функция для ввода int
int inputInt()
{
    int num;

    if (std::cin >> num) {
        return num;
    }

    // очищаем cin в случае плохого ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ноль нигде не используется, так что он считается неверным вводом
    return 0;
}

// функция для ввода строки
char* inputStr()
{
    // создаём буффер для строки
    char* buffer = new char[256];

    // записываем через getline
    std::cin.getline(buffer, 256);

    return buffer;
}

// выбор действий
int menu()
{
    system("cls");

    std::cout << "MAIN MENU:\n\n1.Show all contacts\n2.Find contact\n3.Show contact info\n4.Add contact\n5.Remove contact\n6.Exit\n\n>> ";

    return inputInt();
}

// поиск контактов
void find(PhoneBook* contacts)
{
    system("cls");

    // очищаем cin перед вводом
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "REQUEST << ";
    char* input = inputStr();

    std::cout << '\n';

    // вызов функции из класса книги
    contacts->find(input);

    delete[] input;

    _getch();
}

// показать все контакты
void showAll(PhoneBook* contacts)
{
    system("cls");

    std::cout << "ALL CONTACTS:\n\n";

    // вызов функции из класса книги
    contacts->printAll();

    _getch();
}

// добавление контакта
void add(PhoneBook* contacts)
{
    system("cls");

    // очищаем cin перед вводом
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // заполняем каждую строчку контакта
    std::cout << "NAME << ";
    char* n = inputStr();
    std::cout << "HOME PHONE << ";
    char* hp = inputStr();
    std::cout << "WORK PHONE << ";
    char* wp = inputStr();
    std::cout << "INFO << ";
    char* i = inputStr();

    system("cls");

    // вызов функции из класса книги
    contacts->add(n,hp,wp,i);

    delete[] n;
    delete[] hp;
    delete[] wp;
    delete[] i;

    std::cout << "New contact added.\n";

    _getch();
}

// удаление контакта
void remove(PhoneBook* contacts)
{
    system("cls");

    // вызов функции из класса книги для отображения всех контактов
    contacts->printAll();

    std::cout << "\nDELETE ID << ";

    int input = inputInt();
    
    if (input != 0) {
        // вызов функции из класса книги для удаления контакта
        if (contacts->remove(input - 1)) 
        {
            system("cls");
            std::cout << "Contact was deleted";
            _getch();

            return;
        }
    }

    // если удалить не получилось то пишем что неправильный ввод
    wrongInput();
}

// пишем Ащибку
void wrongInput()
{
    system("cls");

    std::cout << "INVALID INPUT\n";

    _getch();
}