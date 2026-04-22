#include <iostream>
#include <string>

class BankAccount {

    long unsigned int accountNumber;
    long int balance;
    std::string ownerName;

public:

    BankAccount(long unsigned int n, std::string name, long int balance = 0)
    {
        this->accountNumber = n;
        this->balance = balance;
        this->ownerName = name;
    }

    long unsigned int getID() const {
        return this->accountNumber;
    }

    long int getBalance() const {
        return this->balance;
    }

    std::string getOwner() const {
        return this->ownerName;
    }

    std::string setNewOwner(std::string name){
        return this->ownerName = name;
    }

    void Deposit(long int amount)
    {
        if (amount < 0) {
            std::cout << "[ERROR] Пополнение счёта должно быть на положительное значение!" << std::endl;
            return;
        }

        std::cout << "Счёт пополнен." << std::endl;

        this->balance += amount;
    }

    void Withdraw(long int amount)
    {
        if (amount > balance){
            std::cout << "[ERROR] Недостаточно средств на счёте!" << std::endl;
            return;
        }

        std::cout << "Сумма списана." << std::endl;

        this->balance -= amount;
    }

    void DisplayInfo() const {
        std::cout << "ID: " << this->accountNumber << "\nOwner: " << this->ownerName << "\nBalance: " << this->balance << std::endl;
    }
};

int main()
{
    long unsigned int id;
    long int balance;
    std::string owner;

    std::cout << "Owner << ";
    std::getline(std::cin, owner);
    std::cout << "ID << ";
    std::cin >> id;

    BankAccount* acc = new BankAccount(id, owner);

    acc->Deposit(-300);
    acc->Deposit(300);
    acc->Withdraw(500);
    acc->Withdraw(150);
    acc->DisplayInfo();

    return 0;
}