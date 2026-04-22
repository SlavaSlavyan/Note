#include <iostream>
#include <string>

class Product {

    std::string Name;
    unsigned int Price, Quantity;

public:

    Product(std::string name, unsigned int price, unsigned int q)
    {
        this->Name = name;
        this->Price = price;
        this->Quantity = q;
    }

    unsigned int GetTotalValue() {
        return this->Price * this->Quantity;
    }

    bool Sell(unsigned int amount) 
    {
        if (amount > this->Quantity) {
            return false;
        }
        
        this->Quantity -= amount;
        
        return true;
    }
};

int main()
{
    std::string Name;
    unsigned int Price, Quantity;

    std::cout << "Product name << ";
    std::getline(std::cin, Name);
    std::cout << "Price << ";
    std::cin >> Price;
    std::cout << "Quantity << ";
    std::cin >> Quantity;

    Product* prod = new Product(Name, Price, Quantity);

    std::cout << prod->GetTotalValue() << std::endl;
    std::cout << prod->Sell(1) << std::endl;
    std::cout << prod->GetTotalValue() << std::endl;

    return 0;
}