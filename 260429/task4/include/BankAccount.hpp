#pragma once
#include <iostream>

// класс
class BankAccount {

    // поля
    char* owner;
    int accountNumber;
    double balance;

public:

    // конструктор
    BankAccount(const char* owner, int num, double initialBalance);

    // деструктор
    ~BankAccount() {
        delete[] owner;
        std::cout << "Account was deleted\n";
    }

    // метод депозита
    void deposit(double amount);

    // метод снятия средств
    bool withdraw(double amount);

    // метод получения баланса
    double getBalance() { return balance; }

    // вывод информации
    void printInfo();
};