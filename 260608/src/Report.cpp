#include "../include/Report.hpp"
#include <cstring>
#include <iostream>

char* Report::SetString(const char* data)
{
    if (!data) {
        return nullptr;
    }

    char* string = new char[strlen(data) + 1];
    strcpy_s(string, strlen(data) + 1, data);

    return string;
}

Report::Report() : status(false), id(0), vetId(0), animalId(0), clientId(0), anamnesis(nullptr), diagnosis(nullptr), date(nullptr) {}

Report::Report(const Report& other) : status(other.status), id(other.id), vetId(other.vetId), animalId(other.animalId), clientId(other.clientId)
{
    SetAnamnesis(other.anamnesis);
    SetDiagnosis(other.diagnosis);
    SetDate(other.date);
}

void Report::Print(const char* data) const 
{
    if (!data) return;

    unsigned int count = 0;
    while (data[count] != '\0') {
        std::cout << data[count];
        count++;

        if (count % 50 == 0) {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

void Report::PrintAnamnesis() {
    Print(anamnesis);
}

void Report::PrintDiagnosis() {
    Print(diagnosis);
}