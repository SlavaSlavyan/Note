#include "../include/product.hpp" // берём наш "образ" класса
#include <iostream>
#include <cstring>

using namespace std;

// реализуем конструктор
Product::Product(const char* name, int quantity, double price) 
{
    // выделяем память под название
    this->name = new char[strlen(name)+1];
    // копируем инфу
    strcpy_s(this->name, strlen(name) + 1, name);

    // ну и остальные переменные
    this->quantity = quantity;
    this->price = price;
}

// реализуем вывод информации
void Product::print() {
    std::cout << "Товар: " << this->name << std::endl;
    std::cout << "Количество на складе: " << this->quantity << " шт." << std::endl;
    std::cout << "Цена за единицу: " << this->price << " руб." << std::endl;
}