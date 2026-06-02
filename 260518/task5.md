# Задание 5. Что такое перегрузка методов

Перегрузка методов это возможность создавать несколько функций с одним именем, но с разными аргументами. ВСЁ Я ХЗ ЧЁ ТУТ РАСПИСЫВАТЬ.

Разве что можно сказать ещё что перегрузка это всегда по одно имя но разные аргументы и есть она не только у методов.

```cpp
#include <iostream>
#include <string>

class Printer {
public:
    // 1. Метод для вывода целого числа
    void print(int value) {
        std::cout << "Integer: " << value << std::endl;
    }

    // 2. Метод для вывода числа с плавающей точкой (отличается типом параметра)
    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }

    // 3. Метод для вывода строки
    void print(const std::string& value) {
        std::cout << "String: " << value << std::endl;
    }

    // 4. Метод с двумя параметрами (отличается количеством параметров)
    void print(int value, int count) {
        for (int i = 0; i < count; i++) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Printer myPrinter;

    myPrinter.print(5);           // Вызовет метод №1 (int)
    myPrinter.print(3.14);        // Вызовет метод №2 (double)
    myPrinter.print("Hello!");    // Вызовет метод №3 (string)
    myPrinter.print(7, 3);        // Вызовет метод №4 (int, int)

    return 0;
}
```