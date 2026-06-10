#include "../include/Report.hpp"
#include <cstring>

Report::Report() : id(0), animal(0), data(nullptr) {}

Report::Report(unsigned int i, char* d, unsigned int a) : Report()
{
    id = i;
    animal = a;

    if (d) {
        data = new char[strlen(d + 1)];
        strcpy_s(data, strlen(d + 1), d);
    }
}

Report::Report(const Report& other) : Report(other.id, other.data, other.animal) {}

Report::~Report()
{
    if (data) delete[] data;
    data = nullptr;
}