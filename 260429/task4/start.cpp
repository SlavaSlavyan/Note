#include <iostream>
#include <conio.h>
#include "include/BankAccount.hpp"

int main()
{
    // создаём экземпляр счёта
    BankAccount* acc = new BankAccount("Иван", 0, -10.0);

    // зачисляем 100
    acc->deposit(100);

    // списываем 50
    acc->withdraw(50);

    // списываем 500 (неудачно)
    acc->withdraw(500);

    // проверяем счёт
    std::cout << "acc->getBalance() >> " << acc->getBalance() << std::endl;

    // выводим информацию о счёте
    acc->printInfo();

    // удаляем счёт
    delete acc;

    _getch();

    return 0;
}