#pragma once
#include <iostream>
#include <limits>

const unsigned int BUFFER_SIZE = 256;

class UserInput {
public:

    static const char* String(const char* str = nullptr)
    {
        if (str) std::cout << str;

        char* buffer = new char[BUFFER_SIZE];

        std::cin.getline(buffer, BUFFER_SIZE);

        return buffer;
    }

    static unsigned int Uint(const char* str = nullptr)
    {
        unsigned int value;

        if (!(std::cin >> value)) value = 0;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return value;
    }
};