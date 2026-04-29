#include "../include/BankAccount.hpp"
#include <iostream>
#include <cstring>

// реализация конструктора
BankAccount::BankAccount(const char* owner, int num, double initialBalance)
{
    // записываем имя владельца через strcpy_s
    this->owner = new char[strlen(owner) + 1];
    strcpy_s(this->owner, strlen(owner) + 1, owner);

    // записываем номер счёта
    this->accountNumber = num;
    
    // проверяем начальное значение баланса
    if (initialBalance < 0) {
        std::cout << "[ERROR] initialBalance can not be negative!\nBalance will equals 0.\n";
        initialBalance = 0.0;
    }
    
    // записываем начальный баланс
    this->balance = initialBalance;

    std::cout << "Account was created.\n";
}

// реализация депозита
void BankAccount::deposit(double amount)
{
    // проверяем входные данные
    if (amount < 0) {
        std::cout << "[ERROR] amount for deposit can not be negative!\n";
        return;
    }

    // зачисляем сумму
    this->balance += amount;

    std::cout << "Account was replenished\n";
}

// реализация снятия средств
bool BankAccount::withdraw(double amount)
{
    // проверяем входные данные
    if (amount < 0) {
        std::cout << "[ERROR] amount for withdraw can not be negative!\n";
        return false;
    }

    // проверяем количество средств
    if (amount > this->balance)
    {
        std::cout << "[ERROR] not enough funds!\n";
        return false;
    }

    // списываем средства
    this->balance -= amount;

    std::cout << "Funds were written off.\n";

    return true;
}

// реализация вывода информации о счёте
void BankAccount::printInfo()
{
    std::cout << "Owner: " << this->owner << std::endl;
    std::cout << "Account number: " << this->accountNumber << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
}