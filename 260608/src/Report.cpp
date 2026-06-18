#include "../include/Report.hpp"
#include <cstring>
#include <iostream>

void Report::SetDate(const char* newDate)
{
    if (newDate) {
        date = new char[strlen(newDate) + 1];
        strcpy_s(date, strlen(newDate) + 1, newDate);
    }

    else date = nullptr;
}

void Report::SetInfo(const char* newInfo)
{
    if (newInfo) {
        info = new char[strlen(newInfo) + 1];
        strcpy_s(info, strlen(newInfo) + 1, newInfo);
    }

    else info = nullptr;
}

Report::Report() : id(0), animal(0), date(nullptr), info(nullptr) {}

Report::Report(const Report& other) : Report()
{
    id = other.id;
    animal = other.animal;

    SetDate(other.date);
    SetInfo(other.info);
}

Report::~Report()
{
    if (date) delete[] date;
    if (info) delete[] info;
}

void Report::Print()
{
    std::cout << "--------------------------------------------------\n\n  Report number: " << id << "\n\n  ";
    if (info) 
    {
        unsigned int length = strlen(info);
        int part_size = 50;
        
        for (int i = 0; i < length; i += part_size) {

            for (int j = 0; j < part_size && i + j < length; ++j) {
                std::cout << info[i + j];
            }
            std::cout << "\n  "; 
        }
    }
    else std::cout << "  NO INFO FOUND\n";
    
    if (date) std::cout << "\n  [" << date;
    else std::cout << "\n  [NO DATE";

    std::cout << "]\n\n--------------------------------------------------\n";
}