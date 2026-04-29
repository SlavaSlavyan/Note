#pragma once

// образец нашего класса
class Product{

public:

    // поля
    char* name;
    int quantity;
    double price;

    // конструктор
    Product(const char* name, int quantity, double price);

    // деструктор
    ~Product() { delete[] name; }

    // вывод информации
    void print();

    // вывод общей стоймости
    double getTotalCost() { return quantity * price; }
};