# Задача 1: «Товар на складе» (Основы: Класс вместо структуры)

### Условие:

В процедурном стиле для учёта товара использовалась структура и отдельные функции. Вам нужно переписать этот код, создав класс  Product.

### Исходные данные (процедурный стиль): 


``` cpp
#include <iostream>
#include <cstring>

struct product {
    char name[50]
    int quantity;
    double price;
};

// Функция для вывода информации о товаре
void printProduct(const Product& prod) {
    std::cout << "Товар: " << prod.name << std::endl;
    std::cout << "Количество на складе: " << prod.quantity << " шт." << std::endl;
    std::cout << "Цена за единицу: " << prod.price << " руб." << std::endl;
}

// Функция для расчёта общей стоимости товаров на складе
double calculateTotalCost(const Product& prod) {
    return prod.quantity * prod.price;
}
```

### Задание:

Создайте класс Product , который объединит данные о товаре (название, количество, цена) и методы для работы с ними.

1. Определите класс Product с публичными полями: char name[50], int quantity, double price.

2. Внутри класса реализуйте метод void print() для вывода информации о товаре (аналог функции printProduct).

3. Внутри класса реализуйте метод double getTotalCost() для расчета общей стоимости (аналог функции calculateTotalCost).

4. В функции main создайте объект класса, присвойте его полям значения (например, "Монитор", 15, 15000.0) и вызовите оба метода для проверки.

---

Точка входа [**start.cpp**](./start.cpp), включает в себя класс [**product.cpp**](./src/product.cpp) с заголовком [**product.hpp**](./include/product.hpp).