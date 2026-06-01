#include <iostream>
#include "include/SmartArray.hpp"

int main() {
    // Работа с целыми числами
    SmartArray<int> intArray(10);
    
    for (int i = 1; i <= 10; i++) {
        intArray.push_back(i * 10);
    }
        
    std::cout << "Size: " << intArray.Size() << std::endl;

    // Поиск элемента
    int index = intArray.find(50);
    if (index !=-1) {
        std::cout << "Found 50 at index: " << index << std::endl;
    }

    // Работа со строками
    SmartArray<std::string> strArray(3);
    strArray.push_back("Hello");
    strArray.push_back("World");
    strArray.push_back("C++");

    return 0;
}