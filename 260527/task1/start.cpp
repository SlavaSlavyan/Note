#include <iostream>
#include <conio.h>
#include "include/Stack.hpp"

int main()
{
    Element<int>* stack = nullptr;

    for (int i = 0; i < 10; i++) {
        push(stack,i);
    }

    Element<int>* current = stack;

    while (current)
    {
        const int* value = peek<int>(current);
        std::cout << *value << " ";
        current = next_elem<int>(current);
    }

    return 0;
}